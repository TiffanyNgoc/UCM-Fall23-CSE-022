#include <iostream>
using namespace std;

int main() {

    /*
        2.25% rate: income is $100,000 or more.
        3.25% rate: income is less than $100,000, and customer is 65 or older.
        5.25% rate: income is less than $100,000, and customer is 25 or older, but younger than 65.
        7.25% rate: income is less than $100,000, and customer is younger than 25.
    */

    float price;
    bool membership;
    cin >> price >> membership;

    if (price >= 1000){
        cout << "Free shipping" << endl;
    }
    else if (price < 1000 && membership == true) {
        cout << "Discounted shipping" << endl;
    }
    else {
        cout << "Full price shipping" << endl;
    }
    return 0;
}