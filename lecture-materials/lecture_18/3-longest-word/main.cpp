#include <iostream>
#include "ucm_strings.h"
using namespace std;

int main() {

    string text = "Welcome to the University of California-Berkeley";
    string word = longestWord(text);

    cout << "Longest word: " << word << endl;

    return 0;
}
