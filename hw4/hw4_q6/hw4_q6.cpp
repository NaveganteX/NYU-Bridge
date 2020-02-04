#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int number_of_current_digits = 0;
        int count = i;
        while (count != 0) {
            count = count / 10;
            number_of_current_digits++;
        }

        int factor = 1;
        for (int b = 1; b < number_of_current_digits; b++) {
            factor *= 10;
        }

        int current_num = i;
        int current_digit, even_count = 0, odd_count = 0;
        for (int c = 0; c < number_of_current_digits; c++) {
            current_digit = current_num / factor;
            current_num %= factor;
            if ((current_digit % 2) == 0) {
                even_count++;
            } else {
                odd_count++;
            }
            factor /= 10;
        }
       if (even_count > odd_count) {
           cout << i << endl;
       }
    }

    return 0;
}
