#include <iostream>
#include <string>

using namespace std;

void greet(string someName){
    cout << "Hello, " << someName << "!" << endl;
}

int main() {

    /*
        Your code goes here
    */

    string name;
    getline(cin, name);

    greet(name);


    return 0;
}