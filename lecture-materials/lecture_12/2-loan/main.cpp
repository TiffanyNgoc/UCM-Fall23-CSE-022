#include <iostream>
using namespace std;

int main() {

    /*
        2.25% rate: income is $100,000 or more.
        3.25% rate: income is less than $100,000, and customer is 65 or older.
        5.25% rate: income is less than $100,000, and customer is 25 or older, but younger than 65.
        7.25% rate: income is less than $100,000, and customer is younger than 25.
    */

    int age;
    float income;
    cin >> age >> income;

    if (income >= 100000){
        // Age doesn't matter
        cout << "2.25% rate" << endl;
    }
    else{
        // Age matters
        // We know income < 100000
        if (age >= 65){
            cout << "3.25% rate" << endl;
        }
        else if (age >= 25){
            cout << "5.25% rate" << endl;
        }
        else{
            cout << "7.25% rate" << endl;
        }
    }






    // if (income >= 100000){
    //     cout << "2.25% rate" << endl;
    // }
    // if (income < 100000 && age >=65){
    //     cout << "3.25% rate" << endl;
    // }
    // if (income < 100000 && age >=25 && age < 65){
    //     cout << "5.25% rate" << endl;
    // }
    // if (income < 100000 && age < 25){
    //     cout << "7.25% rate" << endl;
    // }



    return 0;
}