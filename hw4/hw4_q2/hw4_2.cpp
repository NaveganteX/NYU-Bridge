#include <iostream>
using namespace std;

int main() {
    int input, number, m, d, c, l, x, v, i;

    cout << "Enter decimal number:" << endl;
    cin >> input;

    number = input;
    while (number > 0) {
        if (number > 999) {
            m = number / 1000;
            number %= 1000;
            cout << "M: " << m << endl;
        } else if (number > 499) {
            d = number / 500;
            number %= 500;
            cout << "D: " << d << endl;
        } else if (number > 99) {
            c = number / 100;
            number %= 100;
            cout << "C: " << c << endl;
        } else if (number > 49) {
            l = number / 50;
            number %= 50;
            cout << "L: " << l << endl;
        } else if (number > 9) {
            x = number / 10;
            number %= 10;
            cout << "X: " << x << endl;
        } else if (number > 4) {
            v = number / 5;
            number %= 5;
            cout << "V: " << v << endl;
        } else {
            i = number;
            number = 0;
            cout << "I: " << i << endl;
        }
    }

    cout << input << " is " << number << endl;

    return 0;
}
