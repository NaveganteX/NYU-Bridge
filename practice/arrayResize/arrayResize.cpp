// write function to resize array
#include <iostream>
using namespace std;

// "int*& arr" means passing in a pointer by reference
void resizeArray(int*& arr, int currentSize, int newSize);

int main() {
    int size = 10;
    int * arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    int oneMore = 110;
    int newSize = size * 2;
    resizeArray(arr, size, newSize);
//    adds 'oneMore' to 10th index
    arr[size++] = oneMore;
    size = newSize;

//    adds 'oneMore' to 20th index
//    arr[size++] = oneMore;

    for (int i = 0; i < size; i++) {
        cout << "arr[i]: " << arr[i] << endl;
    }

    return 0;
}

void resizeArray(int*& arr, int currentSize, int newSize) {
//    temp is a pointer that points to new array in Heap/dynamic memory of size newSize
    int *temp = new int[newSize];

    for (int i = 0; i < currentSize; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
