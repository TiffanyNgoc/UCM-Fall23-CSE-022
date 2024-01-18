#include <iostream>

using namespace std;

void printBanner(string s){
    for( int i = 0; i < s.length() + 2; i++){
        cout << "=";
    }
    cout << endl;
    cout << " " <<  s << " " << endl;

    for( int i = 0; i < s.length() + 2; i++){
        cout << "=";
    }
    cout << endl;
}

void handleInput(string input){
    system("clear");
    printBanner(input);
    cout << endl;
}

int main() {

    /*
        Your code goes here
    */
    string heading;
    
    while (getline(cin, heading)){
        handleInput(heading);
    }

    


    return 0;
}