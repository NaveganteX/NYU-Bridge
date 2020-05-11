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
    BSTNode<T> *root;
public:
    void printInOrder(BSTNode<T> *node);
    void printPreOrder(BSTNode<T> *node);
    void printPostOrder(BSTNode<T> *node);
    void printLevelOrder(BSTNode<T> *node);
    void insert(T item);
    void remove(BSTNode<T> *&temp);
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
    queue< BSTNode<T> > q;
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

/* 
insert() finds the last node and assigns the item to the po
 */
template <class T> 
void BST<T>::insert(T item) {
    if (root == nullptr) {
        root = new BSTNode<T>(item);
        return;
    }

    BSTNode<T> *temp = root;
    BSTNode<T> *prev = root;

    while (temp != nullptr) { // if you have not reached end then set prev to current temp
        prev = temp;
        if (item < temp->data) { // advance temp depending on the value of left/right node
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    // when temp ptr is null (when above while loop cond is false), then prev == the last node
    if (item < prev->data) { // determine which child node to insert into
        prev->left = new BSTNode<T>(item, prev);
    } else {
        prev->right = new BSTNode<T>(item, prev);
    }
}

template <class T>
void BST<T>::remove(BSTNode<T> *&temp) {
    // no children node
    BSTNode<T> *parent = temp->prev;
    if (temp->left == nullptr && temp->right == nullptr) {
    // will need to determine if this the root, left of right of parent
        if (parent == nullptr) { // last node on the tree
            root = nullptr;
        }
        else if (parent->left == temp) {
            parent->left == nullptr;
        }
        else {
            parent->right = nullptr;
        }
        delete temp;
    }
    // one child - in each case we are promoting the value of the left/right child up and deleting the now empty 
    // child node. This has the effect of deleting the node we want
    else if (temp->left == nullptr) { // there is a right child but no left
        // promote temp->right
        BSTNode<T> *toDelete = temp->right;
        temp->data = toDelete->data;
        temp->left = toDelete->left;
        if (temp->left != nullptr) {
            temp->left->parent = temp;
        }
        temp->right = toDelete->right;
        if (temp->right != nullptr) {
            temp->right->parent = temp;
        }
        delete toDelete;
    }

    else if (temp->right == nullptr) { // there is a left but no right
        // promote the value of the left child up
        BSTNode<T> *toDelete = temp->left;
        temp->data = toDelete->data; // assign value of child to the node you want to delete
        temp->left = toDelete->left;
        if (temp->left != nullptr) {
            temp->left->parent = temp;
        }
        temp->right = toDelete->right;
        if (temp->right != nullptr) {
            temp->right->parent = temp;
        }
        delete toDelete;
    }
    // two child nodes - arbitrarily pick the left or right branch and go
    else {
        BSTNode<T> *min_of_right = temp->right;
        while (min_of_right->left != nullptr) {
            min_of_right = min_of_right->left;
        }
        temp->data = min_of_right->data;
        remove(min_of_right);
    }
}

int main() {
    cout << "Hello" << endl;
    return 0;
}

