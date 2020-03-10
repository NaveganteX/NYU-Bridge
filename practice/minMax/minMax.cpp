#include <iostream>
using namespace std;

void minMax(int *arr, int arrSize, int *min, int *max);

int main() {
    int arr[] = {3, 7, 5, 2, 1};
    int min, max;

    minMax(arr, 5, &min, &max);

    cout << min << " " << max << endl;
    return 0;
}

void minMax(int *arr, int arrSize, int *min, int *max) {
    int localMin = arr[0], localMax = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if (*(arr + i) > localMax) {
            localMax = *(arr + i);
        } else {
            localMin = *(arr + i);
        }
    }
    *min = localMin;
    *max = localMax;
}