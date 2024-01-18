#include <iostream>
using namespace std;

int main() {

    /*
        Print a dash '-' between every character of the string.

        Sample Input: COMPUTER
        
        Sample Output: C-O-M-P-U-T-E-R
    */

    string s;
    getline(cin, s);

    // One possible way
    // for (int i = 0; i < s.length()-1; i++){
    //     cout << s[i] << "-";
    // }
    // cout << s[s.length() - 1]<< endl;

    // More common way of solving
    for (int i = 0; i < s.length(); i++){
        cout << s[i];
        if (i < s.length()-1){
            cout << "-";
        }
    }
    cout << endl;

    return 0;
}