#include <iostream>
#include <ucm_random>

using namespace std;

int main() {
    // Create a game that generates a random number and lets the user guess it
    // The user should get an unlimited number of attempts

    RNG generator;
    int x = generator.get(1, 10);

    int attempt;
    while(cin >> attempt){
        if (attempt == x){
            cout << "You got it..." << endl;
            break;
        }
        else{
            cout << "That is not correct" << endl;
        }
    }

    return 0;
}