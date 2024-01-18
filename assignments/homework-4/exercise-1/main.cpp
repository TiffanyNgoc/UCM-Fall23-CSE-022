#include <iostream>
#include <ucm_random>

using namespace std;


int main() {

    for (int i = 1; i < 6; i ++) {
    RNG generator;

    int question = 0;
    question++;

    // Get 2 random ints [1..20]
    int x = generator.get(1, 15);
    int y = generator.get(1, 15);

    // Make sure x is always the bigger 1
    if (x < y){
        int temp = x;
        x = y;
        y = temp;
    }

    // Decide which math operation to perform
    int opCode = generator.get(1, 4);

    int expected;
    string symbol;

    // Display the question
    if (opCode == 1){
        cout << "Question " << i << ": " << x << " + " << y << " = ";
        expected = x + y;
        symbol = "+";
        question++;
    }
    if (opCode == 2){
        cout << "Question " << i << ": " << x << " - " << y << " = ";
        expected = x - y;
        symbol = "-";
        question++;
    }
    if (opCode == 3){
        cout << "Question " << i << ": " << x << " * " << y << " = ";
        expected = x * y;
        symbol = "*";
        question++;
    }
    if (opCode == 4){
        cout << "Question " << i << ": " << x << " / " << y << " = ";
        expected = x / y;
        symbol = "/";
        question++;
    }

    // Get the answer from the user
    int answer;
    cin >> answer;

    if (answer == expected) {
        cout << "That is correct!" << endl;
        cout << endl;
    }
    else {
        cout << "That is incorrect. The correct answer is: " << expected << endl;
        cout << endl; 
    }

    }

    return 0;
}