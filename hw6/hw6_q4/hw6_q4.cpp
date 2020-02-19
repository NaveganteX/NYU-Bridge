#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num) {
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }

    for (int i = sqrt(num) - 1; i > 0; i--) {
        if (num % i == 0) {
            cout << (num / i) << " ";
        }
    }
}

int main() {
    int number = 0;

    cout << "Please enter a positive integer >= 2: ";
    cin >> number;

    printDivisors(number);

    return 0;
}
