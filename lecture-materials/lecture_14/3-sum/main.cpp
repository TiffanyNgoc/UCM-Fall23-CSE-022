#include <iostream>
using namespace std;

int main() {

    /*
        Ask user for 5 integers.
        Print the sum of the 5 integers.
    */

    int total = 0;
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;

        total = total + x;

    }

    cout << "Total is " << total << endl;

    return 0;
}