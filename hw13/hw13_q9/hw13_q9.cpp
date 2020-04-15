#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Board;

class Organism {
    int x, y;
public:
    Organism(int x_coord, int y_coord) {
        x = x_coord;
        y = y_coord;
    }
    virtual void move() const = 0;
    int getXCoord() { return x; }
    int getYCoord() { return y; }

};

class Ant :public Organism {
public:
    Ant(int x_coord, int y_coord) :Organism(x_coord, y_coord) {}
    void move() {

    }
};

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

    void printBoard() {
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

    void updateBoard(vector<Ant> ants) {
        int i, x, y;
        for (i = 0; i < 10; i++) {
            x = ants[i].getXCoord();
            y = ants[i].getYCoord();
            board[y][x] = 'o';
        }
    }

    bool isCellAvailable(int x_coord, int y_coord) {
        if (this->getCellStatus(x_coord, y_coord) == '-') {
            return true;
        }
        return false;
    }

    char getCellStatus(int x_coord, int y_coord) {
        return board[y_coord][x_coord];
    }
};

int main() {
    srand(time(nullptr));

    Board board;

    int x_ant, y_ant;
    vector<Ant> ant_vector;
    for (int i = 0; i < 10; i++) {
        x_ant = rand() % 20;
        y_ant = rand() % 20;
        Ant ant(x_ant, y_ant);
        ant_vector.push_back(ant);
    }

    board.updateBoard(ant_vector);
    board.printBoard();

    int x, y;
    int top_x, top_y;
    int bottom_x, bottom_y;
    int left_x, left_y;
    int right_x, right_y;
    for (int i = 0; i < ant_vector.size(); i++) {
        x = ant_vector[i].getXCoord();
        y = ant_vector[i].getYCoord();
        top_x = x;
        top_y = y - 1;
        bottom_x = x;
        bottom_y = y + 1;
        left_x = x - 1;
        left_y = y;
        right_x = x + 1;
        right_y = y;
        if (!board.isCellAvailable(top_x, top_y)) {
            cout << "ant " << i << ": " << ant_vector[i].getXCoord() << ", " << ant_vector[i].getYCoord() << endl;
            cout << "top: " << top_x << ", " << top_y << endl;
        } else if (!board.isCellAvailable(bottom_x, bottom_y)) {
            cout << "ant " << i << ": " << ant_vector[i].getXCoord() << ", " << ant_vector[i].getYCoord() << endl;
            cout << "bottom: " << bottom_x << ", " << bottom_y << endl;
        } else if (!board.isCellAvailable(left_x, left_y)) {
            cout << "ant " << i << ": " << ant_vector[i].getXCoord() << ", " << ant_vector[i].getYCoord() << endl;
            cout << "left: " << left_x << ", " << left_y << endl;
        } else if (!board.isCellAvailable(right_x, right_y)) {
            cout << "ant " << i << ": " << ant_vector[i].getXCoord() << ", " << ant_vector[i].getYCoord() << endl;
            cout << "right: " << right_x << ", " << right_y << endl;
        }
    }

    return 0;
}
