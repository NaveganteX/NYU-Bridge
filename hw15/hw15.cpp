
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class LListNode;

//class Employee;

template <class T>
class LList {
    LListNode<T> *head;
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
    void updateHoursWorked(int employeeID, int hours_worked);
    int size() const;
    vector<T> outputToVector();
    void printInfo() const;
    bool isEmpty() { return head == nullptr; }
};

template <class T>
void LList<T>::insertAtHead(T new_data) {
    LListNode<T> *new_node = new LListNode<T>(new_data);
    new_node->next = head;
    head = new_node;
}

template <class T>
void LList<T>::insertAtEnd(T new_data) {
    if (isEmpty()) {
        insertAtHead(new_data);
        return;
    }
    LListNode<T> *temp = new LListNode<T>(new_data);
    LListNode<T> *end = head;
    while (end->next != nullptr) {
        end = end->next;
    }
    end->next = temp;
}

template <class T>
void LList<T>::insertAtPoint(LListNode<T> *ptr, T new_data) {
    LListNode<T> *new_node = new LListNode<T>(new_data);
    new_node->next = ptr->next;
    ptr->next = new_node;
}

template <class T>
T LList<T>::removeFromHead() {
    LListNode<T> *temp = head;
    head = head->next;
    return temp->data;
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

template <class T>
void LList<T>::clear() {
    LListNode<T> *temp = head;
    LListNode<T> *ptr = head;
    while (ptr != nullptr) {
        temp = ptr->next;
        delete ptr;
        ptr = temp;
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
    Employee(string input_name, int input_id_num, double input_hourly_pay_rate) : id_num(input_id_num), name(input_name), hourly_pay_rate(input_hourly_pay_rate) {}
    Employee() = default;

    string getEmployeeName() { return name; }
    int getEmployeeID() { return id_num; }
    double getHourlyPayRate() { return hourly_pay_rate; }
    int getHoursWorked() { return hours_worked; }
    void setHoursWorked(int input_hours_worked) { hours_worked = hours_worked + input_hours_worked; }
    double getTotalPay() {
        return hours_worked * hourly_pay_rate;
    }
};

void printInfo(vector<Employee> employee_vector) {
    cout << endl;
    cout << "******** Payroll Information *******" << endl;
    for (int i = 0; i < employee_vector.size(); ++i) {
        cout << employee_vector[i].getEmployeeName() << ", $" << employee_vector[i].getTotalPay() << endl;
    }
    cout << "*********** End Payroll ************" << endl;
}

template <class T>
vector<T> LList<T>::outputToVector() {
    LListNode<T> *head_ptr = head;
    vector<T> output_vector;
    while (head_ptr != nullptr) {
        output_vector.push_back(head_ptr->data);
        head_ptr = head_ptr->next;
    }
    return output_vector;
}

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

void merge(vector<Employee> &employee_vector, vector<Employee> &temp, int left, int middle, int right) {
    vector<Employee> left_vector;
    vector<Employee> right_vector;
    int left_position = left;
    int right_position = middle + 1;
    int temp_pos = left;

    while (left_position <= middle && right_position <= right){
        if (employee_vector[left_position].getTotalPay() > employee_vector[right_position].getTotalPay())
            temp[temp_pos++] = employee_vector[left_position++];
        else
            temp[temp_pos++] = employee_vector[right_position++];
    }

    while (left_position <= middle){
        temp[temp_pos++] = employee_vector[left_position++];
    }
    while (right_position <= right) {
        temp[temp_pos++] = employee_vector[right_position++];
    }

    for (int i = left; i <= right; i++) {
        employee_vector[i] = temp[i];
    }
}

void mergeSort(vector<Employee> &employee_vector, vector<Employee> &temp, int left, int right) {
    if (left < right) {
        int middle =  (left + right) / 2;
        mergeSort(employee_vector, temp, left, middle);
        mergeSort(employee_vector, temp, middle + 1, right);
        merge(employee_vector, temp, left, middle, right);
    }
}

void mergeSort(vector<Employee> &employee_vector) {
    int left = 0;
    int right = employee_vector.size();
    Employee temp_employee;
    vector<Employee> temp;
    temp.push_back(temp_employee);
    temp.resize(employee_vector.size());
    mergeSort(employee_vector, temp, left, right);
}

int main() {
    ifstream employee_data_file;
    openInputFile(employee_data_file);

    int temp_id;
    double temp_hourly_rate;
    string temp_name;

    LList<Employee> employee_list;
    while (employee_data_file >> temp_id) {
        employee_data_file >> temp_hourly_rate;
        employee_data_file.ignore(9999, ' ');
        getline(employee_data_file, temp_name);
        Employee temp_employee(temp_name, temp_id, temp_hourly_rate);
        employee_list.insertAtEnd(temp_employee);
    }

    ifstream employee_payroll_file;
    openInputFile(employee_payroll_file);

    int temp_hours_worked;
    while (employee_payroll_file >> temp_id) {
        employee_payroll_file >> temp_hours_worked;
        employee_list.updateHoursWorked(temp_id, temp_hours_worked);
    }

    vector<Employee> employee_vector;
    employee_vector = employee_list.outputToVector();
    mergeSort(employee_vector);
    printInfo(employee_vector);
    return 0;
}