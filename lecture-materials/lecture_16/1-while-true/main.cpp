#include <iostream>
#include <ucm_random>
using namespace std;

int main() {
    
    /*
        Determine the number of attempts it takes for the random number generator 
        to generate a specific number in a given range.

        Sample Input: 7 1 100
        
        Sample Output: It took 39 attempts to randomly generate a 7 in the range [1, 100]
    */

    RNG generator;
    int counter = 0;

    int target, lower, upper;
    cin >> target >> lower >> upper;

    while (true){ // Repeat infinitely in case that is necessary
        int x = generator.get(lower, upper); // Do what needs to be done
        counter++; 

        if (x == target){   // If the contition to exit comes up
            break;          // Exit the loop
        }
    }

    cout << counter << endl; // Report your result


    return 0;
}