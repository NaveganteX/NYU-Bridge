#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openInputFile(ifstream &inFile) {
    string filename;
    cout << "What filename would you like to open?" << endl;
    cin >> filename;
    inFile.open(filename); // "connects" file to stream object

    while (!inFile) {
        cout << "FILE FAILED TO OPEN!" << endl;
        cout << "What filename would you like to open?" << endl;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

int main() {
    ifstream inFile; // create input stream
    openInputFile(inFile);
    int id;
    double rate;
    string name;

    while (inFile >> id) {
//        cout << "id: " << id << endl;
        inFile >> rate;
//        cout << "rate: " << rate << endl;
        inFile.ignore(9999, '\t');
        getline(inFile, name);
        cout << "name: " << name << endl;
    }
    return 0;
}