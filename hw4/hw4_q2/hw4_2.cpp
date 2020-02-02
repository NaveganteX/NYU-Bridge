#include <iostream>
#include <string>
using namespace std;

int main() {
    int input, number, m, d, c, l, x, v, i;
    string roman;

    cout << "Enter decimal number:" << endl;
    cin >> input;

    number = input;
    if (number > 999) {
        m = number / 1000;
        number %= 1000;
//        cout << "M: " << m << endl;
    }
    if (number > 499) {
        d = number / 500;
        number %= 500;
        while (d > 1) {
            m += 1;
            d--;
        }
//        cout << "D: " << d << endl;
    }
    if (number > 99) {
        c = number / 100;
        number %= 100;
        while (c > 4) {
            d += 1;
            c--;
        }
//        cout << "C: " << c << endl;
    }
    if (number > 49) {
        l = number / 50;
        number %= 50;
        while (l > 1) {
            c += 1;
            l--;
        }
//        cout << "L: " << l << endl;
    }
    if (number > 9) {
        x = number / 10;
        number %= 10;
        while (x > 4) {
            l += 1;
            x--;
        }
//        cout << "X: " << x << endl;
    }
    if (number > 4) {
        v = number / 5;
        number %= 5;
        while (v > 1) {
            x += 1;
            v--;
        }
//        cout << "V: " << v << endl;
    }
//    else {
        i = number;
        while (i > 4) {
            v += 1;
            i--;
        }
        number = 0;
//        cout << "I: " << i << endl;
//    }

    while (m > 0) {
       roman += "M";
       m--;
    }
    while (d > 0) {
       roman += "D";
       d--;
    }
    while (c > 0) {
       roman += "C";
       c--;
    }
    while (l > 0) {
       roman += "L";
       l--;
    }
    while (x > 0) {
       roman += "X";
       x--;
    }
    while (v > 0) {
       roman += "V";
       v--;
    }
    while (i > 0) {
       roman += "I";
       i--;
    }

    cout << input << " is " << roman << endl;

    return 0;
}
