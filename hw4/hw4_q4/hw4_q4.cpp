#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "section a" << endl;
    int seq_length_a, input_a;
    double product_a = 1, geometric_mean_a;

    cout << "Please enter the length of the sequence: ";
    cin >> seq_length_a;

    cout << "Please enter your sequence:" << endl;
    for (int i = 0; i < seq_length_a; i++) {
        cin >> input_a;
        product_a *= input_a;
    }
    geometric_mean_a = pow(product_a, (1.0/seq_length_a));
    cout << "The geometric mean is: " << geometric_mean_a << endl;

    cout << "section b" << endl;
    int input_b = 0, counter = 0;
    double product_b=1, geometric_mean_b;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
    while (input_b != -1) {
        cin >> input_b;
        if (input_b >= 0) {
            product_b *= input_b;
            counter++;
        }
    }
    geometric_mean_b = pow(product_b, (1.0/counter));
    cout << "The geometric mean is: " << geometric_mean_b << endl;
    return 0;
}
