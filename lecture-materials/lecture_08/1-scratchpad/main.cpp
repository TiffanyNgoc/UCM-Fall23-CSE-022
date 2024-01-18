#include <iostream>
#include <string>

using namespace std;

int main(){

    int age;
    cin >> age;
    cin.ignore();

    string name;
    getline(cin, name);

    cout << "Hello " << name << ". It is good to be " << age << " years old." << endl;

    return 0;
}