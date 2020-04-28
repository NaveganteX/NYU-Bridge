#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Employee {
    string name;
    int id_num;
    double hourly_pay_rate;
    int hours_worked;

public:
    Employee(string input_name, int input_id_num, double input_hourly_pay_rate) :
        id_num(input_id_num), name(input_name), hourly_pay_rate(input_hourly_pay_rate) {}

    Employee();

    string getEmployeeName() { return name; }
    int getEmployeeID() { return id_num; }
    double getHourlyPayRate() { return hourly_pay_rate; }
    int getHoursWorked() { return hours_worked; }
    void setHoursWorked(int input_hours_worked) { hours_worked = input_hours_worked; }

//    istream& operator >>(istream& ins, Employee& id) {
//
//    }
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

    while (employee_data_file >> temp_name) {
        cout << temp_name << " " << endl;
    }

    return 0;
}

/*
 * 1. read in data
 * 2. take data and create Employee objects
 * 3. store objects in linked list
 */
