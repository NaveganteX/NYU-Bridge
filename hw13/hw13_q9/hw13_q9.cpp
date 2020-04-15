#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Organism {
    int x, y;
public:
    Organism(int x_coord, int y_coord) {
        x = x_coord;
        y = y_coord;
    }
//    virtual void move() const = 0;
    int getXCoord() { return x; }
    int getYCoord() { return y; }
};

class Ant :public Organism {
public:
    Ant(int x_coord, int y_coord) :Organism(x_coord, y_coord) {}
};

class Board {
    char board[20][20];
public:
    // constructor
    Board() {
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 20; x++) {
                board[x][y] = '-';
            }
        }
    }

    void printBoard() {
        for (int x = 0; x < 20; x++) {
            for (int y = 0; y < 20; y++) {
                cout << " " << board[x][y] << " ";
            }
            cout << endl;
        }
    }

    void updateBoard(vector<Ant> ant_vector) {
        for (int i = 0; i < ant_vector.size(); i++) {
            int x = ant_vector[i].getXCoord();
            int y = ant_vector[i].getYCoord();
            board[x][y] = 'X';
        }
    }
};

int main() {
    srand(time(nullptr));

    Board board;
//    board.printBoard();

    int x_ant = (rand() % 20), y_ant = (rand() % 20);
    Ant a(3, 4);
    Ant b(13, 5);
    Ant c(6, 9);
    Ant d(12, 14);
    Ant e(19, 19);

    vector<Ant> ant_vector = {a, b, c, d, e};
    board.updateBoard(ant_vector);
    board.printBoard();

    return 0;
}
