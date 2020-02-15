#include <iostream>
using namespace std;

int main() {
    int n, k, n_fact = 1, k_fact = 1, k_Combination = 0;
    //    k_Combination will always be a whole number
    //    double k_Combination = 0;
    cout << "Please enter n and k" << endl;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        n_fact *= i;
    }

    for (int i = 1; i <= k; i++) {
        k_fact *= i;
    }

    k_Combination = n_fact / (k_fact * (n - k));

    cout << k_Combination;

    return 0;
}
