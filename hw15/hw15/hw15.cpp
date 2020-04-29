#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
class LListNode {
    T data;
    LListNode<T> *next;

public:
    explicit LListNode(T new_data = T(), LListNode<T> *new_next = nullptr) : data(new_data), next(new_next)
};

class Employee {
    string name;
    int id_num;
    int hours_worked;
    double hourly_pay_rate;

public:
    Employee(string input_name, int input_id_num, double input_hourly_pay_rate) :
        id_num(input_id_num), name(input_name), hourly_pay_rate(input_hourly_pay_rate) {}

    Employee();

    string getEmployeeName() { return name; }
    int getEmployeeID() { return id_num; }
    double getHourlyPayRate() { return hourly_pay_rate; }
    int getHoursWorked() { return hours_worked; }
    void setHoursWorked(int input_hours_worked) { hours_worked = input_hours_worked; }
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

    while (employee_data_file >> temp_id) {
        employee_data_file >> temp_hourly_rate;
        employee_data_file.ignore(9999, '\t');
        getline(employee_data_file, temp_name);

        Employee temp_employee(temp_name, temp_id, temp_hourly_rate);
        employee_vector.push_back(temp_employee);
    }

    ifstream employee_payroll_file;
    openInputFile(employee_payroll_file);

    int temp_hours_worked;
    while (employee_payroll_file >> temp_id) {
        employee_payroll_file >> temp_hours_worked;
        // loop through linked list and find the employee with matching ID and assign temp_hours_worked
    }

    for (int i = 0; i < employee_vector.size(); ++i) {
        cout << employee_vector[i].getEmployeeID() << endl;
        cout << employee_vector[i].getHourlyPayRate() << endl;
        cout << employee_vector[i].getEmployeeName() << endl;
        cout << endl;
    }

    return 0;
}

/*
 * 1. read in data
 * 2. take data and create Employee objects
 * 3. store objects in linked list
 */
