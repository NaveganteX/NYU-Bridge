#include <iostream>
using namespace std;

int main() {
    int input, number=0;

    cout << "section a" << endl;
    cout << "Please enter a positive integer: ";
    cin >> input;

    while (input > 0) {
        number += 2;
        cout << number << endl;
        input--;
    }

    cout << "section b" << endl;
    cout << "Please enter a positive integer: ";
    cin >> input;

    int counter;
    for (counter = 0; counter < input; counter++) {
        number += 2;
        cout << number << endl;
    }

    return 0;
}
