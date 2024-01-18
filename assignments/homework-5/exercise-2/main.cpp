#include <iostream>
#include <ucm_random>
#include <cmath>
using namespace std;

int main() {

    int lower = 1;
    int upper;
    
    cin >> upper;

    if (upper <= 1) {
        cerr << "Invalid upper limit." << endl;
        return 1;
    }

    RNG generator;
    int x = generator.get(lower, upper);

    int count = 1;
    int minimum = ceil(log2(upper));
    int attempt;
    
    while (attempt != x) {
        cout << "Enter guess [1.." << upper << "]: ";
        cin >> attempt;
            if (attempt != x) {
                if (cin.eof()) {
                    break;
                }
                if (attempt < x) {
                    cout << "Go higher" << endl;
                    cout << "" << endl;
                    count +=1;
                }
                else if (attempt > x) {
                    cout << "Go lower" << endl;
                    cout << "" << endl;
                    count +=1;
                }
            }
            else if (attempt == x) {
                if (count == minimum) {
                    cout << "" << endl;
                    cout << "You got it in " << count << " attempts, which is the minimum number of attempts required to guarantee success." << endl;
                    break;
                }
                if (count > minimum) {
                    cout << "" << endl;
                    cout << "You got it in " << count << " attempts, but it could have been done in " << minimum << "." << endl;
                    break;
                }
                if (count < minimum) {
                    cout << "" << endl;
                    cout << "It requires " << minimum << " attempts to guarantee success. You got lucky and guessed it in " << count << "." << endl;
                    break;
                }
            }
    }

    if (cin.eof()) {
        cout << "" << endl;
        cout << "" << endl;
        cout << "Better luck next time." << endl;
        cout << "The number was " << x << "." << endl;
    }

    // if (std::cin.eof()==1) {
    //     cout << "" << endl;
    //     cout << "Better luck next time." << endl;
    //     cout << "The number was " << x << endl;
    // }

    return 0;
}
