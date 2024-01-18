#include <iostream>
using namespace std;

int main() {
    // Create a program that reads in an arbitrary number of grades and computes their average

    int x;

    int total = 0;
    int count = 0;

    while (cin >> x){
        total = total + x;
        count += 1;
    }

    float average = (float) total / count;
    
    cout << average << endl;

    return 0;
}