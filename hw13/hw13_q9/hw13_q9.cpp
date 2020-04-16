#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Board {
    char board[20][20];
public:
    Board() {
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 20; x++) {
                board[y][x] = '-';
            }
        }
    }

//    void printBoard() {
//        for (int i = 0; i < 20; i++) {
//            cout << "  " << i;
//        }
//        cout << endl;
//        for (int y = 0; y < 20; y++) {
//            cout << y;
//            for (int x = 0; x < 20; x++) {
//                cout << " " << board[y][x] << " ";
//            }
//            cout << endl;
//        }
//    }

//    void updateBoard(vector<Ant> ants) {
//        int i, x, y;
//        for (i = 0; i < 10; i++) {
//            x = ants[i].getXCoord();
//            y = ants[i].getYCoord();
//            board[y][x] = 'o';
//        }
//    }

//    bool isCellAvailable(int x_coord, int y_coord) {
//        if (this->getCellStatus(x_coord, y_coord) == '-') {
//            return true;
//        }
//        return false;
//    }

//    char getCellStatus(int x_coord, int y_coord) {
//        return board[y_coord][x_coord];
//    }
};

class Organism {
    int x, y;
public:
    Organism(int x_coord, int y_coord) {
        x = x_coord;
        y = y_coord;
    }
    virtual void move(vector<int> position_coords) {};
    int getXCoord() { return x; }
    int getYCoord() { return y; }
    void setXCoord(int x_coord) { x = x_coord; }
    void setYCoord(int y_coord) { y = y_coord; }
};

class Ant :public Organism {
public:
    Ant(int x_coord, int y_coord) :Organism(x_coord, y_coord) {}

    void move(vector<int> position_coords) override {
        this->setXCoord(position_coords[0]);
        this->setYCoord(position_coords[1]);
        Organism::move(position_coords);
    }
};

bool isCellAvailable(char board[][20], int x_coord, int y_coord) {
    if ((x_coord > 19) || (x_coord < 0) || (y_coord > 19) || (y_coord < 0)) {
        return false;
    }

    if (board[y_coord][x_coord] == '-') {
        return true;
    }
    return false;
}

void printBoard(char board[][20]) {
    for (int i = 0; i < 20; i++) {
        cout << "  " << i;
    }
    cout << endl;
    for (int y = 0; y < 20; y++) {
        cout << y;
        for (int x = 0; x < 20; x++) {
            cout << " " << board[y][x] << " ";
        }
        cout << endl;
    }
}

void updateBoard(char board[][20], vector<Ant> ants) {
    int i, x, y;
    for (i = 0; i < 10; i++) {
        x = ants[i].getXCoord();
        y = ants[i].getYCoord();
        board[y][x] = 'o';
    }
}

vector<int> checkPositions(char board_array[][20], Ant ant) {
    int x, y;
    int top_x, top_y;
    int bottom_x, bottom_y;
    int left_x, left_y;
    int right_x, right_y;
    vector<int> top_coord;
    vector<int> bottom_coord;
    vector<int> left_coord;
    vector<int> right_coord;
    vector< vector<int> > position_vector;

    x = ant.getXCoord();
    y = ant.getYCoord();
    top_x = x;
    top_y = y - 1;
    bottom_x = x;
    bottom_y = y + 1;
    left_x = x - 1;
    left_y = y;
    right_x = x + 1;
    right_y = y;
    if (isCellAvailable(board_array, top_x, top_y)) {
        top_coord.push_back(top_x);
        top_coord.push_back(top_y);
        position_vector.push_back(top_coord);
    }
    if (isCellAvailable(board_array, bottom_x, bottom_y)) {
        bottom_coord.push_back(bottom_x);
        bottom_coord.push_back(bottom_y);
        position_vector.push_back(bottom_coord);
    }
    if (isCellAvailable(board_array, left_x, left_y)) {
        left_coord.push_back(left_x);
        left_coord.push_back(left_y);
        position_vector.push_back(left_coord);
    }
    if (isCellAvailable(board_array, right_x, right_y)) {
        right_coord.push_back(right_x);
        right_coord.push_back(right_y);
        position_vector.push_back(right_coord);
    }

    int position = rand() % position_vector.size();
    return position_vector[position];
}

int main() {
    srand(time(nullptr));

    char board_array[20][20];
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            board_array[y][x] = '-';
        }
    }

    int x_ant, y_ant;
    vector<Ant> ant_vector;
    for (int i = 0; i < 10; i++) {
        x_ant = rand() % 20;
        y_ant = rand() % 20;
        Ant ant(x_ant, y_ant);
        ant_vector.push_back(ant);
    }

    updateBoard(board_array, ant_vector);
    printBoard(board_array);

    vector<int> newPosition;
    for (int i = 0; i < ant_vector.size(); i++) {
        newPosition = checkPositions(board_array, ant_vector[i]);
        ant_vector[i].move(newPosition);
    }

    updateBoard(board_array, ant_vector);
    printBoard(board_array);

    return 0;
}
