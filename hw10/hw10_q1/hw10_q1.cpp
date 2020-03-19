#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    string sentence;
    string *wordsArray;
    int wordsArrSize = 0;

    cout << "Enter a sentence:" << endl;
    getline(cin, sentence);

    wordsArray = createWordsArray(sentence, wordsArrSize);
    cout << wordsArrSize << endl;

    for (int i = 0; i < wordsArrSize; i++) {
        cout << wordsArray[i] << ", ";
    }
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string *tempStringArray;
    string tempWord = "";
    int tempStringArrayCounter = 0, tempOutWordsArrSize = 1;

    for (int i = 0; i < sentence.length(); i++) {
        if (((sentence[i] <= 65) || (sentence[i] >= 90)) && ((sentence[i] <= 97) || (sentence[i] >= 122))) {
            if ( ((i != 0) && (sentence[i] != 32)) || (i == (sentence.length() - 1))) {
                tempOutWordsArrSize++;
            }
        }
    }

    cout << "tempOutWordsArrSize: " << tempOutWordsArrSize << endl;
    tempStringArray = new string[tempOutWordsArrSize];

    for (int i = 0; i <= sentence.length(); i++) {
        if (((sentence[i] >= 65) && (sentence[i] <= 90)) || ((sentence[i] >= 97) && (sentence[i] <= 122))) {
            if ((sentence[i] != 32) && (sentence[i] != 63) && (sentence[i] != 46)) {
                tempWord += sentence[i];
                cout << "tempWord: " << tempWord << endl;
            }
        } else {
            cout << "tempWord: " << tempWord << endl;
            tempStringArray[tempStringArrayCounter] = tempWord;
            tempStringArrayCounter++;
            tempWord = "";
        }

        if (i == (sentence.length() - 1)) {
            tempStringArray[tempStringArrayCounter] = tempWord;
            tempStringArrayCounter++;
            tempWord = "";
        }
    }

    cout << tempOutWordsArrSize << endl;
    outWordsArrSize = tempOutWordsArrSize;
    return tempStringArray;
}


