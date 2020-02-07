#include <iostream>
using namespace std;

int main() {
    cout << "section a" << endl;

    int input_a, number_a=0;
    cout << "Please enter a positive integer: ";
    cin >> input_a;

    while (input_a > 0) {
        number_a += 2;
        cout << number_a << endl;
        input_a--;
    }

    cout << "section b" << endl;

    int input_b, number_b=0;
    cout << "Please enter a positive integer: ";
    cin >> input_b;

    int counter;
    for (counter = 0; counter < input_b; counter++) {
        number_b += 2;
        cout << number_b << endl;
    }

    return 0;
}
