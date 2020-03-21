#include <iostream>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
void findMax(int arr[], int arrSize, int& currentMax);
int* sortArray(int maxNum, int arr[]);

int main() {
    int intArr[] = {5, 4, 4, 2, 2, 2};
    int intArrLogicalSize = 6;
    int newArrLogicalSize = 0;
    int arrMaxNum = 0;
    int *sortedArray;
    int *missingNumArray;

    findMax(intArr, intArrLogicalSize, arrMaxNum);

    sortedArray = sortArray(arrMaxNum, intArr);
    for(int i = 0; i < intArrLogicalSize; i++) {
        cout << sortedArray[i] << " ";
    }
    missingNumArray = findMissing(sortedArray, intArrLogicalSize, newArrLogicalSize);

//    for(int i = 0; i < intArrLogicalSize; i++) {
//        cout << missingNumArray[i] << " ";
//    }

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int smallest = arr[0], largest = arr[n - 1];
    int logicalSize = 1, physicalSize = 1;
    int *missingNums = new int[1];

    for (int i = 0; i < n; i++) {
        int nextNum = arr[i] + 1;
        if (arr[i + 1] != (smallest + 1)) {
//            cout << i << endl;
//                missingNums[i] = i;
//
//                if (logicalSize == physicalSize) {
//                    int *tempArray;
//                    tempArray = new int[physicalSize * 2];
//                    for (int i = 0; i < logicalSize; i++) {
//                        tempArray[i] = missingNums[i];
//                    }
//                    delete []missingNums;
//                    missingNums = tempArray;
//                    physicalSize *= 2;
//                }
//                missingNums[logicalSize - 2] = i;
//                logicalSize += 1;

        }
        smallest += 1;
    }
//    resArrSize = logicalSize;
    return missingNums;
}

void findMax(int arr[], int arrSize, int& currentMax) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > currentMax) {
            currentMax = arr[i];
        }
    }
}

int* sortArray(int maxNum, int arr[]) {
    int *indexArray = new int[maxNum + 1];
    int *outCountArray = new int[maxNum];

//    loop through arr[] and add number of appearances found into countArray
    for (int i = 0; i < maxNum; i++) {
        indexArray[arr[i]] += 1;
    }

//    loop through indexArray and add the previous counts
    for (int i = 0; i < maxNum; i++) {
        indexArray[i + 1] += indexArray[i];
    }

//    loop through arr[] and place arr[i] at outCountArray[indexArray[i]].
//    decrement outCountArray[indexArray[i]]
    for (int i = 0; i < maxNum; i++) {
        outCountArray[indexArray[arr[i]] - 1] = arr[i];
        indexArray[arr[i]] -= 1;
    }
    return outCountArray;
}