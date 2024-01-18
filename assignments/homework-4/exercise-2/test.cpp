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
    Spec(EvenOnly){
        std::string result = exec("echo 2 4 6 8 10 12 14 16 18 20 | ./temp");
        Assert::That(result, Equals("There were 10 even numbers\nThere were no odd numbers"));
    }

    Spec(OddOnly){
        std::string result = exec("echo 1 3 5 7 9 11 13 15 17 19 | ./temp");
        Assert::That(result, Equals("There were no even numbers\nThere were 10 odd numbers"));
    }

    Spec(FourEvenSixOdd){
        std::string result = exec("echo 2 4 6 8 21 31 41 51 61 71 | ./temp");
        Assert::That(result, Equals("There were 4 even numbers\nThere were 6 odd numbers"));
    }

    Spec(EightEvenTwoOdd){
        std::string result = exec("echo 10 20 30 40 50 60 70 80 91 101 | ./temp");
        Assert::That(result, Equals("There were 8 even numbers\nThere were 2 odd numbers"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}