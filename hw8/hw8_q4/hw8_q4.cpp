#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isPin(int arrNum[], int userInput[]);

const int pin[5] = {3, 5, 6, 9, 1};

int main() {
    int arrNum[5], userInput[5];
    int num = 0, digit = 0;

    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM: ";

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

//    for (int i = 0; i < 5; i++) {
//        cout << userInput[i] << endl;
//    }
    cout << endl;

    isPin(arrNum, userInput);

    return 0;
}

bool isPin (int arrNum[], int userInput[]) {
//    cout << arrNum[0] << endl;
//    cout << userInput[0] << endl;

//    for (int i = 0; i < 5; i++) {
//        if (userInput[i] == userInput)
//    }
}

