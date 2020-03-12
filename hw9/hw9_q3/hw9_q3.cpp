#include <iostream>
using namespace std;

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
//    int arrOne[] = {3, -1, -3, 0, 6, 4};
//    int w = 0;
//    cout << getPosNums1(arrOne, 6, w) << endl;
//
//    int arrTwo[] = {-1, -1, -3, 0, -6, -4};
//    int *newArr = new int[6];
//    int x = 0;
//    getPosNums2(arrTwo, 6, *&newArr, x);
//    for (int i = 0; i < 6; i++) {
//        cout << *(newArr + i) << endl;
//    }

//    int arrThree[] = {0, 5, -3, 0, -56, -4};
//    int outPosArrSizePtr = 0;
//    getPosNums3(arrThree, 6, &outPosArrSizePtr);
//
//    for (int i = 0; i < 6; i++) {
//        cout << *(arrThree + i) << endl;
//    }
//    cout << outPosArrSizePtr << endl;



    return 0;
}

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize) {
    int *newArray = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        // cout << *(arr + i) << endl;
        if (*(arr + i) > 0) {
            *(newArray + i) = *(arr + i);
            outPosArrSize += 1;
        }
    }
    return newArray;
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            outPosArr[i] = *(arr + i);
            outPosArrSize += 1;
        }
    }
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
    int tempOutPosArrSize = 0;
    int *tempArray = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > 0) {
            *(tempArray + i) = *(arr + i);
            tempOutPosArrSize += 1;
        }
    }

    for (int i = 0; i < arrSize; i++) {
        *(arr + i) = *(tempArray + i);
    }

    *outPosArrSizePtr = tempOutPosArrSize;
    delete[] tempArray;
    tempArray = nullptr;

    return arr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    for (int i = 0; i < arrSize; i++) {

    }
}


