#include <iostream>
using namespace std;

int main() {

    /*
		Your code goes here
    */

    int currentMin;
    cin >> currentMin;

    for (int i = 0; i < 4; i++){
        int x;
        cin >> x;
        if (x < currentMin){
            currentMin = x;
        }
    }

    cout << "The min is: " << currentMin << endl;
    return 0;
}