#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void merge(vector<T> &arr, vector<T> &temp_arr, int left_pos, int right_pos, int right_end) {
    int left_end = right_pos - 1;
    int temp_pos = left_pos;
    int num_elements = right_end - left_pos + 1;
    while (left_pos <= left_end && right_pos <= right_end) {
        if (arr[left_pos] <= arr[right_pos]) {
            temp_arr[temp_pos++] = arr[left_pos++];
        } else {
            temp_arr[temp_pos++] = arr[right_pos++];
        }
    }

    while (left_pos <= left_end) {
        temp_arr[temp_pos++] = arr[left_pos++];
    }

    while(right_pos <= right_end) {
        temp_arr[temp_pos++] = arr[right_pos++];
    }

    for (int i = 0; i < num_elements; i++, right_end--) {
        arr[right_end] = temp_arr[right_end];
    }
}

template <class T>
void mergeSort(vector<T> &arr, vector<T> &temp_arr, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(arr, temp_arr, left, center);
        mergeSort(arr, temp_arr, center + 1, right);
        merge(arr, temp_arr, left, center + 1, right);
    }
}

template <class T>
void mergeSort(vector<T> &arr) {
    vector<T> temp_arr(arr.size());
    mergeSort(arr, temp_arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {6, 6, 7, 1, 3, 100 , 50, 34};

    mergeSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}