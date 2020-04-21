// Sort practice + notes
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void insertionSort(vector<T> &a) {
    int j;
    for (int i = 0; i < a.size(); i++) {
        T temp = a[i];
        for (j = i; (j > 0) && (temp < a[j - 1]); j--) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

int find_index_of_min(int arr[], int low, int index_of_high) {
    int min = arr[low], min_index = low;
    for (int i = low + 1; i <= index_of_high; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

void selectionSort(int *arr, int arr_size) {
    int min_index;
    for (int i = 0; i < arr_size; i++) {
        int temp;
        min_index = find_index_of_min(arr, i, arr_size - 1);
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main() {
    vector<int> arr1;
    arr1 = {1, 3, 6, 2, 7, 88, 60, 4, 6, 56};
    insertionSort(arr1);
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " ";
    }

    cout << endl;

    int arr2[10] = {1, 3, 6, 2, 7, 88, 60, 4, 6, 56};
    selectionSort(arr2, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << " ";
    }
    return 0;
}
