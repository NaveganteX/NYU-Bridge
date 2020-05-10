#include <iostream>
using namespace std;

// forward declaration of BST class
template <class T>
class BST;

template <class T>
class BSTNode {
    T data;
    BSTNode<T> *parent;
    BSTNode<T> *left;
    BSTNode<T> *right;
public:
    BSTNode(T new_data = T(),
            BSTNode<T> *new_parent = nullptr,
            BSTNode<T> *new_left = nullptr,
            BSTNode<T> *new_right = nullptr)
            : data(new_data), parent(new_parent), left(new_left), right(new_right) {}

    friend class BST<T>; // BST class has access to BSTNode's private members
    int getSize() const;
};

template <class T>
int BSTNode<T>::getSize() const {
    int count = 1;
    if (left != nullptr) {
        count += left->getSize();
    }
    if (right != nullptr) {
        count += right->getSize();
    }
    return count;
}

int main() {
    return 0;
}

