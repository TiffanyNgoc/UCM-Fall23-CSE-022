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
    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(Test_10_7){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){7}' -DMIN='(int[]){1}' -DMAX='(int[]){10}'");
        std::string result = exec("echo 10 5 7 | ./temp");
        Assert::That(result, Equals("Enter guess [1..10]: Go higher\n\nEnter guess [1..10]: \nIt requires 4 attempts to guarantee success. You got lucky and guessed it in 2."));
    }

    Spec(Test_100_42){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){42}' -DMIN='(int[]){1}' -DMAX='(int[]){100}'");
        std::string result = exec("echo 100 50 25 40 45 44 43 42 | ./temp");
        Assert::That(result, Equals("Enter guess [1..100]: Go lower\n\nEnter guess [1..100]: Go higher\n\nEnter guess [1..100]: Go higher\n\nEnter guess [1..100]: Go lower\n\nEnter guess [1..100]: Go lower\n\nEnter guess [1..100]: Go lower\n\nEnter guess [1..100]: \nYou got it in 7 attempts, which is the minimum number of attempts required to guarantee success."));
    }

    Spec(Test_100_889){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){889}' -DMIN='(int[]){1}' -DMAX='(int[]){1000}'");
        std::string result = exec("echo 1000 500 700 900 800 850 875 890 880 885 888 889 | ./temp");
        Assert::That(result, Equals("Enter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: Go lower\n\nEnter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: Go lower\n\nEnter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: Go higher\n\nEnter guess [1..1000]: \nYou got it in 11 attempts, but it could have been done in 10."));
    }


    Spec(Test_10000_1){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){7}' -DMIN='(int[]){1}' -DMAX='(int[]){10000}'");
        std::string result = exec("echo 10000 5000 2500 1000 500 250 100 | ./temp");
        Assert::That(result, Equals("Enter guess [1..10000]: Go lower\n\nEnter guess [1..10000]: Go lower\n\nEnter guess [1..10000]: Go lower\n\nEnter guess [1..10000]: Go lower\n\nEnter guess [1..10000]: Go lower\n\nEnter guess [1..10000]: Go lower\n\nEnter guess [1..10000]: \n\nBetter luck next time.\nThe number was 7."));
    }

   Spec(Test_1_Invalid){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){1}' -DMIN='(int[]){1}' -DMAX='(int[]){1}'");
        std::string result = exec("echo 1 | ./temp");
        Assert::That(result, Equals("Invalid upper limit."));
    }

};


int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}