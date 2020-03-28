#include <iostream>
using namespace std;

int lowestCost(int arr[], int arrSize);

int main() {
    int arr1[6] = {0, 3, 80, 6, 57, 10};
    int arr2[10] = {0, 20, 11, 5, 13, 7, 18, 13, 14, 2};

    int arr1Result = lowestCost(arr1, 6);
    int arr2Result = lowestCost(arr2, 10);

    cout << "arr1 lowest cost: " << arr1Result << endl;
    cout << "arr2 lowest cost: " << arr2Result << endl;

    return 0;
}

int lowestCost (int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0];
    } else {
        int currentSum = arr[arrSize - 1];
        if (arr[arrSize - 2] <= arr[arrSize - 3]) {
            currentSum += lowestCost(arr, arrSize - 1);
        } else {
            currentSum += lowestCost(arr, arrSize - 2);
        }
        return currentSum;
    }
}
