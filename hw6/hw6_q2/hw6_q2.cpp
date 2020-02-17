#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= i; c++) {
            cout << symbol;
        }
        cout << endl;
    }
}

void printPineTree(int n, char symbol) {

}

int main() {
    cout << "Hello, World!" << endl;

    printShiftedTriangle(3, 4, '*');
    return 0;
}

