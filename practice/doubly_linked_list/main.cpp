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
};

template <class T>
class DLLItr {
    DLLNode<T> *ptr;
public:
    DLLItr() { ptr = nullptr; }
};

template <class T>
class DLL {
    DLLNode<T> *head;
    DLLNode<T> *tail;
public:
    DLL();
    void insertAtEnd(T new_data);

    // *point is the ptr to the node you want to insert new node after
    // i.e. you want to insert a new node after *point
    void insertAfter(T new_data, DLLNode<T> *point);

    void swapData(DLLNode<T> *left, DLLNode<T> *right);
};

template <class T>
void DLL<T>::insertAtEnd(T new_data) {
    // insert after the dummy node (i.e. after the tail)
    insertAfter(new_data, tail->prev);
}

template <class T>
void DLL<T>::insertAfter(T new_data, DLLNode<T> *point) {
    DLLNode<T> *temp = new DLLNode<T>(new_data, point, point->next);
    point->next = temp;
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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
