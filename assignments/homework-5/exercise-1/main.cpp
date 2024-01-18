#include <iostream>
#include <ucm_random>

using namespace std;


int main() {

    int answer;
    int count1 = 1;
    int count2 = 1;
    int count3 = 1;
    int count4 = 1;
    int count5 = 1;

    for (int i = 1; i < 6; i ++) {
    RNG generator;

    // Get 2 random ints [1..20]
    int x = generator.get(1, 15);
    int y = generator.get(1, 15);

    // Decide which math operation to perform
    int opCode = generator.get(1, 5);

    int expected;
    string symbol;

    // Display the question
    
    // if (opCode == 1){
    //     cout << i << ". " << x << " + " << y << " = ";
    //     expected = x + y;
    //     symbol = "+";
    // }

    // if (opCode == 2){
    //     cout << i << ". " << x << " - " << y << " = ";
    //     expected = x - y;
    //     symbol = "-";
    // }

    // if (opCode == 3){
    //     cout << i << ". " << x << " * " << y << " = ";
    //     expected = x * y;
    //     symbol = "*";
    // }

    // if (opCode == 4){
    //     cout << i << ". " << x << " / " << y << " = ";
    //     expected = x / y;
    //     symbol = "/";
    // }

    // if (opCode == 5) {
    //     cout << i << ". " << x << " % " << y << " = ";
    //     expected = x % y;
    //     symbol = "%";
    // }

    // Get the answer from the user

    while (1 == 1 ) {

        if (opCode == 1) {
            cout << i << ". " << x << " + " << y << " = ";
            expected = x + y;
            symbol = "+";
            // count1 += 1;
        }
        if (opCode == 2) {
            cout << i << ". " << x << " - " << y << " = ";
            expected = x - y;
            symbol = "-";
            // count2 += 1;
        }
        if (opCode == 3) {
            cout << i << ". " << x << " * " << y << " = ";
            expected = x * y;
            symbol = "*";
            // count3 += 1;
        }
        if (opCode == 4) {
            cout << i << ". " << x << " / " << y << " = ";
            expected = x / y;
            symbol = "/";
            // count4 += 1;
        }
        if (opCode == 5) {
            cout << i << ". " << x << " % " << y << " = ";
            expected = x % y;
            symbol = "%";
            // count5 += 1;
        }
        cin >> answer;
        if (answer == expected) {
            cout << "" << endl;
            break;
        } 
        else {
            if ((i) == 1){
                count1 += 1;
            }
            else if ((i) == 2) {
                count2 += 1;
            }
            else if ((i) == 3) {
                count3 += 1;
            }
            else if ((i) == 4) {
                count4 += 1;
            }
            else if ((i) == 5) {
                count5 += 1;
            }
        }
    }

    }

    cout << "Question 1 took you " << count1 << " attempts." << endl;
    cout << "Question 2 took you " << count2 << " attempts." << endl;
    cout << "Question 3 took you " << count3 << " attempts." << endl;
    cout << "Question 4 took you " << count4 << " attempts." << endl;
    cout << "Question 5 took you " << count5 << " attempts." << endl;

    return 0;
}