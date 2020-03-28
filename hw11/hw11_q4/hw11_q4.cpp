#include <iostream>
using namespace std;

int lowestCost(int arr[], int arrSize);

int main() {
    int arr1[6] = {0, 3, 80, 6, 57, 10};
    int arr2[10] = {0, 10, 11, 5, 2, 8, 3, 7, 14, 2};

    int result = lowestCost(arr1, 6);
//    int result = lowestCost(arr2, 10);
    cout << "result: " << result << endl;
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
