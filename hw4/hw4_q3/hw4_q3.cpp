#include <iostream>
using namespace std;

int main() {
    int decimal_num;

    cout << "Enter decimal number: ";
    cin >> decimal_num;

    int digits=0;
    int num = decimal_num;
    while (num >= 1) {
        num /= 2;
        digits++;
    }

    int current_num = decimal_num, binary_num = 0, remainder = 0, factor = 1;
    for (int i = 0; i < digits; i++) {
        remainder = current_num % 2;

        for (int b = 0; b < i; b++) {
            factor *= 10;
        }

        binary_num += remainder * factor;
        current_num /= 2;
        factor = 1;
    }

    cout << "The binary representation of " << decimal_num << " is " << binary_num;
    return 0;
}
