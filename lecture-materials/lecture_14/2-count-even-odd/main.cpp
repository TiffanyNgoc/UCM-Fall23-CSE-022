#include <iostream>
using namespace std;

int main() {

    /*
        Ask user for 5 integers.
        Count the number of even and odd ones
    */

    int n = 5;

    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;

        if (x % 2 == 0){
            evenCount++;
        }
        else{
            oddCount++;
        }
    }

    cout << "There were " << evenCount << " even numbers" << endl;
    cout << "There were " << oddCount << " odd numbers" << endl;

    return 0;
}