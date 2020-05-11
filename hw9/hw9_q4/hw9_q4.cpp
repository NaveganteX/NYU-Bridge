#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);

int main() {
    int arr[] = {1, -4, 9, 4, 8, 2};
    cout << "original array:" << endl;
    printArray(arr, 6);

    oddsKeepEvensFlip(arr, 6);

    cout << "reordered array:" << endl;
    printArray(arr, 6);

    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int *tempArray = new int[arrSize];
    int oddCounter = 0, evenCounter = (arrSize - 1);

    for (int i = 0; i < arrSize; i++) {
        if ((arr[i] % 2) != 0) {
            tempArray[oddCounter] = arr[i];
            oddCounter++;
        }
    }

    for (int i = 0; i < arrSize; i++) {
        if ((arr[i] % 2) == 0) {
            tempArray[evenCounter] = arr[i];
            evenCounter--;
        }
    }

    for (int i = 0; i < arrSize; i++) {
        arr[i] = tempArray[i];
    }
}

void printArray(int arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i];
        if (i < (arrSize - 1)) {
            cout << ", ";
        }
    }
    cout << "]" <<endl;
}

