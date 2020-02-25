#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividers (int num, int& outCountDivs, int& outSumDivs);
bool isPerfect (int num);

int main() {
    int m;
    cout << "Please enter an integer >= 2: ";
    cin >> m;

    for (int i = 2; i <= m; i++) {
        if (isPerfect(i)) {
            cout << i << endl;
        }
    }

    for (int b = 2; b <= m; b++) {
        
    }

    return 0;
}

void analyzeDividers (int num, int& outCountDivs, int& outSumDivs) {
    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0) {
//            cout << i << " ";
            outCountDivs++;
            outSumDivs += i;
        }
    }

    for (int b = ceil(sqrt(num)); b <= num; b++) {
        if (num % b == 0) {
//            cout << b << " ";
            outCountDivs++;
            outSumDivs += b;
        }
    }
}

bool isPerfect (int num) {
    int outCountDivs = 0, outSumDivs = 0;
    analyzeDividers(num, outCountDivs, outSumDivs);
    if ((outSumDivs - num) == num) {
//        cout << "outSumDivs: " << outSumDivs << endl;
//        cout << "true";
        return true;
    }
//    cout << "false";
    return false;
}