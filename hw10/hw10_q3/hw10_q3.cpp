#include <iostream>
#include <vector>
using namespace std;

int main1();
int* readNumsV1(int &outNumArrLogicalSize);
void numSearchV1(int array[], int arrayLogicalSize, int &outNumFoundArrayLogicalSize);

int main2();
vector<int> readNumsV2();
void numSearchV2(vector<int> numVector);


int main() {
    return main1();
//    return main2();
}

int main1() {
    int *arr;
    int logicalSize = 1;
    int arrayLogicalSize = 1;

    arr = readNumsV1(logicalSize);
    numSearchV1(arr, logicalSize, arrayLogicalSize);
    return 0;
}

int* readNumsV1(int &outNumArrLogicalSize){
    int* numArray;
    int numArrayPhysicalSize, numArrayLogicalSize, currentNum;
    bool endInput;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1" << endl;

    numArray = new int[1];
    numArrayPhysicalSize = 1;
    numArrayLogicalSize = 0;

    endInput = false;
    while (endInput == false) {
        cin >> currentNum;
        if (currentNum == -1) {
            endInput = true;
        } else {
            if (numArrayLogicalSize == numArrayPhysicalSize) {
                int *numArrayTemp;
                numArrayTemp = new int[numArrayPhysicalSize * 2];
                for (int i = 0; i < numArrayLogicalSize; i++) {
                    numArrayTemp[i] = numArray[i];
                }
                delete[] numArray;
                numArray = numArrayTemp;
                numArrayPhysicalSize *= 2;
            }
            numArray[numArrayLogicalSize] = currentNum;
            numArrayLogicalSize += 1;
        }
    }
    outNumArrLogicalSize = numArrayLogicalSize;
    return numArray;
}

void numSearchV1(int array[], int arrayLogicalSize, int &outNumFoundArrayLogicalSize) {
    int *numFoundArray;
    int num, numFoundArrayLogicalSize, numFoundArrayPhysicalSize;

    numFoundArray = new int[1];
    numFoundArrayPhysicalSize = 1;
    numFoundArrayLogicalSize = 0;

    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    for (int i = 0; i < arrayLogicalSize; i++) {
        if (array[i] == num) {
            if (numFoundArrayLogicalSize == numFoundArrayPhysicalSize) {
                int *numFoundArrayTemp;
                numFoundArrayTemp = new int[numFoundArrayPhysicalSize * 2];
                for (int j = 0; j < numFoundArrayLogicalSize; j++) {
                    numFoundArrayTemp[j] = numFoundArray[j];
                }
                delete[] numFoundArray;
                numFoundArray = numFoundArrayTemp;
                numFoundArrayPhysicalSize *= 2;
            }
            numFoundArray[numFoundArrayLogicalSize] = i + 1;
            numFoundArrayLogicalSize += 1;
        }
    }

    outNumFoundArrayLogicalSize = numFoundArrayLogicalSize;

    cout << num << " shows in lines ";
    for (int i = 0; i < outNumFoundArrayLogicalSize; i++) {
        if (i != outNumFoundArrayLogicalSize - 1) {
            cout << numFoundArray[i] << ", ";
        } else {
            cout << numFoundArray[i] << "." << endl;
        }
    }
}

int main2() {
    vector<int> numsVector;
    numsVector = readNumsV2();

    numSearchV2(numsVector);
    return 0;
}

vector<int> readNumsV2() {
    vector<int> inputVector;
    int currentNum;
    bool endInput;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1" << endl;

    endInput = false;
    while (endInput == false) {
        cin >> currentNum;
        if (currentNum == -1) {
            endInput = true;
        } else {
            inputVector.push_back(currentNum);
        }
    }
    return inputVector;
}

void numSearchV2(vector<int> numVector) {
    int num;
    vector<int> numFoundVector;

    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    for (int i = 0; i < numVector.size(); i++) {
        if (num == numVector[i]) {
            numFoundVector.push_back(i + 1);
        }
    }

    cout << num << " shows in lines ";
    for (int i = 0; i < numFoundVector.size(); i++) {
        if (i != numFoundVector.size() - 1) {
            cout << numFoundVector[i] << ", ";
        } else {
            cout << numFoundVector[i];
        }
    }
}