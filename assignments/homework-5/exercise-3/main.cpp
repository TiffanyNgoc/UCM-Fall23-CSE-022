#include <iostream>
#include <string>
#include "ucm_hidden.h"
#include <cctype>

using namespace std;

int main() {

    // HIDDEN_INPUT input;
    // string hiddenWord = input.get();
    // string completedWord;
    // completedWord = hiddenWord;

    // // Changes letters to uppercase
    // for (int i = 0; i < hiddenWord.length(); i++){
    //     hiddenWord[i] = toupper(hiddenWord[i]);
    // }

    // // Code before main
    // char attempt;
    // int count;

    // cout << "Enter a letter: ";
    // cin >> attempt;
    // attempt = toupper(attempt);

    // for (int i = 0; i < completedWord.length(); i++){
    //     cout << "_ ";
    // }
        
    // cout << "" << endl;
    // cout << "" << endl;

    // // Main Code
    // while (1 == 1) {
    //     if (count == hiddenWord.length()) {
    //         break;
    //     }

    //     cout << "Letters: " << endl;
    //     cout << "Enter a letter: ";
    //     cin >> attempt;
    //     attempt = toupper(attempt);

    //     // Underscores
    //     for (int i = 0; i < completedWord.length(); i++){
    //         completedWord[i] = '_';
    //     }
        
    //     // Spaces after underscores
    //     for (int i = 0; i < completedWord.length(); i++){
    //         cout << completedWord[i] << " ";
    //     }

    //     int pos = hiddenWord.find(attempt);
    //     while (pos!= -1) {
    //         completedWord.replace(pos,1,1,attempt);
    //         pos = hiddenWord.find(attempt, pos+1);
    //     }

    
    //     // if (attempt == completedWord[0]) {
    //     //     completedWord = attempt;
    //     //     cout << completedWord << endl;
    //     // }

    //     cout << "" << endl;
    //     cout << "" << endl;
    // }

    HIDDEN_INPUT input;
    string iLetters = "";
    string word = input.get();
    string underScores;
    
    for (int i = 0; i < word.length(); i++){
        word[i] = toupper(word[i]);
        underScores.append("_ ");
    }

    underScores.pop_back();

    int count = 0;
    char gLetter;
    cout << "\nEnter a letter: ";

    while (true){
        cin >> gLetter;

        if (cin.eof()) {
            cout << "\n\nBetter luck next time!" << endl;
            cout << "The word was: " << word << endl;
            break;
        }

        gLetter = toupper(gLetter);

        bool si = true;

        for (int i = 0; i < iLetters.length(); i++){
            if (gLetter == iLetters[i]) {
                si = false;
                break;
            }
        }
        if (si == false) {
            cout << underScores << endl;
            cout << endl;
            cout << "Letters: " << iLetters << endl;
            cout << "Enter a letter: ";
            continue;
        }

        for (int i = 0; i < word.length(); i++){
            if (word[i] == gLetter){
                underScores[i*2] = gLetter;
                count+= 1;
            if (count == word.length()){
                cout << underScores << endl;
                cout << endl;
                cout << "Great job!" << endl;
                return 1;
            }
            }
        }
        cout << underScores << endl;
        cout << endl;

        if (iLetters.length() > 0){
            iLetters += ", ";
            iLetters += gLetter;
            cout << "Letters: " << iLetters << endl;
        }
        else {
            iLetters += gLetter;
            cout << "Letters: " << iLetters << endl;
        }
        cout << "Enter a letter: ";
    }

    // if (cin.eof()){
    //     cout << "\n\nBetter luck next time!" << endl;
    //     cout << "The word was: " << word << endl;
    //     return 1;
    // }
    
    return 0;
}