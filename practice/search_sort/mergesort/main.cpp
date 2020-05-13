#include <iostream>
#include <vector>
using namespace std;

template <class T>
void merge(vector<T> &arr, int left, int middle, int right) {
    vector<T> temp_left;

}

template <class T>
void mergeSort(vector<T> &arr, int left, int right) {
    if (arr.size() == 1) {
        return arr;
    } else if (arr.size() == 2) {
        if (arr[0] > arr[1]) {
            T temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return arr;
    }

    // split arr into two (a left and right subarray)
    // recursively call mergesort on those subarrays
    int middle = (left + right) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int main() {
    return 0;
}

// test cases: size 0, 1, 2, 3

