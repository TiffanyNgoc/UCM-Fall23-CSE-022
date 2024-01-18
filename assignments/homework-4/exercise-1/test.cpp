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

Context(TextProgram){
    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(GenerateThreeOneToTen){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){12, 7, 1, 11, 3, 2, 6, 5, 3, 12, 4, 4, 7, 3, 1}' -DMAX='(int[]){15, 15, 4, 15, 15, 4, 15, 15, 4, 15, 15, 4, 15, 15, 4}' -DMIN='(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}'");
        std::string allCorrect = exec("echo 19 8 30 3 10 | ./temp");
        Assert::That(allCorrect, Equals("Question 1: 12 + 7 = That is correct!\n\nQuestion 2: 11 - 3 = That is correct!\n\nQuestion 3: 6 * 5 = That is correct!\n\nQuestion 4: 12 / 4 = That is correct!\n\nQuestion 5: 7 + 3 = That is correct!"));

        std::string lastIncorrect = exec("echo 19 8 30 3 6 | ./temp");
        Assert::That(lastIncorrect, Equals("Question 1: 12 + 7 = That is correct!\n\nQuestion 2: 11 - 3 = That is correct!\n\nQuestion 3: 6 * 5 = That is correct!\n\nQuestion 4: 12 / 4 = That is correct!\n\nQuestion 5: 7 + 3 = That is incorrect. The correct answer is: 10"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}