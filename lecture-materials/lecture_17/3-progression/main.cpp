#include <cstdlib>
#include <iostream>

using namespace std;

void progress(int percentage){
    int completed = percentage / 100.0 * 20;

    cout << "[";

    for (int i = 0; i < completed; i++){
        cout << "=";
    }
    for (int i = completed; i < 20; i++){
        cout << " ";
    }
    cout << "]";
    cout << " | " << percentage << "%" << endl;
}

void displayProgress(int p){
    system("clear");
    progress(p);
    cout << endl;
}

int main() {

    /*
        Your code goes here
    */

    int x;
    while (cin >> x){
        if (x < 0) x = 0;
        displayProgress(x);
    }

    return 0;
}