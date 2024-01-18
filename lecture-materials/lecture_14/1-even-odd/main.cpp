#include <iostream>
using namespace std;

int main() {

    /*
        Ask user for 5 integers.
        Classify each one as even or odd.
    */
    int n = 5;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        if (x % 2 == 0){
            cout << "EVEN" << endl;
        }
        else{
            cout << "ODD" << endl;
        }
    }

    return 0;
}