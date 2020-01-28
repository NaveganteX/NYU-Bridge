#include <iostream>
#include <string>
using namespace std;

int main() {
    double weight, height, bmi;
    string status;

    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    weight *= 0.453592;
    height *= 0.0254;

    bmi = weight / (height * height);

    if (bmi >= 30) {
        status = "Obese";
    } else if (bmi >= 25 && bmi < 30) {
        status = "Overweight";
    } else if (bmi >= 18.5 && bmi < 25) {
        status = "Normal";
    } else {
        status = "Underweight";
    }

    cout << "Your weight status is: " << status;
    return 0;
}
