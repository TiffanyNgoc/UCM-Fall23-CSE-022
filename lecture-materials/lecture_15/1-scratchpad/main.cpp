#include <iostream>
using namespace std;

int main() {
    // Your code here

    for(int i = 10; i > 0; i -= 2){
        cout<< i << ": "  << "Hello World" << endl;
    }


int x;
    

    int total = 0;

    while (cin >> x){
        total = total + x;
    }

    cout << "Total is: " << total << endl;

    // Other code
    
    string password = "abc123";

    string attempt;
    cin >> attempt;


    while (attempt != password){
        cout << "Incorrect password" << endl;
        cin >> attempt;
    }

    cout << "Access granted" << endl;

    return 0;
}