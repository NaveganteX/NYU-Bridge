#include <iostream>
using namespace std;

template <class T>
class LListNode;

template <class T>
class LList {
    LListNode<T> *head; // the only item stored in a LL class is a pointer to the first node in the list
    LListNode<T> *recursiveCopy(LListNode<T> *rhs);

public:
    LList() : head(nullptr) {}
    // copy constructor
    LList(const LList &rhs) : head(nullptr) { *this = rhs; }
    // assignment operator
    LList<T>& operator=(const LList<T> &rhs);
    //destructor
    ~LList() { clear(); }

    void insertAtHead(T new_data);
    T removeFromHead();
    bool isEmpty() const { return head == nullptr; }

    // clear() will throw away all the data in the List
    void clear();
    void insertAtEnd(T new_data);
    void insertAtPoint(LListNode<T> *ptr, T new_data);
    int size() const;
};

template <class T>
void LList<T>::insertAtEnd(T new_data) {
    if (isEmpty()) {
        insertAtHead(new_data);
        return;
    }

    // create a node with new_data
    LListNode<T> *temp = new LListNode<T>(new_data);
    // set end ptr to head of current LList (the pointer to the first node in the list)
    LListNode<T> *end = head;

    // while there is a node after the current node, assign the end ptr to the next node's next ptr
    while (end->next != nullptr) {
        end = end->next;
    }
    // assign the lists' last node's next ptr to the new node we want to insert into the end
    end->next = temp;
}

template <class T>
int LList<T>::size() const {
    int count = 0;
    LListNode<T> *temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
class LListNode {
    T data; // "data" is the item of type T that is stored
    LListNode<T> *next; // "*next" is a pointer to the next node in the linked list

public:
    // T new_data = T() creates a default
    explicit LListNode(T new_data = T(), LListNode<T> *new_next = nullptr) :
    data(new_data), next(new_next) {}

    friend class LList<T>;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
