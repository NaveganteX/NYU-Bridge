#include <iostream>
#include <queue>
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

template <class T>
class BST {
public:
    void printInOrder(BSTNode<T> *node);
    void printPreOrder(BSTNode<T> *node);
    void printPostOrder(BSTNode<T> *node);
    void printLevelOrder(BSTNode<T> *node);
    void insert(T item);
};

/*
in-, pre- and post- order traversals differ in the order at which a node is traversed
inOrder = traversal is from the left node, parent node then right node
preOrder = traversal is from parent node, left node then right node
postOrder = traversal is from left node, right node then parent node
*/

template <class T>
void BST<T>::printInOrder(BSTNode<T> *node) {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->data << ",";
        printInOrder(node->right);
    }
}

template <class T>
void BST<T>::printPreOrder(BSTNode<T> *node) {
    if (node != nullptr) {
        cout << node->data << ",";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}

template <class T>
void BST<T>::printPostOrder(BSTNode<T> *node) {
    if (node != nullptr) {
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << node->data << ",";
    }
}

/* 
Level-Order traversal goes through each level starting from the root node to each child then to each childs children

A queue is used to store each pointer to a node. The left child node is processed and if it has children, those nodes
are processed AFTER the right child node.
 */
template <class T>
void BST<T>::printLevelOrder(BSTNode<T> *node) {
    queue<BSTNode<T>> *q;
    q.push(node);
    while (!q.empty()) {
        BSTNode<T> *temp = q.front(); // assign a temp ptr to the first node in the queue
        q.pop(); // remove the node from the queue
        cout << temp->data << ",";
        if (temp->left != nullptr) { // if the current node has a left child, add it to the queue
            q.push(temp->left);
        }
        if (temp->right != nullptr) { // if the current node has a right child, add it to the queue
            q.push(temp->right);
        }
    }
}

template <class T> 
void BST<T>::insert(T item) {
    if (root == nullptr) {
        root = new BSTNode<T>(item);
        return;
    }
    BSTNode<T> *temp = root;
    BSTNode<T> *prev = root;
    while (temp != nullptr) {
        prev = temp;
        if (item < temp->data) { // t
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    if (item < prev->data) {
        prev->left = new BSTNode<T>(item, prev);
    } else {
        prev->right = new BSTNode<T>(item, prev);
    }
}

int main() {
    cout << "Hello" << endl;
    return 0;
}

