#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 0, divisor_Count = 0;
    cout << "Input a number: ";
    cin >> n;

    divisor_Count = 0;
    for (int i = 2; i < sqrt(n); i++) {
        if ((n % i) == 0) {
            divisor_Count++;
        }
    }

    if (divisor_Count == 0) {
        cout << n << " is a prime number" << endl;
    } else {
        cout << n << " is not a prime number" << endl;
    }

    return 0;
}