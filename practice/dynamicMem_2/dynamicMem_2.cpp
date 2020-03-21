#include <iostream>
#include <string>
#include <vector>
using namespace std;

string* readLinesArray(int &outLinesArrSize);
string* readLinesArray2(int &outlinesArrSize);
vector<string> readLinesVector();
int main1();
int main2();

int main() {
    return main1();
}

int main1() {
    int numOfLines = 0;
    string *linesArray;
    int linesArraySize;

//    linesArray = readLinesArray(linesArraySize);
    linesArray = readLinesArray2(linesArraySize);

    cout << "Your text is: " << endl;
    for (int i = 0; i < linesArraySize; i++) {
        cout << i + 1 << ". " << linesArray[i] << endl;
    }

    delete[] linesArray;
    linesArray = nullptr;

    return 0;
}

int main2() {
    vector<string> linesVector;

    linesVector = readLinesVector();

    cout << "Your text is: " << endl;
    for (int i = 0; i < linesVector.size(); i++) {
        cout << i + 1 << ". " << linesVector[i] << endl;
    }

    return 0;
}

string* readLinesArray(int &outLinesArrSize) {
    string *linesArray;
    int linesArraySize = 0;

    cout << "Please enter number of lines:" << endl;
    cin >> linesArraySize;
    cin.ignore(1); // cin.ignore ensures getline in line37 does not consume cin's empty breakline character in line31
    linesArray = new string[linesArraySize];

    cout << "Please enter " << linesArraySize << " lines:" << endl;
    for (int i = 0; i < linesArraySize; i++) {
        getline(cin, linesArray[i]);
    }
    outLinesArrSize = linesArraySize;

    return linesArray;
}

string* readLinesArray2(int &outLinesArrSize) {
    string* linesArray;
    int linesArrayLogicalSize, linesArrayPhysicalSize;
    string currentLine;
    bool seenEmptyLine;
    cout << "Please enter a sequence of lines:" << endl;
    cout << "End your by typing an empty line." << endl;

    linesArray = new string[1];
    linesArrayPhysicalSize = 1;
    linesArrayLogicalSize = 0;

    seenEmptyLine = false;
    while (seenEmptyLine == false) {
        getline(cin, currentLine);
        if (currentLine == ""){
            seenEmptyLine = true;
        } else {
//            vector's push_back() member function handles the following if statement
            if (linesArrayLogicalSize == linesArrayPhysicalSize) {
                string *linesArrayTemp;
                linesArrayTemp = new string[linesArrayPhysicalSize * 2];
                for (int i = 0; i < linesArrayLogicalSize; i++) {
                    linesArrayTemp[i] = linesArray[i];
                }
                delete []linesArray;
                linesArray = linesArrayTemp;
                linesArrayPhysicalSize *= 2;
            }
            linesArray[linesArrayLogicalSize] = currentLine;
            linesArrayLogicalSize += 1;
        }
    }
    outLinesArrSize = linesArrayLogicalSize;
    return linesArray;
}

vector<string> readLinesVector() {
    vector<string> linesVector;
    bool seenEmptyLine;
    string currentLine;
    cout << "Please enter a sequence of lines:" << endl;
    cout << "End your by typing an empty line." << endl;

    seenEmptyLine = false;
    while (seenEmptyLine == false) {
        getline(cin, currentLine);
        if (currentLine == ""){
            seenEmptyLine = true;
        } else {
            linesVector.push_back(currentLine);
        }
    }
    return linesVector;
}