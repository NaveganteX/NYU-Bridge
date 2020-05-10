#include <iostream>
using namespace std;

template <class T>
class LListNode;

template <class T>
class LList {
    LListNode<T> *head; // the only item stored in a LL class is a pointer to the first node in the list
    LListNode<T> *recursiveCopy(LListNode<T> *rhs);
    /*
     * rhs is the right hand side node; recursiveCopy not only copies rhs but
     * all subsequent right hand side nodes
     */
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
    T popFront();
    int size() const;
    bool isEmpty() { return head == nullptr; }
};

template <class T>
void LList<T>::insertAtHead(T new_data) {
    // create new LListNode to rep data we want to insert at head
    LListNode<T> *new_node = new LListNode<T>(new_data);
    // point new_node's next ptr to head (the current first node)
    new_node->next = head;
    // point head node of list to node we just created (the new node we want to insert at head)
    head = new_node;
}

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
void LList<T>::insertAtPoint(LListNode<T> *ptr, T new_data) {
    LListNode<T> *new_node = new LListNode<T>(new_data);
    // have new node's next point to ptr's next
    new_node->next = ptr->next;
    // have previous node point to new_node;
    ptr->next = new_node;
}

template <class T>
T LList<T>::removeFromHead() {
    LListNode<T> *temp = head;
    head = head->next;
    return temp->data;
}

template <class T>
T LList<T>::popFront() {
    if (head->next == nullptr) //empty list!
        return T(); //not sure what to do here?  User did something dumb.
    T retval = head->next->data;
    LListNode<T>* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    head->next = head;
    delete nodeToDelete;
    return retval;
}

template <class T>
int LList<T>::size() const {
    int count = 0;
    LListNode<T> *temp = head;
    while (temp != nullptr) {
        count++;
        cout << temp->getData() << " ";
        temp = temp->next;
    }
    return count;
}

template <class T>
void LList<T>::clear() {
    while (isEmpty()) {
        popFront();
    }
}

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
LListNode<T>* LList<T>::recursiveCopy(LListNode<T> *rhs) {
    if (rhs == nullptr) {
        return nullptr;
    }
    return new LListNode<T>(rhs->data, recursiveCopy(rhs->next));
}

template <class T>
class LListNode {
    T data; // "data" is the item of type T that is stored
    LListNode<T> *next; // "*next" is a pointer to the next node in the linked list

public:
    // T new_data = T() creates a default
    explicit LListNode(T new_data = T(), LListNode<T> *new_next = nullptr) :
    data(new_data), next(new_next) {}
    T getData() { return data; }
    friend class LList<T>;
};

int main() {
    LList<int> linked_list;
    for (int i = 0; i < 10; ++i) {
        LListNode<int> temp_node(i);
        linked_list.insertAtEnd(temp_node);
    }

    linked_list.size();
    return 0;
}
