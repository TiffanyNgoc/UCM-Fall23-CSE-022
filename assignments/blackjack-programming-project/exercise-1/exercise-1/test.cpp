#include <igloo/igloo.h>
#include <fstream>
#include <vector>
#include "blackjack.h"

using namespace igloo;

std::string exec(std::string command) {
   char buffer[128];
   std::string result = "";

   // Open pipe to file
   FILE* pipe = popen((command + " 2>&1").c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
   return result;
}

void replace_pattern(std::string&output, const std::string& pattern){
    while (output.find(pattern) != std::string::npos){
        output = output.replace(output.find(pattern), pattern.length(), "");
    }
}

struct OutputParser{
    std::string output;
    std::vector<std::string> result;

    void replace_pattern(const std::string& pattern){
        while (output.find(pattern) != std::string::npos){
            output = output.replace(output.find(pattern), pattern.length(), "");
        }
    }

    OutputParser(std::string output){
        this->output = output;
        replace_pattern("[1;47;31m");
        replace_pattern("[1;31;47m");
        replace_pattern("[47;1;31m");
        replace_pattern("[31;1;47m");
        replace_pattern("[47;31;1m");
        replace_pattern("[31;47;1m");
        replace_pattern("[1;47;30m");
        replace_pattern("[1;30;47m");
        replace_pattern("[47;1;30m");
        replace_pattern("[30;1;47m");
        replace_pattern("[47;30;1m");
        replace_pattern("[30;47;1m");
        replace_pattern("[0m");
        replace_pattern("[1m");
        replace_pattern("[30m");
        replace_pattern("[31m");
        replace_pattern("[47m");

        std::stringstream ss(this->output);
        std::string line;
        while (getline(ss, line)){
            if (line != ""){
                result.push_back(line);
            }
        }
    }
};

Context(TestBlackjack){
    static void TearDownContext() {
        system("rm -rf out.txt");
    }

    Spec(TestCalculatePoints0Cards){
        const int handCount = 0;
        std::string hand[handCount];
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(0));
    }
    Spec(TestCalculatePointsAce){
        const int handCount = 1;
        std::string hand[handCount] = {"AH"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(11));
    }
    Spec(TestCalculatePointsTwo){
        const int handCount = 1;
        std::string hand[handCount] = {"2D"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(2));
    }
    Spec(TestCalculatePointsThree){
        const int handCount = 1;
        std::string hand[handCount] = {"3S"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(3));
    }
    Spec(TestCalculatePointsFour){
        const int handCount = 1;
        std::string hand[handCount] = {"4C"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(4));
    }
    Spec(TestCalculatePointsFive){
        const int handCount = 1;
        std::string hand[handCount] = {"5H"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(5));
    }
    Spec(TestCalculatePointsSix){
        const int handCount = 1;
        std::string hand[handCount] = {"6D"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(6));
    }
    Spec(TestCalculatePointsSeven){
        const int handCount = 1;
        std::string hand[handCount] = {"7S"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(7));
    }
    Spec(TestCalculatePointsEight){
        const int handCount = 1;
        std::string hand[handCount] = {"8C"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(8));
    }
    Spec(TestCalculatePointsNine){
        const int handCount = 1;
        std::string hand[handCount] = {"9H"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(9));
    }
    Spec(TestCalculatePointsTen){
        const int handCount = 1;
        std::string hand[handCount] = {"10D"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(10));
    }
    Spec(TestCalculatePointsJack){
        const int handCount = 1;
        std::string hand[handCount] = {"JS"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(10));
    }
    Spec(TestCalculatePointsQueen){
        const int handCount = 1;
        std::string hand[handCount] = {"QC"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(10));
    }
    Spec(TestCalculatePointsKing){
        const int handCount = 1;
        std::string hand[handCount] = {"KH"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(10));
    }
    Spec(TestCalculatePointsTwoAces){
        const int handCount = 2;
        std::string hand[handCount] = {"AH", "AD"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(12));
    }
    Spec(TestCalculatePointsThreeAces){
        const int handCount = 3;
        std::string hand[handCount] = {"AH", "AD", "AS"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(13));
    }
    Spec(TestCalculatePointsFourAces){
        const int handCount = 4;
        std::string hand[handCount] = {"AH", "AD", "AS", "AC"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(14));
    }
    Spec(TestCalculatePointsBlackjack){
        const int handCount = 2;
        std::string hand[handCount] = {"AH", "10D"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(21));
    }
    Spec(TestCalculatePoints3A4){
        const int handCount = 3;
        std::string hand[handCount] = {"3H", "AH", "4C"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(18));
    }
    Spec(TestCalculatePoints3A45){
        const int handCount = 4;
        std::string hand[handCount] = {"3H", "AH", "4C", "5S"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(13));
    }
    Spec(TestCalculatePoints3A45Q){
        const int handCount = 5;
        std::string hand[handCount] = {"3H", "AH", "4C", "5S", "QD"};
        int points = calculatePoints(hand, handCount);
        Assert::That(points, Equals(23));
    }


    Spec(TestShuffle){
        std::string shuffled[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};
        std::string original[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};
        
        bool isShuffled = false;
        shuffleCards(shuffled, 52);
        for (int i = 0; i < 52; i++) {
            if (shuffled[i] != original[i]) {
                isShuffled = true;
                break;
            }
        }

        Assert::That(isShuffled, IsTrue());
    }

    Spec(TestShuffleGood){
        std::string shuffled[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};
        std::string original[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};
        
        int repeats = 0;
        shuffleCards(shuffled, 52);
        for (int i = 0; i < 52; i++) {
            if (shuffled[i] == original[i]) {
                repeats++;
            }
        }

        Assert::That(repeats, IsLessThan(5));
    }

    Spec(TestShuffleShuffle){
        std::string shuffled[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};
        std::string original[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};
        std::string shuffled2[52];

        shuffleCards(shuffled, 52);
        for (int i = 0; i < 52; i++) {
            shuffled2[i] = shuffled[i];
        }

        int repeats = 0;
        shuffleCards(shuffled, 52);
        for (int i = 0; i < 52; i++) {
            if (shuffled[i] == shuffled2[i]) {
                repeats++;
            }
        }

        Assert::That(repeats, IsLessThan(5));
    }

    Spec(TestOutcomePlayerBlackjack){
        const int playerHandCount = 2;
        std::string playerHand[playerHandCount] = {"AH", "10D"};
        const int dealerHandCount = 3;
        std::string dealerHand[dealerHandCount] = {"7H", "8D", "3C"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You got a blackjack!"));
    }

    Spec(TestOutcomeDealerBlackjack){
        const int playerHandCount = 2;
        std::string playerHand[playerHandCount] = {"JH", "9C"};
        const int dealerHandCount = 2;
        std::string dealerHand[dealerHandCount] = {"AD", "QD"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("Dealer got a blackjack!"));
    }

    Spec(TestOutcomeBothBlackjack){
        const int playerHandCount = 2;
        std::string playerHand[playerHandCount] = {"JH", "AC"};
        const int dealerHandCount = 2;
        std::string dealerHand[dealerHandCount] = {"QS", "AS"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("It's a tie!"));
    }

    Spec(TestOutcomePlayerBlackjackDealer21){
        const int playerHandCount = 2;
        std::string playerHand[playerHandCount] = {"QH", "AD"};
        const int dealerHandCount = 3;
        std::string dealerHand[dealerHandCount] = {"3H", "8S", "10S"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You got a blackjack!"));
    }

    Spec(TestOutcomeDealerBlackjackPlayer21){
        const int playerHandCount = 3;
        std::string playerHand[playerHandCount] = {"5H", "6D", "AS"};
        const int dealerHandCount = 2;
        std::string dealerHand[dealerHandCount] = {"10H", "AD"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("Dealer got a blackjack!"));
    }

    Spec(TestOutcomePlayerWins){
        const int playerHandCount = 3;
        std::string playerHand[playerHandCount] = {"3H", "10D", "7C"};
        const int dealerHandCount = 2;
        std::string dealerHand[dealerHandCount] = {"AD", "7H"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You win!"));
    }

    Spec(TestOutcomePlayerWinsDealerBusts){
        const int playerHandCount = 3;
        std::string playerHand[playerHandCount] = {"4H", "8D", "7C"};
        const int dealerHandCount = 3;
        std::string dealerHand[dealerHandCount] = {"10C", "7H", "6S"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You win!"));
    }

    Spec(TestOutcomePlayerBustsDealerWins){
        const int playerHandCount = 3;
        std::string playerHand[playerHandCount] = {"4H", "8D", "KS"};
        const int dealerHandCount = 2;
        std::string dealerHand[dealerHandCount] = {"10C", "8H"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You lose!"));
    }

    Spec(TestOutcomePlayerBustsDealerBusts){
        const int playerHandCount = 3;
        std::string playerHand[playerHandCount] = {"4H", "8D", "KS"};
        const int dealerHandCount = 3;
        std::string dealerHand[dealerHandCount] = {"10C", "4H", "QS"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You lose!"));
    }

    Spec(TestOutcomeTie){
        const int playerHandCount = 3;
        std::string playerHand[playerHandCount] = {"2H", "8D", "JS"};
        const int dealerHandCount = 2;
        std::string dealerHand[dealerHandCount] = {"10C", "QH"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("It's a tie!"));
    }

    Spec(TestOutcomePlayer21NotBlackjack){
        const int playerHandCount = 4;
        std::string playerHand[playerHandCount] = {"2H", "8D", "JS", "AD"};
        const int dealerHandCount = 2;
        std::string dealerHand[dealerHandCount] = {"10C", "QH"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You win!"));
    }

    Spec(TestOutcomeDealer21NotBlackjack){
        const int playerHandCount = 3;
        std::string playerHand[playerHandCount] = {"10H", "8D", "AH"};
        const int dealerHandCount = 3;
        std::string dealerHand[dealerHandCount] = {"8C", "8H", "5C"};

        std::string outcome = determineOutcome(playerHand, playerHandCount, dealerHand, dealerHandCount);

        Assert::That(outcome, Equals("You lose!"));
    }

    Spec(PrintZeroCards) {
        const int count = 0;
        std::string hand[count];

        std::ofstream fw;
        fw.open("out.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 
        printHand(hand, count);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        std::string actual = exec("cat out.txt");
        std::vector<std::string> actualParsed = OutputParser(actual).result;
        std::vector<std::string> expected = {};

        Assert::That(actualParsed, EqualsContainer(expected));
    }


    Spec(PrintOneCard) {
        const int count = 1;
        std::string hand[count] = {"AH"};

        std::ofstream fw;
        fw.open("out.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 
        printHand(hand, count);
        std::cout.flush();
        std::cout.rdbuf(oldbuf);

        std::string actual = exec("cat out.txt");
        std::vector<std::string> actualParsed = OutputParser(actual).result;
        std::vector<std::string> expected = {
            "          ",
            "  A       ",
            "   _  _   ",
            "  ( \\/ )  ",
            "   \\  /   ",
            "    \\/    ",
            "       A  ",
            "          ",
        };

        Assert::That(actualParsed, EqualsContainer(expected));
    }

    Spec(PrintTwoCards) {
        const int count = 2;
        std::string hand[count] = {"AH", "QH"};

        std::ofstream fw;
        fw.open("out.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 
        printHand(hand, count);
        std::cout.flush();
        std::cout.rdbuf(oldbuf);

        std::string actual = exec("cat out.txt");
        std::vector<std::string> actualParsed = OutputParser(actual).result;
        std::vector<std::string> expected = {
            "                     ",
            "  A          Q       ",
            "   _  _       _  _   ",
            "  ( \\/ )     ( \\/ )  ",
            "   \\  /       \\  /   ",
            "    \\/         \\/    ",
            "       A          Q  ",
            "                     ",
        };

        Assert::That(actualParsed, EqualsContainer(expected));
    }

    Spec(PrintAllCards) {
        const int count = 52;
        std::string hand[52] = {"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "10H", "JH", "QH", "KH", "AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "10D", "JD", "QD", "KD", "AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "10S", "JS", "QS", "KS", "AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "10C", "JC", "QC", "KC"};

        std::ofstream fw;
        fw.open("out.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 
        printHand(hand, count);
        std::cout.flush();
        std::cout.rdbuf(oldbuf);

        std::string actual = exec("cat out.txt");
        std::vector<std::string> actualParsed = OutputParser(actual).result;
        std::vector<std::string> expected = {
            "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ",
            "  A          2          3          4          5          6          7          8          9          10         J          Q          K          A          2          3          4          5          6          7          8          9          10         J          Q          K          A          2          3          4          5          6          7          8          9          10         J          Q          K          A          2          3          4          5          6          7          8          9          10         J          Q          K       ",
            "   _  _       _  _       _  _       _  _       _  _       _  _       _  _       _  _       _  _       _  _       _  _       _  _       _  _        /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         /\\         __         __         __         __         __         __         __         __         __         __         __         __         __    ",
            "  ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )     ( \\/ )      /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       /  \\       (  )       (  )       (  )       (  )       (  )       (  )       (  )       (  )       (  )       (  )       (  )       (  )       (  )   ",
            "   \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /       \\  /      (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)     (____)  ",
            "    \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         \\/         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||         ||    ",
            "       A          2          3          4          5          6          7          8          9         10          J          Q          K          A          2          3          4          5          6          7          8          9         10          J          Q          K          A          2          3          4          5          6          7          8          9         10          J          Q          K          A          2          3          4          5          6          7          8          9         10          J          Q          K  ",
            "                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ",
        };

        Assert::That(actualParsed, EqualsContainer(expected));
    }
};



int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}




