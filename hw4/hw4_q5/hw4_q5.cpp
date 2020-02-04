#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive integer number: ";
    cin >> n;

    for (int i = 0; i < (2 * n); i++) {
        string space, asterisk;
        if (i < n) {
            for (int space_count = 1; space_count <= i; space_count++) {
                space += "   ";
            }
            for (int asterisk_count = ((2 * n) - 1); asterisk_count > (2 * i); asterisk_count--) {
                asterisk += " * ";
            }
        } else {
            for (int space_count = ((2 * n) - 1); space_count > i; space_count--) {
                space += "   ";
            }
            for (int asterisk_count = (2 * i); asterisk_count > ((2 * n) - 1); asterisk_count--) {
                asterisk += " * ";
            }
        }
        cout << space << asterisk << endl;
    }

    return 0;
}
