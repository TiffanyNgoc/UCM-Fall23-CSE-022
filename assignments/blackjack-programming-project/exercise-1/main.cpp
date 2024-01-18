#include <iostream>
#include "blackjack.h"
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() {
    // cards must be represented using the following string array
    string cards[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};

    // Shuffle cards
    int deckSize = 52;

    shuffleCards(cards, deckSize);

    std::cout << "Your bank: $" << bank << std::endl;
    std::cout << std::endl;
    std::cout << "Place bet [$25]: ";
    
    string a;
    getline(cin, a);

    if (a == "") {
        system("clear");
    }

    // while (bank >= betAmount) {
    //     // Player's turn
    //     std::string playerHand[2];
    //     playerHand[0] = cards[0];
    //     playerHand[1] = cards[1];
    //     int playerHandSize = 2;

    //     // Dealer's turn
    //     std::string dealerHand[2];
    //     dealerHand[0] = cards[2];
    //     dealerHand[1] = cards[3];
    //     int dealerHandSize = 2;

    //     std::cout << "Your bank: $" << bank << std::endl;
    //     std::cout << "Your bet: $" << betAmount << std::endl;

    //     std::cout << "\nPlayer's Hand:" << std::endl;
    //     printHand(playerHand, playerHandSize);

    //     // Check if there is Blackjack
    //     std::string playerOutcome = determineOutcome(playerHand, playerHandSize, dealerHand, dealerHandSize);
    //     std::cout << playerOutcome << std::endl;
    // }






    while (bank >= betAmount) {
        // Player's turn
        std::string playerHand[2];
        playerHand[0] = cards[0];
        playerHand[1] = cards[1];
        int playerHandSize = 2;

        // Dealer's turn
        std::string dealerHand[2];
        dealerHand[0] = cards[2];
        dealerHand[1] = cards[3];
        int dealerHandSize = 2;

        std::cout << "Your bank: $" << bank << std::endl;
        std::cout << "Your bet: $" << betAmount << std::endl;

        std::cout << "\nPlayer's Hand:" << std::endl;
        printHand(playerHand, playerHandSize);

        // Check if there is Blackjack
        std::string playerOutcome = determineOutcome(playerHand, playerHandSize, dealerHand, dealerHandSize);
        std::cout << playerOutcome << std::endl;

        if (playerOutcome == "You got a blackjack!") {
            bank += static_cast<int>(betAmount * 1.5); // Blackjack pays 1.5 times the bet
        }
        else {
            // Player's turn
            std::string action;
            while (true) {
                std::cout << "Do you want to 'hit' or 'stand'? ";
                std::cin >> action;

                if (action == "hit") {
                    playerHand[playerHandSize] = cards[playerHandSize];
                    playerHandSize++;

                    std::cout << "\nPlayer's Hand:" << std::endl;
                    printHand(playerHand, playerHandSize);

                    // Check for bust
                    if (calculatePoints(playerHand, playerHandSize) > 21) {
                        std::cout << "You busted! You lose!" << std::endl;
                        bank -= betAmount;
                        break;
                    }
                }
                else if (action == "stand") {
                    break;
                }
                else {
                    std::cout << "Invalid action, Please enter 'hit' or 'stand'." << std::endl;
                }
            }

            // Dealer's turn
            while (calculatePoints(dealerHand, dealerHandSize) < 17 && dealerHandSize < 52) {
                dealerHand[dealerHandSize] = cards[playerHandSize + dealerHandSize];
                dealerHandSize++;
            }

            std::cout << "\nDealer's Hand:" << std::endl;
            printHand(dealerHand, dealerHandSize);

            // Determining the winner
            std::string outcome = determineOutcome(playerHand, playerHandSize, dealerHand, dealerHandSize);
            std::cout << outcome << std::endl;

            if (outcome == "You win!") {
                bank += betAmount;
            }
            else if (outcome == "You lose!") {
                bank -= betAmount;
            }

            // Ask if the player wants to player another round
            std::string playAgain;
            std::cout << "\nDo you want to play another round? (yes/no): ";
            std::cin >> playAgain;

            if (playAgain != "yes") {
                break;
            }
        }

        std::cout << "Thanks for playing! Your final bank: $" << bank << std::endl;
    }

    return 0;
}
