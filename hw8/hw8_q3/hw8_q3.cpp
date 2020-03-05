#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

//    int arr3[10] = {3, 6, 4, 1, 12};
//    int arr3[10] = {6, 8, 12, 11, 9};
    int arr3[10] = {13, 7, 12, 11, 9};
    int arr3Size = 5;

//    reverseArray(arr1, arr1Size);
//    printArray(arr1, arr1Size);

//    removeOdd(arr2, arr2Size);
//    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

void printArray(int arr[], int arrSize){
    int i;

    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize) {
    for (int i = 0; i < (arrSize / 2); i++) {
        int tempHolder = arr[i];
        arr[i] = arr[(arrSize - 1) - i];
        arr[(arrSize - 1) - i] = tempHolder;
    }
}

void removeOdd(int arr[], int& arrSize) {
    int oddCount = 0, tempHolder = 0;
    for (int i = 0, lowestOddIndex = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            tempHolder = arr[lowestOddIndex];
            arr[lowestOddIndex] = arr[i];
            arr[i] = tempHolder;
            lowestOddIndex += 1;
        } else {
            oddCount += 1;
        }
    }
    arrSize -= oddCount;
}

void splitParity(int arr[], int arrSize) {
    int tempHolder = 0;
    for (int i = 0, lowestOddIndex = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            tempHolder = arr[lowestOddIndex];
            arr[lowestOddIndex] = arr[i];
            arr[i] = tempHolder;
            lowestOddIndex += 1;
        }
    }
}