#ifndef BLACKJACK_H
#define BLACKJACK_H
#include <iostream>

// C++ macros for changing background color and text color of the terminal
#define RESET "\033[0m"             // reset terminal
#define WHITE_BG "\033[47m"         // white background
#define RED_CARD "\033[1;47;31m"    // white background + red text color
#define BLACK_CARD "\033[1;47;30m"  // white background + black text color

int bank = 250;
int betAmount = 25;

void shuffleCards(std::string cards[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        std::swap(cards[i], cards[j]);
    }
}

void printHand(std::string cards[], int size) {
    for (int i = 0; i < size; i++){
        std::cout << WHITE_BG << "          " << RESET;
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::string face = cards[i].substr(0, cards[i].size() - 1); // Extract face value
        std::string suit = cards[i].substr(cards[i].size() - 1); // Extract suit

        // Print based on face value and suit for color coding
        // Red Cards only
        if ((face == "A") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  A       " << RESET;
        }
        else if ((face == "2") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  2       " << RESET;
        }
        else if((face == "3") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  3       " << RESET;
        }
        else if ((face == "4") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  4       " << RESET;
        }
        else if ((face == "5") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  5       " << RESET;
        }
        else if ((face == "6") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  6       " << RESET;
        }
        else if ((face == "7") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  7       " << RESET;
        }
        else if ((face == "8") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  8       " << RESET;
        }
        else if ((face == "9") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  9       " << RESET;
        }
        else if ((face == "10") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  10      " << RESET;
        }
        else if ((face == "J") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  J       " << RESET;
        }
        else if ((face == "Q") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  Q       " << RESET;
        }
        else if ((face == "K") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "  K       " << RESET;
        } // Starting of Black Cards
        else if ((face == "A") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  A       " << RESET;
        }
        else if ((face == "2") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  2       " << RESET;
        }
        else if ((face == "3") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  3       " << RESET;
        }
        else if ((face == "4") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  4       " << RESET;
        }
        else if ((face == "5") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  5       " << RESET;
        }
        else if ((face == "6") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  6       " << RESET;
        }
        else if ((face == "7") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  7       " << RESET;
        }
        else if ((face == "8") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  8       " << RESET;
        }
        else if ((face == "9") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  9       " << RESET;
        }
        else if ((face == "10") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  10      " << RESET;
        }
        else if ((face == "J") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  J       " << RESET;
        }
        else if ((face == "Q") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "  Q       " << RESET;
        }
        else {
            std::cout << BLACK_CARD << "  K       " << RESET;
        }
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i ++) {
        std::string face = cards[i].substr(0, cards[i].size() - 1); // Extract face value
        std::string suit = cards[i].substr(cards[i].size() - 1); // Extract suit

        if (suit == "D") {
            std::cout << RED_CARD << "    /\\    " << RESET;
        }
        else if (suit == "H") {
            std::cout << RED_CARD << "   _  _   " << RESET;
        }
        else if (suit == "C") {
            std::cout << BLACK_CARD << "    __    " << RESET;
        }
        else {
            std::cout << BLACK_CARD << "    /\\    " << RESET;
        }
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::string face = cards[i].substr(0, cards[i].size() - 1); // Extract face value
        std::string suit = cards[i].substr(cards[i].size() - 1); // Extract suit

        if (suit == "D") {
            std::cout << RED_CARD << "   /  \\   " << RESET;
        }
        else if (suit == "H") {
            std::cout << RED_CARD << "  ( \\/ )  " << RESET;
        }
        else if (suit == "S") {
            std::cout << BLACK_CARD << "   /  \\   " << RESET;
        }
        else {
            std::cout << BLACK_CARD << "   (  )   " << RESET;
        }
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::string face = cards[i].substr(0, cards[i].size() - 1); // Extract face value
        std::string suit = cards[i].substr(cards[i].size() - 1); // Extract suit

        if (suit == "D" || suit == "H") {
            std::cout << RED_CARD << "   \\  /   " << RESET;
        }
        else {
            std::cout << BLACK_CARD << "  (____)  " << RESET;
        }
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::string face = cards[i].substr(0, cards[i].size() - 1); // Extract face value
        std::string suit = cards[i].substr(cards[i].size() - 1); // Extract suit

        if (suit == "D" || suit == "H") {
            std::cout << RED_CARD << "    \\/    " << RESET;
        }
        else {
            std::cout << BLACK_CARD << "    ||    " << RESET;
        }
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        std::string face = cards[i].substr(0, cards[i].size() - 1); // Extract face value
        std::string suit = cards[i].substr(cards[i].size() - 1); // Extract suit

        if ((face == "A") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       A  " << RESET;
        }
        else if ((face == "2") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       2  " << RESET;
        }
        else if ((face == "3") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       3  " << RESET;
        }
        else if ((face == "4") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       4  " << RESET;
        }
        else if ((face == "5") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       5  " << RESET;
        }
        else if ((face == "6") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       6  " << RESET;
        }
        else if ((face == "7") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       7  " << RESET;
        }
        else if ((face == "8") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       8  " << RESET;
        }
        else if ((face == "9") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       9  " << RESET;
        }
        else if ((face == "10") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "      10  " << RESET;
        }
        else if ((face == "J") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       J  " << RESET;
        }
        else if ((face == "Q") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       Q  " << RESET;
        }
        else if ((face == "K") && (suit == "H" || suit == "D")) {
            std::cout << RED_CARD << "       K  " << RESET;
        } // Starting Black cards
        else if ((face == "A") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       A  " << RESET;
        }
        else if ((face == "2") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       2  " << RESET;
        }
        else if ((face == "3") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       3  " << RESET;
        }
        else if ((face == "4") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       4  " << RESET;
        }
        else if ((face == "5") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       5  " << RESET;
        }
        else if ((face == "6") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       6  " << RESET;
        }
        else if ((face == "7") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       7  " << RESET;
        }
        else if ((face == "8") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       8  " << RESET;
        }
        else if ((face == "9") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       9  " << RESET;
        }
        else if ((face == "10") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "      10  " << RESET;
        }
        else if ((face == "J") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       J  " << RESET;
        }
        else if ((face == "Q") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       Q  " << RESET;
        }
        else if ((face == "K") && (suit == "S" || suit == "C")) {
            std::cout << BLACK_CARD << "       K  " << RESET;
        }
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout <<std::endl;

    for (int i = 0; i < size; i++){
        std::cout << WHITE_BG << "          " << RESET;
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

}

int calculatePoints(std::string hand[], int size) {
    int points = 0;
    int numberOfAces = 0;

    for (int i = 0; i < size; i++) {
        char face = hand[i][0];
        switch (face) {
            case 'A':
                points += 11;
                numberOfAces++;
                break;
            case 'K':
            case 'Q':
            case 'J':
                points += 10;
                break;
            default:
                points += std::stoi(hand[i]); // Convert char to int
        }
    }

    // Adjust for Aces
    while (numberOfAces > 0 && points > 21) {
        points -= 10;
        numberOfAces--;
    }

    return points;
}

std::string determineOutcome(std::string playerHand[], int playerHandSize, std::string dealerHand[], int dealerHandSize){
    int playerPoints = calculatePoints(playerHand, playerHandSize);
    int dealerPoints = calculatePoints(dealerHand, dealerHandSize);

    if (playerPoints == 21 && playerHandSize == 2) {
        if (dealerPoints == 21 && dealerHandSize == 2) {
            return "It's a tie!";
        }
        return "You got a blackjack!";
    }
    else if (dealerPoints == 21 && dealerHandSize == 2) {
        return "Dealer got a blackjack!";
    }
    else if (playerPoints > 21) {
        return "You lose!";
    }
    else if (dealerPoints > 21) {
        return "You win!";
    }
    else if (playerPoints > dealerPoints) {
        return "You win!";
    }
    else if (playerPoints < dealerPoints) {
        return "You lose!";
    }
    else if (playerPoints == dealerPoints) {
        return "It's a tie!";
    }
    else {
        return "Unexpected outcome!";
    }
}

#endif