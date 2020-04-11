#include <iostream>
using namespace std;

//DynArray is a substitute for Vector to understand how Vectors work under the hood
class DynArray {
    int* data; // don't know how many elements there will be so we instead create a pointer
    int totalCapacity; // number of elements in the array (total capacity of array)
    int numItems; // number of items in the array (logical size)
public:
    DynArray() :data(new int[5]), totalCapacity(5), numItems(0) {}
    void clear() { numItems = 0; }
    void resize(int newSize);
    void push_back(int newValue);
    int pop_back();
};

void DynArray::push_back(int newValue) {
    if (numItems == totalCapacity) {
        resize(totalCapacity * 2); // double the space in the array if there is no more room in array to add
    }
    data[numItems++] = newValue;
}

int DynArray::pop_back() {
    if (numItems == 0) {
        return data[0]; // return garbage value
    }
    numItems--;
    return data[numItems]; // return the item "popped"
}

int main() {
    cout << "Hello, World!" << endl;

    return 0;
}
