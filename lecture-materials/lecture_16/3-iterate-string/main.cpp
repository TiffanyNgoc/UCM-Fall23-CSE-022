#include <iostream>
#include <string>
using namespace std;

int main() {

    /*
        Print each individual character of the string.
        
        Sample Input: COMPUTER
        
        Sample Output:
        C
        O
        M
        P
        U
        T
        E
        R
    */
    
    string s;
    getline(cin, s);

    // cout << s[0] << endl;
    // cout << s[1] << endl;
    // cout << s[2] << endl;
    // cout << s[3] << endl;
    // cout << s[4] << endl;
    // cout << s[5] << endl;
    // cout << s[6] << endl;
    // cout << s[7] << endl;

    for (int i = 0; i < s.length(); i++){
        cout << s[i] << endl;
    }

    return 0;
}