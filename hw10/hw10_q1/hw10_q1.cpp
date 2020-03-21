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

    for (int i = 0; i < wordsArrSize; i++) {
        if (i == (wordsArrSize - 1)) {
            cout << wordsArray[i];
        } else {
            cout << wordsArray[i] << ", ";
        }
    }

    cout << endl;
    cout << "New array size: " << wordsArrSize << endl;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    string *tempStringArray;
    string tempWord = "";
    int tempStringArrayCounter = 0, tempOutWordsArrSize = 1;

    for (int i = 0; i < sentence.length(); i++) {
        if ((i != 0) && (sentence[i] == 32)) {
            tempOutWordsArrSize += 1;
        }
    }

    tempStringArray = new string[tempOutWordsArrSize];

    for (int i = 0; i < sentence.length(); i++) {
        int letter = sentence[i];
        if (((letter >= 65) && (letter <= 90)) || ((letter >= 97) && (letter <= 122)) || (letter == 39)) {
            if ((letter != 32) && (letter != 63) && (letter != 46)) {
                tempWord += letter;
            }
        } else {
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

    outWordsArrSize = tempOutWordsArrSize;
    return tempStringArray;
}


