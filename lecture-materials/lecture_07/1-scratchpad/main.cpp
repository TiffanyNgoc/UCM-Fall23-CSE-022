#include <iostream>

using namespace std;

int main(){

    int age;
    cin >> age;
    cin.ignore();

    string emotion;
    // cin >> emotion;
    getline(cin, emotion);

    string thing;
    getline(cin, thing);

    cout << " I am " << age << " and I " << emotion << " " << thing << "." << endl;

    return 0;
}