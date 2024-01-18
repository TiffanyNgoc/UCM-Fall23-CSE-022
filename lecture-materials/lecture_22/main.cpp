#include <iostream>
#include <ucm_random>

// https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#define RED_ON_WHITE "\033[1;31;107m"
#define RESET "\033[0m"

using namespace std;

bool allSame(int dice[], int size){
    int first = dice[0];
    for (int i = 1; i < size; i++){
        if (dice[i] != first){
            return false;
        }
    }
    return true;
}

void printDice(int dice[], int size){
   
    for (int i = 0; i < size; i++){
        cout << RED_ON_WHITE << "         " << RESET << " ";
    }
    cout << endl;
    
    for (int i = 0; i < size; i++){
        if (dice[i] == 1){
            cout << RED_ON_WHITE << "         " << RESET << " ";
        }
        else if (dice[i] == 2 || dice[i] == 3){
            cout << RED_ON_WHITE << "  *      " << RESET << " ";
        }
        else{
            cout << RED_ON_WHITE << "  *   *  " << RESET << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < size; i++){
        if (dice[i] == 1 || dice[i] == 3 || dice[i] == 5){
            cout << RED_ON_WHITE << "    *    " << RESET << " ";
        }
        else if (dice[i] == 2 || dice[i] == 4){
            cout << RED_ON_WHITE << "         " << RESET << " ";
        }
        else{
            cout << RED_ON_WHITE << "  *   *  " << RESET << " ";
        }
        
    }
    cout << endl;

    for (int i = 0; i < size; i++){
        if (dice[i] == 1){
            cout << RED_ON_WHITE << "         " << RESET << " ";
        }
        else if (dice[i] == 2 || dice[i] == 3){
            cout << RED_ON_WHITE << "      *  " << RESET << " ";
        }
        else{
            cout << RED_ON_WHITE << "  *   *  " << RESET << " ";
        }
        
    }
    cout << endl;

    for (int i = 0; i < size; i++){
        cout << RED_ON_WHITE << "         " << RESET << " ";
    }
    cout << endl;
}

int main(){    
    // Your code here
    RNG generator;
    int size = 2;

    int hand[size];
    int rolls[7 * size];
    string c;

    int score = 0;
    int counter = 0;

    for (int k = 0; k < 7; k++){
        system("clear");
        
        for (int i = 0; i < size; i++){
            hand[i] = generator.get(1, 6);
            score = score + hand[i];
            rolls[counter] = hand[i];
            counter++;
        }

        printDice(hand, size);

        cout << "Current Score: " << score << endl << endl;


        if (allSame(hand, size)){
            score = 0;
            break;
        }

        cout << "Continue ([Y]/N): ";
        getline(cin, c);

        if (toupper(c[0]) == 'N'){
            break;
        }
    }

    int dealerHand[size];
    int dealerRolls[7 * size];

    int dealerScore = 0;
    int dealerCounter = 0;

    for (int k = 0; k < 7; k++){
        for (int i = 0; i < size; i++){
            dealerHand[i] = generator.get(1, 6);
            dealerScore = dealerScore + dealerHand[i];
            dealerRolls[dealerCounter] = dealerHand[i];
            dealerCounter++;
        }

        if (allSame(dealerHand, size)){
            dealerScore = 0;
            break;
        }

        if (dealerScore >= score){
            break;
        }
    }

    system("clear");

    printDice(rolls, counter);
    cout << "Your score: " << score << endl; 

    cout << endl;

    printDice(dealerRolls, dealerCounter);
    cout << "Dealer score: " << dealerScore << endl; 

    if (score > dealerScore){
        cout << "You win" << endl;
    }
    else if (dealerScore > score){
        cout << "You lose" << endl;
    }
    else{
        if (score == 0){
            cout << "It's a tie" << endl;
        }
        else{
            cout << "You lose" << endl;
        }
    }

    cout << RESET;
    return 0;
}