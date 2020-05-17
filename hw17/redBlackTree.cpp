// Given the attached code for an RedBlackTree tree.
// Modify the code to implement a red-black tree.
// You do NOT need to implement removals!
#include <iostream>
#include <ctime>
#include <queue>
#include <string>

using namespace std;

template <class T>
class RedBlackTree;

template <class T>
T& max(T& left, T& right){
    if (left > right)
        return left;
    else
        return right;

}
template <class T>
T max(const T& left, const T& right){
    if (left > right)
        return left;
    else
        return right;

}

template <class T>
class RedBlackNode{
    RedBlackNode<T>* parent, *left, *right;
    int height;
    T data;
    string color;
public:
    friend class RedBlackTree < T > ;
    RedBlackNode(const T& newdata = T(),
            RedBlackNode<T>* newparent = nullptr,
            RedBlackNode<T>* newleft = nullptr,
            RedBlackNode<T>* newright = nullptr, string newColor = "red") :
            data(newdata), parent(newparent), left(newleft), right(newright), color(newColor) {
        calcHeight();
    }
    void calcHeight(){
        int leftHeight = -1;
        int rightHeight = -1;
        if (left != nullptr)
            leftHeight = left->height;
        if (right != nullptr)
            rightHeight = right->height;
        height = max(leftHeight, rightHeight) + 1;
        if (parent) //Update all parent heights also
            parent->calcHeight();
    }
    void printInOrder()const{
        if (left != nullptr)
            left->printInOrder();
        cout << data <<"\t"<<height<< endl;
        if (right != nullptr)
            right->printInOrder();
    }
    void printPostOrder()const;
    int size()const{
        int leftSize = 0;
        int rightSize = 0;
        if (left != nullptr)
            leftSize = left->size();
        if (right != nullptr)
            rightSize = right->size();
        return 1 + leftSize + rightSize;
    }
    /*	int height()const{
            int leftSize = -1;
            int rightSize = -1;
            if (left != nullptr)
            leftSize = left->height();
            if (right != nullptr)
            rightSize = right->height();
            return 1 + max(leftSize, rightSize);
            }*/
    int depth() const{
        int parentDepth = -1;
        if (parent != nullptr)
            parentDepth = parent->depth();
        return 1 + parentDepth;
    }
};

template <class T>
void RedBlackNode<T>::printPostOrder()const{
    if (left != nullptr)
        left->printInOrder();
    if (right != nullptr)
        right->printInOrder();
    cout << data << endl;
}

template <class T>
class RedBlackTree{
    RedBlackNode<T>* root;
    int size;
    RedBlackNode<T>* recursiveCopy(RedBlackNode<T>* toCopy);
    void singleCCR(RedBlackNode<T>*& point);
    void doubleCR(RedBlackNode<T>*& point);
    void singleCR(RedBlackNode<T>*& point);
    void doubleCCR(RedBlackNode<T>*& point);
    int heightDiff(RedBlackNode<T>* point);
    void doRotation(RedBlackNode<T>* point);
public:
    RedBlackTree() :size(0){ root = nullptr; }

    //memory on the heap so.... here comes the big 3!
    RedBlackTree(const RedBlackTree<T>& rhs) :root(nullptr){ *this = rhs; }
    virtual ~RedBlackTree(){ clear(); }
    RedBlackTree& operator=(const RedBlackTree<T>& rhs);

    bool isInTree(const T& toFind) const{ return find(toFind) != nullptr; }
    bool isEmpty()const{ return root == nullptr; }
    int getSize()const { return size; }
    void remove(const T& toRemove){
        RedBlackNode<T>* item = find(toRemove);
        if (item != nullptr)
            remove(item);
    }
    void insert(const T&);
    void insert(const T&, RedBlackNode<T>*& point);
    void remove(RedBlackNode<T>*);
    RedBlackNode<T>* find(const T& toFind) const;
    void clear(){ while (!isEmpty()) remove(root); }
    void printInOrder()const{ root->printInOrder(); }
    void printPostOrder()const{ root->printPostOrder(); }
    void printLevelOrder()const;
    void rebalance(RedBlackNode<T>*& point);
    void recolor(RedBlackNode<T>*& point);
};

template <class T>
void RedBlackTree<T>::printLevelOrder() const{
    queue<RedBlackNode<T>*> q;
    q.push(root);
    while (!q.empty()){
        RedBlackNode<T>* front = q.front();
        cout << front->data << "\t" << front->color << endl;
        if (front->left!=nullptr)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
        q.pop();
    }
}
template <class T>
void RedBlackTree<T>::doubleCCR(RedBlackNode<T>*& point){
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RedBlackTree<T>::doubleCR(RedBlackNode<T>*& point){
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RedBlackTree<T>::singleCR(RedBlackNode<T>*& point){
    RedBlackNode<T>* grandparent = point;
    RedBlackNode<T>* parent = point->left;
    parent->parent = grandparent->parent;
    grandparent->parent = parent;
    grandparent->left = parent->right;
    parent->right = grandparent;
    if (grandparent->left != nullptr) //if we now have a left child, update its parent pointer
        grandparent->left->parent = grandparent;
    if (parent->parent == nullptr)//if we were the root, update the root!
        root = parent;
    else if (parent->parent->left == grandparent)
        parent->parent->left = parent;
    else
        parent->parent->right = parent;
    grandparent->calcHeight();
    parent->calcHeight();
}

template <class T>
void RedBlackTree<T>::singleCCR(RedBlackNode<T>*& point){
    RedBlackNode<T>* grandparent = point;
    RedBlackNode<T>* parent = point->right;
    parent->parent = grandparent->parent;
    grandparent->parent = parent;
    grandparent->right = parent->left;
    parent->left = grandparent;
    if (grandparent->right != nullptr) //if we now have a right child, update its parent pointer
        grandparent->right->parent = grandparent;
    if (parent->parent == nullptr)//if we were the root, update the root!
        root = parent;
    else if (parent->parent->right == grandparent)
        parent->parent->right = parent;
    else
        parent->parent->left = parent;
    grandparent->calcHeight();
    parent->calcHeight();
}

template <class T>
RedBlackNode<T>* RedBlackTree<T>::recursiveCopy(RedBlackNode<T>* toCopy){
    if (toCopy == nullptr)
        return nullptr;
    RedBlackNode<T>* temp = new RedBlackNode<T>(toCopy->data, nullptr, recursiveCopy(toCopy->left), recursiveCopy(toCopy->right));
    if (temp->left != nullptr)
        temp->left->parent = temp;
    if (temp->right != nullptr)
        temp->right->parent = temp;
    return temp;
}

template <class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree<T>& rhs){
    if (this == &rhs)
        return *this;
    clear();
    root = recursiveCopy(rhs.root);
    size = rhs.size;
    return *this;
}

template <class T>
void RedBlackTree<T>::remove(RedBlackNode<T>* toRemove){
    if (root == nullptr)
        return; //Remove from an empty tree????
    if (toRemove->left == nullptr && toRemove->right == nullptr){ //leaf node case
        if (toRemove->parent == nullptr){
            root = nullptr;
        }
        else if (toRemove == toRemove->parent->left) //left child!
            toRemove->parent->left = nullptr; //fix the parent's pointer!
        else
            toRemove->parent->right = nullptr;
        delete toRemove;
        size--;
    }
    else if (toRemove->right == nullptr){ //has one (left) child
        if (toRemove->parent == nullptr){
            root = toRemove->left;
            root->parent = nullptr;
        }
        else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
            toRemove->parent->left = toRemove->left;
            toRemove->left->parent = toRemove->parent;
        }
        else{
            toRemove->parent->right = toRemove->left;
            toRemove->left->parent = toRemove->parent;
        }
        delete toRemove;
        size--;
    }
    else if (toRemove->left == nullptr){ //has one right child, almost same solution as left child only
        if (toRemove->parent == nullptr){
            root = toRemove->right;
            root->parent = nullptr;
        }
        else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
            toRemove->parent->left = toRemove->right;
            toRemove->right->parent = toRemove->parent;
        }
        else{
            toRemove->parent->right = toRemove->right;
            toRemove->right->parent = toRemove->parent;
        }
        delete toRemove;
        size--;
    }
    else{ //sigh... two children!
        RedBlackNode<T>* temp = toRemove->right;
        while (temp->left != nullptr)
            temp = temp->left;
        toRemove->data = temp->data;
        remove(temp);
    }

}

template <class T>
RedBlackNode<T>* RedBlackTree<T>::find(const T& toFind) const{
    RedBlackNode<T>* temp = root;
    while (temp != nullptr && temp->data != toFind){
        if (toFind < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp;
}

/*
 * 1. insert node and color it red
 * 2. rebalance nodes to fix violation (either recolor or rotate)
 *
 * 1. black aunt -> rotate (after a rotation, you must fix color of nodes (parent is black children red))
 * 2. red aunt -> color flip
 */
template <class T>
void RedBlackTree<T>::insert(const T& toInsert, RedBlackNode<T>*& point){
    if (point==nullptr) {
        point = new RedBlackNode<T>(toInsert);
    }
    else if (toInsert < point->data){
        insert(toInsert, point->left);
        point->left->parent = point; //update parent pointer
        if (point->parent != nullptr) {
            rebalance(point->left);
        }
    }
    else {
        insert(toInsert, point->right);
        point->right->parent = point;
        if (point->parent != nullptr) {
            rebalance(point->right);
        }
    }
}

template <class T>
void RedBlackTree<T>::rebalance(RedBlackNode<T>*& inserted) {
    if (inserted->parent != nullptr) {
        if (inserted->parent->parent->left != nullptr) { // if inserted's uncle is on the left
            if (inserted->parent->parent->left->color == "red") { // if inserted's uncle is red, recolor nodes
                recolor(inserted);
            } else if (inserted->parent->parent->left->color == "black") { // if inserted's uncle is black, do a rotation
                doRotation(inserted);
            }
        } else if (inserted->parent->parent->right != nullptr) { // inserted's uncle is on the right
            if (inserted->parent->parent->right->color == "red") { // if inserted's uncle is red, recolor nodes
                recolor(inserted);
            } else if (inserted->parent->parent->right->color == "black") { // if inserted's uncle is black, do a rotation
                doRotation(inserted);
            }
        }
    }
}

template <class T>
void RedBlackTree<T>::recolor(RedBlackNode<T>*& point) {
        point->color = "black";
        point->parent->color = "red";
        point->parent->left->color = "black";
}

template <class T>
void RedBlackTree<T>::insert(const T& toInsert){
    insert(toInsert, root);
}
template <class T>
void RedBlackTree<T>::doRotation(RedBlackNode<T>* point){
    int leftChild = -1;
    int rightChild = -1;
    if (point->left != nullptr)
        leftChild = point->left->height;
    if (point->right != nullptr)
        rightChild = point->right->height;

    if (leftChild > rightChild){//CR, but is it single or double?
        int leftGC = -1;
        int rightGC = -1;
        if (point->left->left != nullptr)
            leftGC = point->left->left->height;
        if (point->left->right != nullptr)
            rightGC = point->left->right->height;
        if (leftGC > rightGC) // single rotation
            singleCR(point);
        else
            doubleCR(point);
    }
    else{//definitely a CCR, but which one?
        int leftGC = -1;
        int rightGC = -1;
        if (point->right->left != nullptr)
            leftGC = point->right->left->height;
        if (point->right->right != nullptr)
            rightGC = point->right->right->height;
        if (leftGC > rightGC) // double rotation
            doubleCCR(point);
        else
            singleCCR(point);
    }
}


template<class T>
int RedBlackTree<T>::heightDiff(RedBlackNode<T>* point){
    int leftHeight = -1;
    int rightHeight = -1;
    if (point->left != nullptr)
        leftHeight = point->left->height;
    if (point->right != nullptr)
        rightHeight = point->right->height;
    return (abs(leftHeight - rightHeight));
}


int main(){
    RedBlackTree<int> b;
    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        int val = rand() % 1000;
        b.insert(val);
    }
    b.printLevelOrder();
}