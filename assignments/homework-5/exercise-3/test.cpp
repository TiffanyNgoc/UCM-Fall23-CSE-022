#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

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

Context(TestProgram) {
    static void SetUpContext(){
        exec("g++ main.cpp -o temp");
    }

    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(Test_APPLE){
        std::string result = exec("echo 'APPLE A P L E' | ./temp");
        Assert::That(result, Equals("\nEnter a letter: A _ _ _ _\n\nLetters: A\nEnter a letter: A P P _ _\n\nLetters: A, P\nEnter a letter: A P P L _\n\nLetters: A, P, L\nEnter a letter: A P P L E\n\nGreat job!"));
    }

    Spec(Test_MACBOOK){
        std::string result = exec("echo 'MACBOOK a b c d e f g h i j k l m n o' | ./temp");
        Assert::That(result, Equals("\nEnter a letter: _ A _ _ _ _ _\n\nLetters: A\nEnter a letter: _ A _ B _ _ _\n\nLetters: A, B\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C, D\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C, D, E\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C, D, E, F\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C, D, E, F, G\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C, D, E, F, G, H\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C, D, E, F, G, H, I\nEnter a letter: _ A C B _ _ _\n\nLetters: A, B, C, D, E, F, G, H, I, J\nEnter a letter: _ A C B _ _ K\n\nLetters: A, B, C, D, E, F, G, H, I, J, K\nEnter a letter: _ A C B _ _ K\n\nLetters: A, B, C, D, E, F, G, H, I, J, K, L\nEnter a letter: M A C B _ _ K\n\nLetters: A, B, C, D, E, F, G, H, I, J, K, L, M\nEnter a letter: M A C B _ _ K\n\nLetters: A, B, C, D, E, F, G, H, I, J, K, L, M, N\nEnter a letter: M A C B O O K\n\nGreat job!"));
    }

    Spec(Test_golf){
        std::string result = exec("echo 'golf F L O G' | ./temp");
        Assert::That(result, Equals("\nEnter a letter: _ _ _ F\n\nLetters: F\nEnter a letter: _ _ L F\n\nLetters: F, L\nEnter a letter: _ O L F\n\nLetters: F, L, O\nEnter a letter: G O L F\n\nGreat job!"));
    }

    Spec(Test_iPhone){
        std::string result = exec("echo 'iPhone a B c D e F g H i J k L m N' | ./temp");
        Assert::That(result, Equals("\nEnter a letter: _ _ _ _ _ _\n\nLetters: A\nEnter a letter: _ _ _ _ _ _\n\nLetters: A, B\nEnter a letter: _ _ _ _ _ _\n\nLetters: A, B, C\nEnter a letter: _ _ _ _ _ _\n\nLetters: A, B, C, D\nEnter a letter: _ _ _ _ _ E\n\nLetters: A, B, C, D, E\nEnter a letter: _ _ _ _ _ E\n\nLetters: A, B, C, D, E, F\nEnter a letter: _ _ _ _ _ E\n\nLetters: A, B, C, D, E, F, G\nEnter a letter: _ _ H _ _ E\n\nLetters: A, B, C, D, E, F, G, H\nEnter a letter: I _ H _ _ E\n\nLetters: A, B, C, D, E, F, G, H, I\nEnter a letter: I _ H _ _ E\n\nLetters: A, B, C, D, E, F, G, H, I, J\nEnter a letter: I _ H _ _ E\n\nLetters: A, B, C, D, E, F, G, H, I, J, K\nEnter a letter: I _ H _ _ E\n\nLetters: A, B, C, D, E, F, G, H, I, J, K, L\nEnter a letter: I _ H _ _ E\n\nLetters: A, B, C, D, E, F, G, H, I, J, K, L, M\nEnter a letter: I _ H _ N E\n\nLetters: A, B, C, D, E, F, G, H, I, J, K, L, M, N\nEnter a letter: \n\nBetter luck next time!\nThe word was: IPHONE"));
    }

    Spec(Test_Bobcats){
        std::string result = exec("echo 'Bobcats b b s t c a a a o' | ./temp");
        Assert::That(result, Equals("\nEnter a letter: B _ B _ _ _ _\n\nLetters: B\nEnter a letter: B _ B _ _ _ _\n\nLetters: B\nEnter a letter: B _ B _ _ _ S\n\nLetters: B, S\nEnter a letter: B _ B _ _ T S\n\nLetters: B, S, T\nEnter a letter: B _ B C _ T S\n\nLetters: B, S, T, C\nEnter a letter: B _ B C A T S\n\nLetters: B, S, T, C, A\nEnter a letter: B _ B C A T S\n\nLetters: B, S, T, C, A\nEnter a letter: B _ B C A T S\n\nLetters: B, S, T, C, A\nEnter a letter: B O B C A T S\n\nGreat job!"));
    }

    Spec(Test_SpOnGeBoB){
        std::string result = exec("echo 'SpOnGeBoB a E i O u S g t g p g' | ./temp");
        Assert::That(result, Equals("\nEnter a letter: _ _ _ _ _ _ _ _ _\n\nLetters: A\nEnter a letter: _ _ _ _ _ E _ _ _\n\nLetters: A, E\nEnter a letter: _ _ _ _ _ E _ _ _\n\nLetters: A, E, I\nEnter a letter: _ _ O _ _ E _ O _\n\nLetters: A, E, I, O\nEnter a letter: _ _ O _ _ E _ O _\n\nLetters: A, E, I, O, U\nEnter a letter: S _ O _ _ E _ O _\n\nLetters: A, E, I, O, U, S\nEnter a letter: S _ O _ G E _ O _\n\nLetters: A, E, I, O, U, S, G\nEnter a letter: S _ O _ G E _ O _\n\nLetters: A, E, I, O, U, S, G, T\nEnter a letter: S _ O _ G E _ O _\n\nLetters: A, E, I, O, U, S, G, T\nEnter a letter: S P O _ G E _ O _\n\nLetters: A, E, I, O, U, S, G, T, P\nEnter a letter: S P O _ G E _ O _\n\nLetters: A, E, I, O, U, S, G, T, P\nEnter a letter: \n\nBetter luck next time!\nThe word was: SPONGEBOB"));
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}