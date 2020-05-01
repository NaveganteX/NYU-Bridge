#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class LListNode;

class Employee;

template <class T>
class LList {
    LListNode<T> *head;
    LListNode<T> *recursiveCopy(LListNode<T> *rhs);

public:
    LList() : head(nullptr) {}
    LList(const LList &rhs) : head(nullptr) { *this = rhs; }
    LList<T>& operator=(const LList<T> &rhs);
//    ~LList() { clear(); }

    void insertAtHead(T new_data);
    T removeFromHead();
    bool isEmpty() const { return head == nullptr; }
    void clear();
    void insertAtEnd(T new_data);
    void insertAtPoint(LListNode<T> *ptr, T new_data);
    void updateHoursWorked(int employeeID, int hours_worked);
//    T popFront();
    int size() const;
    void printInfo() const;
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

//template <class T>
//T LList<T>::popFront() {
//    if (head->next == nullptr)
//        return T();
//    T retval = head->next->data;
//    LListNode<T>* nodeToDelete = head->next;
//    head->next = nodeToDelete->next;
//    head->next = head;
//    delete nodeToDelete;
//    return retval;
//}

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
void LList<T>::printInfo() const {
    int count = 0;
    LListNode<T> *temp = head;
    while (temp != nullptr) {
        cout << "Employee ID: " << temp->data.getEmployeeID() << endl;
        cout << "Employee Name: " << temp->data.getEmployeeName() << endl;
        cout << "Employee Pay Rate: " << temp->data.getHourlyPayRate() << endl;
        cout << "Employee Total Pay: " << temp->data.getTotalPay() << endl;
        cout << endl;
        temp = temp->next;
    }
}

template <class T>
void LList<T>::updateHoursWorked(int employeeID, int hours_worked) {
    LListNode<T> *temp = head;
    while (temp != nullptr) {
        if (temp->data.getEmployeeID() == employeeID) {
            temp->data.setHoursWorked(hours_worked);
            return;
        }
        temp = temp->next;
    }
}

//template <class T>
//void LList<T>::clear() {
//    while (isEmpty()) {
//        popFront();
//    }
//}

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
    T data;
    LListNode<T> *next;

public:
    explicit LListNode(T new_data = T(), LListNode<T> *new_next = nullptr) :
            data(new_data), next(new_next) {}
    T getData() { return data; }
    friend class LList<T>;
};

class Employee {
    string name;
    int id_num;
    int hours_worked = 0;
    double hourly_pay_rate;

public:
    Employee(string input_name, int input_id_num, double input_hourly_pay_rate) :
        id_num(input_id_num), name(input_name), hourly_pay_rate(input_hourly_pay_rate) {}

    Employee();

    string getEmployeeName() { return name; }
    int getEmployeeID() { return id_num; }
    double getHourlyPayRate() { return hourly_pay_rate; }
    int getHoursWorked() { return hours_worked; }
    void setHoursWorked(int input_hours_worked) { hours_worked = hours_worked + input_hours_worked; }
    double getTotalPay() {
        return hours_worked * hourly_pay_rate;
    }

};

void openInputFile(ifstream &inFile) {
    string filename;
    cout << "What filename would you like to open?" << endl;
    cin >> filename;
    inFile.open(filename);

    while (!inFile) {
        cout << "FILE FAILED TO OPEN!" << endl;
        cout << "What filename would you like to open?" << endl;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

int main() {
    vector<Employee> employee_vector; // to be converted to linked list later

    ifstream employee_data_file;
    openInputFile(employee_data_file);

    int temp_id;
    double temp_hourly_rate;
    string temp_name;

    LList<Employee> employee_list;
    while (employee_data_file >> temp_id) {
        employee_data_file >> temp_hourly_rate;
        employee_data_file.ignore(9999, '\t');
        getline(employee_data_file, temp_name);
        Employee temp_employee(temp_name, temp_id, temp_hourly_rate);
        employee_list.insertAtEnd(temp_employee);
    }

    ifstream employee_payroll_file;
    openInputFile(employee_payroll_file);

    int temp_hours_worked;
    LListNode<Employee> *head_ptr = nullptr;
    while (employee_payroll_file >> temp_id) {
        employee_payroll_file >> temp_hours_worked;
        // loop through linked list and find the employee with matching ID and assign temp_hours_worked
        employee_list.updateHoursWorked(temp_id, temp_hours_worked);
    }
        employee_list.printInfo();

    return 0;
}

/*
 * 1. read in data
 * 2. take data and create Employee objects
 * 3. store objects in linked list
 *
 * 4. traverse the linked list
 *
 */
