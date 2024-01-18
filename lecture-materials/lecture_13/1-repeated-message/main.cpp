#include <iostream>

using namespace std;

int main() {

    string message;
    getline(cin, message);


    for (int i = 0; i < 50; i++){
        cout << "=";
    }
    cout << endl;
    cout << "| ";
    cout << message;

    for (int i = 0; i < 46 - message.length(); i++){
        cout << " ";
    }

    cout << " |" << endl;

    for (int i = 0; i < 50; i++){
        cout << "=";
    }
    cout << endl;




    // cout << message.length() << endl;

    // for (int i = 0; i < message.length() + 2; i++){
    //     cout << "=";
    // }
    // cout << endl;
    // cout << " " << message << " " << endl;
    
    // for (int i = 0; i < message.length() + 2; i++){
    //     cout << "=";
    // }
    // cout << endl;

    

	return 0;
}