#include <iostream>
using namespace std;

int main() {
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    double num;
    int method;

    cout << "Please enter a Real number: ";
    cin >> num;

    cout << "Choose your rounding method: " << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> method;

    switch (method) {
        case FLOOR_ROUND:
            if (num < 0) {
                num -= 1;
            }
            cout << (int)num;
            break;
        case CEILING_ROUND:
            if (num > 0) {
                num += 1;
            }
            cout << (int)num;
            break;
        case ROUND:
            if (num > 0) {
                num += 0.5;
            } else {
                num -= 0.5;
            }
            cout << (int)num;
            break;
        default:
            break;
    }
    return 0;
}
