#include <iostream>
using namespace std;

int sumArray(int* arr, int arrSize);

int main() {
    int arr[] = {1, 2, 3, 4};
    int arrSize = 4;
    int a = sumArray(arr, arrSize);
    cout << "sum: " << a << endl;
    return 0;
}

int sumArray(int* arr, int arrSize) {
//    base case:
    int resSum;
    if (arrSize == 1) {
        return arr[0];
    } else {
        resSum = sumArray(arr, arrSize - 1);
        cout << "resSum: " << resSum << endl;
        resSum += arr[arrSize - 1];
//        resSum = sumArray(arr + 1, arrSize - 1);
//        resSum += arr[0];
//        cout << resSum << endl;
        return resSum;
    }
}