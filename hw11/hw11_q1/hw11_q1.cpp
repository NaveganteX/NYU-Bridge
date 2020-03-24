#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {
    cout << "printTriangle(n):" << endl;
    printTriangle(4);
    cout << endl;

    cout << "printOppositeTriangles(n):" << endl;
    printOppositeTriangles(4);
    cout << endl;

    cout << "printRuler(n):" << endl;
    printRuler(4);
    return 0;
}

void printTriangle(int n) {
    if (n == 1) {
        cout << "*" << endl;
    } else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printOppositeTriangles(int n) {
    if (n == 0) {
        cout << "*" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
        if (n == 1) {
            cout << "*" << endl;
        } else {
            printOppositeTriangles(n - 1);
            for (int i = 0; i < n; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
}

void printRuler(int n) {
    if (n == 1) {
        cout << "- " << endl;
    } else {
        printRuler(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "- ";
        }
        cout << endl;
        printRuler(n - 1);
    }
}
