#include <iostream>
#include "ucm_hidden.h"
#include <vector>
#include <bits/stdc++.h>

using namespace std;
string guessedWord;
char guessedLetter;
bool flag = true;
int limit = 0;
int correctGuessCount = 0;


int main() {

    vector<char> word;
    vector<char> letters;
    std::cin >> guessedWord;
    
    for (int i = 0; i < guessedWord.length(); i++){
        guessedWord[i] = toupper(guessedWord[i]);
    }

    for (int x = 0; x < guessedWord.length(); x++){
        word.insert(word.end(), guessedWord[x]);
    }

    int size = word.size();
    char key[size];
    fill(key, key + size, '_');
    while (flag == true){
        cout << "Enter a letter: ";
        std::cin >> guessedLetter;

        if(cin.eof()){
            cout << "" << endl;
            cout << "\nBetter luck next time!\n";
            cout << "The word was: " << guessedWord << endl;
            return 0;
        }
        guessedLetter = toupper(guessedLetter);
        letters.push_back(guessedLetter);
        for (int x = 0; x < guessedWord.length(); x++){
            if (guessedLetter == word.at(x)){
                key[x] = guessedLetter;
                std::cout << key[x];
                limit++;
            }
            else if (guessedLetter != key[x] && key[x] != '_'){
                std::cout << key[x];
            }
            else {
                std::cout << "_";
            }
            std::cout << " ";
        }
        for (int x= 0; x < letters.size(); x++){
            // std::cout << letters.at(x);
        }
        std:: cout << "" << endl;

        if (limit != word.size()){
        std::cout << "\n" << "Letters: ";
        for (int x = 0; x < letters.size(); x++){
            // std::cout << letters.at(x);
            cout << letters[x];
            if (x != letters.size() - 1){
                cout << ", ";
            }
            
        }
        }
        std::cout << "\n";
        if (limit == word.size()){
            cout << "Great job!" << endl;
            flag = false;
        }
    }

    return 0;
}