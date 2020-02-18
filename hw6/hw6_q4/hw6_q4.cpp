#include <iostream>
using namespace std;

// O(N)
//void printDivisors(int num) {
//    for (int i = 1; i <= num; i++) {
//        if (num % i == 0) {
//            cout << i << " ";
//        }
//    }
//}

// O(sqrt(N))
void printDivisors(int num) {

}

int main() {
    int number = 0;

    cout << "Please enter a positive integer >= 2: ";
    cin >> number;

    printDivisors(number);

    return 0;
}
