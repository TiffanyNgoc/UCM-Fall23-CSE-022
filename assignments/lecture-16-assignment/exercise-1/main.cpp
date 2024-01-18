#include <iostream>
using namespace std;

int main() {
    
    string pass;
    string lul;
    getline(cin, pass);
    for (int i = 0; i < pass.length(); i ++){

        lul = pass[i];
        if (lul == "a") {
            cout << '@';
        } else if (lul == "c") {
            cout << "(";
        } else if (lul == "g") {
            cout << "9";
        } else if (lul == "o") {
            cout << "0";
        } else if (lul == "s") {
            cout << "$";
        } else {
            cout << lul;
        }
    }

    return 0;
}