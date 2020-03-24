#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr1[] = {2, -1, 3, 10};
    int arr1Size = 4;
    cout << "sumOfSquares:" << endl;
    cout << sumOfSquares(arr1, arr1Size) << endl;
    cout << endl;

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2Size = 10;
    cout << "isSorted:" << endl;
    if (isSorted(arr2, arr2Size)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0] * arr[0];
    } else {
        int currentSum;
        currentSum = sumOfSquares(arr, arrSize - 1);
        currentSum += arr[arrSize - 1] * arr[arrSize - 1];
        return currentSum;
    }
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize == 1) {
        return true;
    } else {
        if (arr[arrSize - 2] <= arr[arrSize - 1]) {
            if (isSorted(arr, arrSize - 1)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}
