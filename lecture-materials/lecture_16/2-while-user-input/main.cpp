#include <iostream>
using namespace std;

int main() {
    
    /* 
        Ask the user to input an indefinite number of integers and classify each as even or odd.

        Sample Input: 1 2 3 [ctrl+d]
        
        Sample Output: 
        1 is an odd numer      
        2 is an even number
        3 is an odd number
        Thank you for using this number classifier
    */

    int x;

    while (cin >> x){
        if (x % 2 == 0){
            cout << x << " is an even number" << endl;
        }
        else{
            cout << x << " is an odd number" << endl;
        }
    }

    cout << "Thank you for using this number classifier" << endl;


    return 0;
}