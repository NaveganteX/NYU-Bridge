#include <iostream>
using namespace std;

template <class T>
class DLL;

template <class T>
class DLLItr;

template <class T>
class DLLNode {
    T data;
    DLLNode<T> *prev;
    DLLNode<T> *next;
public:
    DLLNode(T new_data = T(), DLLNode<T> *new_prev = nullptr, DLLNode<T> *new_next = nullptr) :
        data(new_data), prev(new_prev), next(new_next) {}

    // DLL is a friend class of DLLNode so DLL can access private and protected members of DLLNode
    friend class DLL<T>;
    friend class DLLItr<T>;
};

template <class T>
class DLLItr {
    DLLNode<T> *ptr;
public:
    DLLItr() { ptr = nullptr; cout << "!"; }
    DLLItr(DLLNode<T> *new_ptr) : ptr(new_ptr) {}
    bool operator==(const DLLItr<T> &rhs) { return ptr == rhs.ptr; }
    bool operator!=(const DLLItr<T> &rhs) { return !(*this == rhs); }
    T operator*() const { return ptr->data; }
    T& operator*() { return ptr->data; }
    DLLItr& operator++();
    DLLItr operator++(int);
    DLLItr& operator--();
    DLLItr operator--(int);

    friend class DLL<T>;
};

template <class T>
DLLItr<T>& DLLItr<T>::operator++() {
    if (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    return *this;
}

template <class T>
DLLItr<T> DLLItr<T>::operator++(int) {
    DLLItr temp = *this;
    if (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    return temp;
}

template <class T>
DLLItr<T>& DLLItr<T>::operator--() {
    if (ptr->prev != nullptr) {
        ptr = ptr->prev;
    }
    return *this;
}

template <class T>
DLLItr<T> DLLItr<T>::operator--(int) {
    DLLItr temp = *this;
    if (ptr->prev != nullptr) {
        ptr = ptr->prev;
    }
    return temp;
}

template <class T>
class DLL {
    DLLNode<T> *head;
    DLLNode<T> *tail;
public:
    DLL();
    void insertAtEnd(T new_data);

    // *point is the ptr to the node you want to insert new node after
    // i.e. you want to insert a new node after *point
    void insertAfter(T new_data, DLLItr<T> point);

    void swapData(DLLNode<T> *left, DLLNode<T> *right);
    DLLItr<T> begin() { return head->next; }
    DLLItr<T> end() { return tail; }
};

template <class T>
void DLL<T>::insertAtEnd(T new_data) {
    // insert after the dummy node (i.e. after the tail)
    insertAfter(new_data, tail->prev);
}

template <class T>
void DLL<T>::insertAfter(T new_data, DLLItr<T> point) {
    DLLNode<T> *temp = new DLLNode<T>(new_data, point.ptr, point.ptr->next);
    point.ptr->next = temp;
    temp->next->prev = temp;
}

template <class T>
void DLL<T>::swapData(DLLNode<T> *left, DLLNode<T> *right) {
    T temp = left->data;
    left->data = right->data;
    right->data = temp;
}

// dummy node:
template <class T>
DLL<T>::DLL() {
    head = new DLLNode<T>(T(), nullptr, new DLLNode<T>);
    tail = head->next;
    tail->prev = head;
}

int main() {
    DLL<int> d;
    for (int i = 0; i < 10; ++i) {
        d.insertAtEnd(i);
    }

    DLLItr<int> x;
    x++;

    for (DLLItr<int> j = d.begin(); j != d.end(); ++j) {
//        cout << "!!" << endl;
        cout << *j;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
