#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// openInputFile includes logic to check that opening file was successful
void openInputFile(ifstream &inFile) {
    string filename;
    cout << "What filename would you like to open?" << endl;
    cin >> filename;
    // opens the file named "filename"
    inFile.open(filename);

    // while loop verifies that the file did in fact open;
    // if file fails to open (i.e. wrong file name given etc.)
    // the while loop allows us to keep trying to open while checking if open succeeds
    while (!inFile) {
        cout << "FILE FAILED TO OPEN!" << endl;
        cout << "What filename would you like to open?" << endl;
        cin >> filename;
        // if the file failed to open previously ifstream object will have internal bool set to False
        // clearing that bool will allow that file to open the next time we try
        // must clear BEFORE trying again or else
        // the while loop condition is testing for a flag. If the second try is successful
        // the state will still be a fail flag from previous failure. So we have to clear that flag
        // before trying the next time.
        inFile.clear();
        inFile.open(filename);
    }
}

struct Student {
    int id;
    double test_score;
    string name;
};

int main() {
    // ofstream outFile("outFile.txt"); does same as next two lines in one line; o need for ".open"
    ofstream outFile;
    outFile.open("outFile.txt", ios::app); //ios::app appends input to end of outFile.txt instead of overwriting
    // writes "Hello, World!" to outFile
    outFile << "Hello, World!" << endl;

    ifstream inFile;
    openInputFile(inFile);
    // no simple way to read DIRECTLY into a vector, however, we can create a temporary object
    // of the datatype of the file (in this case an int) and read into
    // that temp object in a while loop
    vector<int> v;
    int temp;
    /*
     * conditional "inFile >> temp" checks to make sure we can continue reading into temp
     * if we can no longer read into (i.e. finished reading everything in the file and there is
     * no more ints to read in, the condition will fail and we will exit out of the loop.
     *
     * using the the input operator ">>" instead of .eof also allows us to check for leading
     * empty whitespaces or any other invalid characters and only read in valid characters
     * the condition will fail once we reach a trailing whitespace.
     *
     * input operator also skips over invalid objects depending on the datatype of "temp"
     * if temp is int, >> will skip doubles, strings etc.
     */
    while (inFile >> temp) {
        v.push_back(temp);
    }

    double sum = 0, average;
    for (int i : v) {
        sum += i;
    }

    average = sum / v.size();
    cout << "The average of the integers in this file is: " << average << endl;

    ifstream inFileStudentScores;
    openInputFile(inFileStudentScores);
    vector<Student> student_vector;
    Student temp_student;

    while (inFileStudentScores >> temp_student.id) {
        inFileStudentScores >> temp_student.test_score;
        // because the file stops at the end of the test score and because there is a tab
        // separating test scores and name we need to .ignore to ignore the tab space
        inFileStudentScores.ignore(9999, '\t');
        getline(inFileStudentScores, temp_student.name);
        student_vector.push_back(temp_student);
    }
    cout << "Students who scored above 70:" << endl;
    for (Student student : student_vector) {
        if (student.test_score > 70) {
            cout << student.name << " - (" << student.test_score << ")" << endl;
        }
    }
    return 0;
}
