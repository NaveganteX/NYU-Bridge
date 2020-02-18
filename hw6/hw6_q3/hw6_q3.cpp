#include <iostream>
using namespace std;

double factorial(int n) {
    double fact = 1;
    for (int i = 1; i <= n; i ++) {
        fact *= i;
    }
    return fact;
}

double eApprox(int n) {
    double e = 1;
    for (int i = 1; i <= n; i++) {
        e += 1 / (factorial(i));
    }
    return e;
}


int main() {
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    cout << eApprox(number);

    return 0;
}

