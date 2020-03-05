#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PIN[5] = {3, 5, 6, 9, 1};

int main() {
    int arrNum[5], userInput[5];
    int num = 0, digit = 0;

    cout << "Please enter your PIN according to the following mapping:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << PIN[i];
    }
    cout << endl;
    cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM: ";

//    generate NUM array with random numbers
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        arrNum[i] = (rand() % 10);
        cout << arrNum[i] << " ";
    }
    cout << endl;

    cin >> num;

//    parse input into an array to avoid asking user to enter space
    for (int i = 10000, idx = 0; i > 0; i /= 10, idx++) {
        digit = (num / i) * i;
        userInput[idx] = digit / i;
        num -= digit;
    }

    for (int i = 0; i < 5; i++) {
        if (arrNum[PIN[i]] != userInput[i]) {
            i = 5;
            cout << "Your PIN is not correct" << endl;
        } else if ((i == 4) && (arrNum[PIN[i]] == userInput[i])) {
            cout << "Your PIN is correct" << endl;
        }
    }
    return 0;
}
