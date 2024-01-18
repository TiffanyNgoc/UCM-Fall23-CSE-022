#include <iostream>
using namespace std;

int main() {

    /*
        Ask user for 5 integers.
        Determine the max of those 5 integers.
    */

    int currentMax;
    cin >> currentMax;

    for (int i = 0; i < 4; i++){
        int x;
        cin >> x;
        if (x > currentMax){
            currentMax = x;
        }
    }

    cout << "The maximum value entered was " << currentMax << endl;

    return 0;
}