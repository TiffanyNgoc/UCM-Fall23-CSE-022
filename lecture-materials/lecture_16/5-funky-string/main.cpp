#include <cctype>
#include <iostream>
using namespace std;

int main() {

    /*
        Convert a string into a funky string.

        Sample Input: COMPUTER
        
        Sample Output: cOmPuTeR
    */

    // char letter = 'A';

    // letter = toupper(letter);

    // cout << letter << endl;

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++){
        if (i % 2 == 0){
            s[i] = tolower(s[i]);
        }
        else{
            s[i] = toupper(s[i]);
        }
        
    }

    cout << s << endl;

    return 0;
}