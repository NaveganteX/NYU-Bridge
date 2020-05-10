#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class T>
class LList; //Pre-Definition to make Friend work in LListNode

template <class T>
class LListNode {
    T data;
    LListNode<T>* next;
    LListNode<T>* prev;
public:
    LListNode(const T& newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) :data(newdata), next(newnext), prev(newprev) {}
    friend class LList<T>;
};

template <class T>
class LList {
    LListNode<T>* head;
    LListNode<T>* tail;

public:
    LList();
    ~LList();
    LList(const LList<T>& rhs);
    LList<T>& operator=(const LList<T>& rhs);

    void clear() { while (!isEmpty()) pop_front(); }
    void push_back(const T& data) { tail->prev = new LListNode(data, tail, tail->prev); tail->prev->prev->next = tail->prev; }
    void push_front(const T& data) { head->next = new LListNode(data, head->next, head);  head->next->next->prev = head->next; }
    T pop_back();
    T pop_front();
    int size();
    bool isEmpty() { return head->next == tail; }
};
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
    if (this == &rhs)
        return *this;
    clear();
    LListNode<T>* ptr = rhs.head->next;
    while (ptr != rhs.tail) {
        push_back(ptr->data);
    }
    return *this;
}
template <class T>
int LList<T>::size() {
    LListNode<T>* ptr = head->next;
    int count = 0;
    while (ptr != tail) {
        count++;
        ptr = ptr->next;
    }
    return count;
}
template <class T>
T LList<T>::pop_back() {
    if (tail->prev == head) //empty list!
        return T(); //not sure what to do here?  User did something dumb.
    T retval = tail->prev->data;
    LListNode<T>* nodeToDelete = tail->prev;
    tail->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    delete nodeToDelete;
    return retval;
}
template <class T>
T LList<T>::pop_front() {
    if (tail->prev == head) //empty list!
        return T(); //not sure what to do here?  User did something dumb.
    T retval = head->next->data;
    LListNode<T>* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    head->next->prev = head;
    delete nodeToDelete;
    return retval;
}
template <class T>
LList<T>::~LList() {
    clear();
    delete head;
    delete tail;
}
template <class T>
LList<T>::LList(const LList<T>& rhs) {
    head = new LListNode();
    tail = new LListNode();
    head->next = tail;
    tail->prev = head;
    *this = rhs; //call to the assignment operator!!!
}
template <class T>
LList<T>::LList() { //build two nodes, as "Dummies" for teh sake of making things easier
    head = new LListNode();
    tail = new LListNode();
    head->next = tail;
    tail->prev = head;
}