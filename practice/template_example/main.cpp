#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

template <class T> // template <typename SomeType>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
class DynArray {
    T* data; // don't know how many elements there will be so we instead create a pointer
    int totalCapacity; // number of elements in the array (total capacity of array)
    int numItems; // number of items in the array (logical size)
public:
    // constructor
    DynArray() :data(new T[5]), totalCapacity(5), numItems(0) {}

    // Big Three: destructor, copy constructor, and assignment operator
    // destructor
    virtual ~DynArray() { delete[] data; } // !!!! make destructor virtual so that deleting a pointer of a basetype of the base class will delete the
    // copy constructor
    DynArray(const DynArray<T>& rhs) :data(nullptr), totalCapacity(0), numItems(0) { *this = rhs; } //call to assignment operator
    // assignment operator
    DynArray<T>& operator=(const DynArray<T>& rhs);

    void clear() { numItems = 0; }
    void resize(int newSize);
    void push_back(T newValue);
    T pop_back();
    int size() const { return numItems; }
    T operator[](int index) const { return data[index]; }
    T& operator[](int index) { return data[index]; }
};

template <class T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T> &rhs) {
    if (this == &rhs) { // checks for self assignment
        return *this;
    }
    delete [] data; // deletes this' data which is a nullptr;
    data = new T[rhs.numItems]; // can also set data to int[totalCapacity]. This will be up to programmer.
    totalCapacity = rhs.numItems;
    numItems = rhs.numItems;
    for (int i = 0; i < numItems; i++) {
        data[i] = rhs.data[i];
    }
    return *this;
}

template <class T>
void DynArray<T>::resize(int newSize) {
    int *temp = new T[newSize];
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

template <class T>
void DynArray<T>::push_back(T newValue) {
    if (numItems == totalCapacity) {
        resize(totalCapacity * 2); // double the space in the array if there is no more room in array to add
    }
    data[numItems++] = newValue;
}

template <class T>
T DynArray<T>::pop_back() {
    if (numItems == 0) {
        return data[0]; // return garbage value
    }
    numItems--;
    return data[numItems]; // return the item "popped"
}

/*
 * Templates allow you to define one function for multiple datatypes
 * so you don't need to redefine the same function for each type.
 *
 * Under the hood, C++ is actually creating multiple versions of the
 * function (i.e. one for int, one for double etc.) via generating
 * object information (i.e. object code). Templates abstracts that
 * away from the programmer so all we need to do is write one version.
 * That way if there is a logic error in our code, we only need to fix
 * in the Template.
 */

//void swap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//void swap(double& a, double& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//void swap(char& a, char& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}

template <class T>
int find(const DynArray<T> &v, T toFind) { // linear search Theta(n)
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == toFind) {
            return i;
        }
    }
    return -1;
}

template <class T>
void selectionSort(DynArray<T> &v) { // Theta(N^2)
    for (int i = 0; i < v.size(); ++i) {
        int min_index = i;
        for (int j = (i + 1) ; j < v.size(); ++j) {
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }
        mySwap(v[i], v[min_index]);
    }
}

template <class T>
int binarySearch(const DynArray<T> &v, T toFind, int start, int end) { // recursive function is Theta(log N)
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (v[mid] == toFind) {
        return mid;
    } else if (v[mid] < toFind) {
        return binarySearch(v, toFind, mid + 1, end);
    } else {
        return binarySearch(v, toFind, start, mid - 1);
    }
}

template <class T>
int binarySearch(const DynArray<T> &v, T toFind) {//v MUST be sorted. This is a "driver function" (aka wrapper function)
    return binarySearch(v, toFind, 0, v.size() - 1); //call to the other function
}

int main() {
    srand(time(nullptr));

    DynArray<int> a;
    for (int i = 0; i < 100; i++) {
        a.push_back(rand() % 1000);
    }

    /*
    int x = 5, y = 10;
    cout << "x: " << x << " y: " << y << endl;
    mySwap(x, y);
    cout << "x: " << x << " y: " << y << endl;

    double a = 5.5, b = 6.7;
    cout << "a: " << a << " b: " << b << endl;
    mySwap(a, b);
    cout << "a: " << a << " b: " << b << endl;
    */

//    We've effectively fully implemented the vector class with its templates!
    vector<int> int_vector; // vector is just a templated class!!!
    DynArray<string> d; // we instantiate the DynArray class with the same notation as instantiating a vector
    d.push_back("Lawrence");
    d.push_back("Michael");

    DynArray<int> grades;
    grades.push_back(85);
    grades.push_back(100);
    grades.push_back(76);

    return 0;
}
