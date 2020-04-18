// Name: Lawrence Hon
// NetID: lh3024

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Ant;
bool isCellAvailable(char board[][20], int x_coord, int y_coord);
bool isCellAvailableDoodlebug(char board[][20], vector<Ant> &ant_vector, int x_coord, int y_coord);
bool isAnt(char board[][20], int x_coord, int y_coord);

class Organism {
    int x, y;
public:
    Organism(int x_coord, int y_coord) {
        x = x_coord;
        y = y_coord;
    }
    virtual void move(const char board_array[][20]) {};
    int getXCoord() { return x; }
    int getYCoord() { return y; }
    void setXCoord(int x_coord) { x = x_coord; }
    void setYCoord(int y_coord) { y = y_coord; }
};

class Ant :public Organism {
public:
    Ant(int x_coord, int y_coord) :Organism(x_coord, y_coord) {}
    ~Ant() {}

    void move(char board_array[][20]) {
        int x, y;
        int top_x, top_y;
        int bottom_x, bottom_y;
        int left_x, left_y;
        int right_x, right_y;
        vector<int> top_coord;
        vector<int> bottom_coord;
        vector<int> left_coord;
        vector<int> right_coord;
        vector<vector<int> > position_vector;

        x = this->getXCoord();
        y = this->getYCoord();
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

        this->setXCoord(position_vector[position][0]);
        this->setYCoord(position_vector[position][1]);
        Organism::move(board_array);
    }
};

class Doodlebug :public Organism {
public:
    Doodlebug(int x_coord, int y_coord) :Organism(x_coord, y_coord) {}
    ~Doodlebug() {}

    void move(char board_array[][20], vector<Ant> &ant_vector) {
        int x, y;
        int top_x, top_y;
        int bottom_x, bottom_y;
        int left_x, left_y;
        int right_x, right_y;
        vector<int> top_coord;
        vector<int> bottom_coord;
        vector<int> left_coord;
        vector<int> right_coord;
        vector<vector<int> > position_vector;

        x = this->getXCoord();
        y = this->getYCoord();
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
        } else if (isAnt(board_array, top_x, top_y)) {
            eat(board_array, ant_vector, top_x, top_y);
        }

        if (isCellAvailable(board_array, bottom_x, bottom_y)) {
            bottom_coord.push_back(bottom_x);
            bottom_coord.push_back(bottom_y);
            position_vector.push_back(bottom_coord);
        } else if (isAnt(board_array, bottom_x, bottom_y)) {
            eat(board_array, ant_vector, bottom_x, bottom_y);
        }

        if (isCellAvailable(board_array, left_x, left_y)) {
            left_coord.push_back(left_x);
            left_coord.push_back(left_y);
            position_vector.push_back(left_coord);
        } else if (isAnt(board_array, left_x, left_y)) {
            eat(board_array, ant_vector, left_x, left_y);
        }

        if (isCellAvailable(board_array, right_x, right_y)) {
            right_coord.push_back(right_x);
            right_coord.push_back(right_y);
            position_vector.push_back(right_coord);
        } else if (isAnt(board_array, right_x, right_y)) {
            eat(board_array, ant_vector, right_x, right_y);
        }

        int position = rand() % position_vector.size();

        this->setXCoord(position_vector[position][0]);
        this->setYCoord(position_vector[position][1]);
        Organism::move(board_array);
    }

    void eat(char board[][20], vector<Ant> &ant_vector, int x_coord, int y_coord) {
        if (board[y_coord][x_coord] == 'o') {
            int x, y;
            for(int i = 0; i < ant_vector.size(); i++) {
                x = ant_vector[i].getXCoord();
                y = ant_vector[i].getYCoord();
                if ((x_coord == x) && (y_coord == y)) {
                    ant_vector.erase(ant_vector.begin() + i);
                }
            }
        }
    }
};

bool isCellAvailableDoodlebug(char board[][20], vector<Ant> &ant_vector, int x_coord, int y_coord) {
    if ((x_coord > 19) || (x_coord < 0) || (y_coord > 19) || (y_coord < 0)) {
        return false;
    }

    if (board[y_coord][x_coord] == 'X') {
// loop through ant_vector and see which ant is there
        int x, y;
        for(int i = 0; i < ant_vector.size(); i++) {
            x = ant_vector[i].getXCoord();
            y = ant_vector[i].getYCoord();
            if ((x_coord == x) && (y_coord == y)) {
                ant_vector.erase(ant_vector.begin() + i);
            }
        }
        return true;
    }
    return false;
}

bool isAnt(char board[][20], int x_coord, int y_coord) {
    if (board[y_coord][x_coord] == 'o') {
        return true;
    }
    return false;
}

bool isCellAvailable(char board[][20], int x_coord, int y_coord) {
    if ((x_coord > 19) || (x_coord < 0) || (y_coord > 19) || (y_coord < 0)) {
        return false;
    }

    if (board[y_coord][x_coord] == '-') {
        return true;
    }
    return false;
}

void initializeBoard(char board[][20], vector<Ant> &ant_vector, vector<Doodlebug> &doodlebug_vector) {
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            board[y][x] = '-';
        }
    }

    int x_ant, y_ant;
    for (int i = 0; i < 100; i++) {
        x_ant = rand() % 20;
        y_ant = rand() % 20;
        Ant ant(x_ant, y_ant);
        ant_vector.push_back(ant);
    }

    int x_doodlebug, y_doodlebug;
    for (int i = 0; i < 5; i++) {
        x_doodlebug = rand() % 20;
        y_doodlebug = rand() % 20;
        Doodlebug doodlebug(x_doodlebug, y_doodlebug);
        doodlebug_vector.push_back(doodlebug);
    }
}

void printBoard(char board[][20]) {
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            cout << " " << board[y][x] << " ";
        }
        cout << endl;
    }
}

void updateBoard(char board[][20], vector<Ant> ants, vector<Doodlebug> doodlebug) {
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            board[y][x] = '-';
        }
    }

    int i, x, y;
    for (i = 0; i < ants.size(); i++) {
        x = ants[i].getXCoord();
        y = ants[i].getYCoord();
        board[y][x] = 'o';
    }

    for (i = 0; i < doodlebug.size(); i++) {
        x = doodlebug[i].getXCoord();
        y = doodlebug[i].getYCoord();
        board[y][x] = 'X';
    }
}

int main() {
    srand(time(nullptr));
    int time_step = 0;
    char board_array[20][20];
    vector<Ant> ant_vector;
    vector<Doodlebug> doodlebug_vector;
    initializeBoard(board_array, ant_vector, doodlebug_vector);

    do {
        cout << "Time step: " << time_step << endl;
        cout << "Ant count: " << ant_vector.size() << endl;
        cout << "Doodlebug count: " << doodlebug_vector.size() << endl;
        updateBoard(board_array, ant_vector, doodlebug_vector);
        printBoard(board_array);

//    exit code 8 happens somewhere in this for loop; suspect a floating point exception
        for (int i = 0; i < doodlebug_vector.size(); i++) {
            doodlebug_vector[i].move(board_array, ant_vector);
        }
        for (int i = 0; i < ant_vector.size(); i++) {
            ant_vector[i].move(board_array);
        }

        cout << "Press [Enter] to advance 1 time step.";
        cout << endl;
        time_step++;
    } while (cin.get());

    return 0;
}
