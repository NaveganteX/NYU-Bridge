#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, x1, x2, discriminant;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0) {
        if (a == 0) {
            cout << "This equation has no solutions";
        } else {
            x1 = ((-1 * b) + (sqrt(discriminant))) / (2 * a);
            x2 = ((-1 * b) - (sqrt(discriminant))) / (2 * a);
            cout << "This equation has two real solutions" << " X1 = " << x1 << " and X2 = " << x2;
        }
    } else if (discriminant == 0) {
        if (a == 0) {
            cout << "This equation has no solutions";
        } else {
            x1 = ((-1 * b) + (sqrt(discriminant))) / (2 * a);
            cout << "This equation has one solution X = " << x1;
        }
    } else if (discriminant < 0) {
        cout << "This equation has no real solutions";
    }

    return 0;
}
