#include <iostream>
#include <string>
using namespace std;

int main() {
    int grad_year, current_year, year;
    string name, status;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    cin >> grad_year;

    cout << "Please enter current year: ";
    cin >> current_year;

    year = grad_year - current_year;

    if (year == 0) {
        status = "have graduated";
    } else if (year == 1) {
        status = "are a Senior";
    } else if (year == 2) {
        status = "are a Junior";
    } else if (year == 3) {
        status = "are a Sophomore";
    } else if (year == 4) {
        status = "are a Freshman";
    } else {
        status = "are not in college yet";
    }

    cout << name << ", you " << status;

    return 0;
}
