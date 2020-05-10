#include <iostream>
using namespace std;

//DynArray is a substitute for Vector to understand how Vectors work under the hood
class DynArray {
    int* data; // don't know how many elements there will be so we instead create a pointer
    int totalCapacity; // number of elements in the array (total capacity of array)
    int numItems; // number of items in the array (logical size)
public:
    // constructor
    DynArray() :data(new int[5]), totalCapacity(5), numItems(0) {}

    // Big Three: destructor, copy constructor, and assignment operator
    // destructor
    virtual ~DynArray() { delete[] data; } // !!!! make destructor virtual so that deleting a pointer of a basetype of the base class will delete the
    // copy constructor
    DynArray(const DynArray& rhs) :data(nullptr), totalCapacity(0), numItems(0) { *this = rhs; } //call to assignment operator
    // assignment operator
    DynArray& operator=(const DynArray& rhs);

    void clear() { numItems = 0; }
    void resize(int newSize);
    void push_back(int newValue);
    int pop_back();
};

class OtherArray :public DynArray {
    int *ptr;
public:
    OtherArray() :ptr(new int(0)) {}
    ~OtherArray() { delete ptr; }
    void setVal(int newVal) { *ptr = newVal; }
    int getVal() const { return *ptr; }
};

DynArray& DynArray::operator=(const DynArray &rhs) {
    if (this == &rhs) { // checks for self assignment
        return *this;
    }
    delete [] data; // deletes this' data which is a nullptr;
    data = new int[rhs.numItems]; // can also set data to int[totalCapacity]. This will be up to programmer.
    totalCapacity = rhs.numItems;
    numItems = rhs.numItems;
    for (int i = 0; i < numItems; i++) {
        data[i] = rhs.data[i];
    }
    return *this;
}

void DynArray::resize(int newSize) {
    int *temp = new int[newSize];
    if (newSize > numItems) { //make new array bigger
        for (int i = 0; i < numItems; i++) {
            temp[i] = data[i];
        }
    } else { //make new array smaller
        for (int i = 0; i < newSize; i++) {
            temp[i] = data[i];
        }
        numItems = newSize;
    }
    totalCapacity = newSize;
    delete[] data;
    data = temp;
}

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

void testFunc() {
    DynArray *ptr = new OtherArray;
    ptr -> push_back(1);
    ptr -> push_back(2);
    delete ptr;
    /* In testFunc() the ptr is a DynArray type (not OtherArray type). If the base class destructor is not virtual, the delete will
     * be calling the DynArray destructor, NOT the OtherArray class' destructor. This leads to a memory leak!
     * If it is virtual, the DynArray destructor will be overidden by the derived class' destructor which is what
     * we want
     */
}

int main() {
    for (int i = 0; i < 1000000000; i++) {
        testFunc();
    }

    return 0;
}
