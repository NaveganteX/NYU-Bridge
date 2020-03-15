#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {
    int arr[] = {5, 2, 11, 7, 6, 4};
    oddsKeepEvensFlip(arr, 6);

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << ", ";
    }

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

