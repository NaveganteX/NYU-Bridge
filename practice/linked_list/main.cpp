#include <iostream>
using namespace std;

template <class T>
class LList {
    LListNode<T> *head; // the only item stored in a LL class is a pointer to the first node in the list
    LListNode<T> *recursiveCopy(LListNode<T> *rhs);

public:
    LList() : head(nullptr) {}
    LList(const LList &rhs) : head(nullptr) { *this = rhs; }
    LList<T>& operator=(const LList<T> &rhs);
    ~LList() { clear(); }

    void insertAtHead(T new_data);
    T removeFromHead();
    bool isEmpty() const { return head == nullptr; }
    void clear();
    void insertAtEnd(T new_data);

    void insertAtPoint(LListNode<T> *ptr, T new_data);
    int size() const;
};

template <class T>
class LListNode {
    T data; // "data" is the item of type T that is stored
    LListNode<T> *next; // "*next" is a pointer to the next node in the linked list

public:
    explicit LListNode(T new_data = T(), LListNode<T> *new_next = nullptr) :
    data(new_data), next(new_next) {}

    friend class LList<T>;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
