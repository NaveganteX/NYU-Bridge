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

/*
 * findIndexOfMin() is a helper function for selectionSort().
 * if we let n = high - (low + 1) then the runtime of findIndexOfMin() is theta(n)
 * because at the worst the function will iterate over the array_size - 1. we do not include
 * the first element of the input array because we are comparing it to the next element up to the last element.
 * Therefore f(n) = theta(n) for the findIndexOfMin() helper function.
 */
int findIndexOfMin(int arr[], int low, int index_of_high) {
    int min = arr[low], min_index = low;
    for (int i = low + 1; i <= index_of_high; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

/*
 * again we define n as the size of the input array; n = high - (low + 1)
 * for each iteration the size of the input array decreases like so (i.e the "cost" of the for loop
 * and calling findIndexOfMin() is (n - i). so n, then n-1, n-2, etc)
 * n + (n-1) + (n-2) + (n-3) + ... + 2 + 1 = theta(n^2)
 * 
 * Thus, the selectionSort() algorithm (which includes the findIndexOfMin() helper function) has a
 * quadratic runtime (n^2)
 */

void selectionSort(int *arr, int arr_size) {
    int min_index;
    for (int i = 0; i < arr_size; i++) {
        int temp;
        min_index = findIndexOfMin(arr, i, arr_size - 1);
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
