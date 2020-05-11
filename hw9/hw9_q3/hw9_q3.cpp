#include <iostream>
using namespace std;

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
void printArray(int* array, int arrSize);

int main() {
    cout << "getPosNums1:" << endl;
    int arrOne[] = {3, -1, -3, 0, 6, 4};
    int arrOneSize = 6;
    int outPosArrOneSize = 0;

    int *newArrayPtr = getPosNums1(arrOne, arrOneSize, outPosArrOneSize);
    cout << "Original array:" << endl;
    printArray(arrOne, arrOneSize);
    cout << "New array:" << endl;
    printArray(newArrayPtr, outPosArrOneSize);
    cout << endl;

    cout << "getPosNums2:" << endl;
//    int arrTwo[] = {16, -1, 3, 0, 6, 4};
    int arrTwo[] = {5, -2, -1, 0, 1, 2, 3, -4, 5, 6};
    int arrTwoSize = 10;
    int *outPosArrTwo = new int[arrTwoSize];
    int outPosArrTwoSize = 0;
    getPosNums2(arrTwo, arrTwoSize, *&outPosArrTwo, outPosArrTwoSize);

    cout << "Original array:" << endl;
    printArray(arrTwo, arrTwoSize);
    cout << "New array:" << endl;
    printArray(outPosArrTwo, outPosArrTwoSize);
    cout << endl;

    cout << "getPosNums3:" << endl;
    int arrThree[] = {0, 5, 3, 0, 56, 4};
    int arrThreeSize = 6;
    cout << "Original array:" << endl;
    printArray(arrThree, arrThreeSize);

    int *outPosArrThreeSize = &arrThreeSize;
    int *outPosArrThree = getPosNums3(arrThree, arrThreeSize, outPosArrThreeSize);

    cout << "New array:" << endl;
    printArray(outPosArrThree, *outPosArrThreeSize);
    cout << endl;

    cout << "getPosNums4:" << endl;
    int arrFour[] = {0, 5, -3, -2, 72, 8};
    int arrFourSize = 6;
    cout << "Original array:" << endl;
    printArray(arrFour, arrFourSize);

    int *outPosArrFourSizePtr = &arrFourSize;
    int *outPosArrFour = new int[arrFourSize];
    int **outPosArrFourPtr = &outPosArrFour;
    getPosNums4(arrFour, arrFourSize, outPosArrFourPtr, outPosArrFourSizePtr);

    cout << "New array:" << endl;
    printArray(outPosArrFour, *outPosArrFourSizePtr);

    return 0;
}

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize) {
    int tempArraySize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            tempArraySize += 1;
        }
    }
    int *newArray = new int[tempArraySize];
    int newArrayCounter = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            newArray[newArrayCounter] = arr[i];
            newArrayCounter++;
        }
    }
    outPosArrSize = tempArraySize;
    return newArray;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int outPosArrCounter = 0;
    int newArraySize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            newArraySize += 1;
        }
    }

    int *newArray = new int[newArraySize];

    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            newArray[outPosArrCounter] = *(arr + i);
            outPosArrCounter++;
        }
    }

    delete[] outPosArr;
    outPosArr = newArray;

    outPosArrSize = newArraySize;

    delete[] newArray;
    newArray = nullptr;
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
    int tempOutPosArrSize = 0, tempArrayCounter = 0;
    int newArraySize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            newArraySize += 1;
        }
    }

    int *newArray = new int[newArraySize];

    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            newArray[tempArrayCounter] = *(arr + i);
            tempOutPosArrSize++;
            tempArrayCounter++;
        }
    }

    *outPosArrSizePtr = tempOutPosArrSize;

    return newArray;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int tempOutPosArrSize = 0, tempArrayCounter = 0, newArraySize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            newArraySize += 1;
        }
    }

    int *tempArray = new int[newArraySize];

    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            tempArray[tempArrayCounter] = arr[i];
            tempOutPosArrSize++;
            tempArrayCounter++;
        }
    }

    *outPosArrSizePtr = tempOutPosArrSize;
    *outPosArrPtr = tempArray;
}

void printArray(int* array, int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        cout << array[i];
        if (i != (arrSize - 1)) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


