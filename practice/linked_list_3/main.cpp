#include <iostream>
#include <vector>
using namespace std;

template <class T>
class LList;

template <class T>
class LListNode {
    T data;
    LListNode<T> *next;
public:
    LListNode(T new_value =T(), LListNode<T> *new_next = nullptr) : data(new_value), next(new_next) {}
    friend class LList<T>;
};

template <class T>
class LList {
    LListNode<T> *head;
public:
    LList() : head(nullptr) {}
    void insert(T new_data);
    void print();
    void removeFromEnd();
};

template <class T>
void LList<T>::insert(T new_data) {
    LListNode<T> *new_node = new LListNode<T>(new_data);
    if (head == nullptr) {
        new_node->next = head;
        head = new_node;
    } else {
        LListNode<T> *end = head;
        while (end->next != nullptr) {
            end = end->next;
        }
        end->next = new_node;
    }
}

template <class T>
void LList<T>::removeFromEnd() {
    LListNode<T> *end = head;
    while (end->next->next != nullptr) {
        end = end->next;
    }
    end->next = nullptr;
}

template <class T>
void LList<T>::print() {
    LListNode<T> *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    LList<int> a;
    a.insert(3);
    a.insert(6);
    a.insert(9);
    a.removeFromEnd();
    a.print();
    return 0;
}
