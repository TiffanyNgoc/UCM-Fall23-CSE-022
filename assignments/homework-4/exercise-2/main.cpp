#include <iostream>
using namespace std;

int main() {

    int n = 10;

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

    if (evenCount == 0) {
        cout << "There were no even numbers" << endl;
        cout << "There were " << oddCount << " odd numbers" << endl;
    }
    else if (oddCount == 0) {
        cout << "There were " << evenCount << " even numbers" << endl;
        cout << "There were no odd numbers" << endl;
    }
    else {
        cout << "There were " << evenCount << " even numbers" << endl;
        cout << "There were " << oddCount << " odd numbers" << endl;
    }

    return 0;
}