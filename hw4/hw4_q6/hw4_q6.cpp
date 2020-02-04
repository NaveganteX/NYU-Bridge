#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int number_of_digits = 0;
        int count = i;
        while (count != 0) {
            count = count / 10;
            number_of_digits++;
        }

        int factor = 1;
        for (int b = 1; b < number_of_digits; b++) {
            factor *= 10;
        }

        int current_num = i;
        int digit, even = 0, odd = 0;
        for (int c = 0; c < number_of_digits; c++) {
            digit = current_num / factor;
            current_num %= factor;
            if ((digit % 2) == 0) {
                even++;
            } else {
                odd++;
            }
            factor /= 10;
        }
       if (even > odd) {
           cout << i << endl;
       }
    }

    return 0;
}
