#include <iostream>
#include <vector>
using namespace std;

template <class T>
vector<T> minMax(vector<T> &arr, vector<T> &min_max, int left, int right) {
    vector<T> left_array;
    vector<T> right_array;
    if (left == right) {
        min_max[0] = arr[left];
        min_max[1] = arr[right];
        return min_max;
    } else if (left + 1 == right) {
        if (arr[left] > arr[right]) {
            min_max[0] = arr[right];
            min_max[1] = arr[left];
        } else {
            min_max[0] = arr[left];
            min_max[1] = arr[right];
        }
        return min_max;
    }

    int middle = (left + right) / 2;
    left_array = minMax(arr, min_max, left, middle);
    right_array = minMax(arr, min_max, middle + 1, right);

    if (left_array[0] < right_array[0]) {
        min_max[0] = left_array[0];
    } else {
        min_max[0] = right_array[0];
    }

    if (left_array[1] > right_array[1]) {
        min_max[1] = left_array[1];
    } else {
        min_max[1] = right_array[1];
    }

    return min_max;
}

template <class T>
vector<T> minMax(vector<T> &arr) {
    vector<T> min_max;
    min_max = {0, 0};
    return minMax(arr, min_max, 0, arr.size() - 1);
}

int main() {
    vector<int> arr;
    arr = {5, 100, 10, 6, 34, -1210, 1, 88, 3, 900, 45, 29};
    vector<int> min_max;

//    vector<double> arr;
//    arr = {100.76, 1.11, 44.57, 1.36, 3.302, 30.929, 68.24};
//    vector<double> min_max;

//    vector<char> arr;
//    arr = {'l', 'b', 'a', 'z'};
//    vector<char> min_max;

    min_max = minMax(arr);
    cout << "min: " << min_max[0] << endl;
    cout << "max: " << min_max[1] << endl;

    return 0;
}