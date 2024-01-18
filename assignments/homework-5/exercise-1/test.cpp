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

    Spec(Test_1){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){1, 15, 1, 13, 15, 5, 3, 11, 2, 10, 11, 2, 1, 7, 4}' -DMIN='(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}' -DMAX='(int[]){15, 15, 5, 15, 15, 5, 15, 15, 5, 15, 15, 5, 15, 15, 5}'");
        std::string result = exec("echo 16 13 -8 -1 0 | ./temp");
        Assert::That(result, Equals("1. 1 + 15 = \n2. 13 % 15 = \n3. 3 - 11 = \n4. 10 - 11 = \n5. 1 / 7 = \nQuestion 1 took you 1 attempts.\nQuestion 2 took you 1 attempts.\nQuestion 3 took you 1 attempts.\nQuestion 4 took you 1 attempts.\nQuestion 5 took you 1 attempts."));
    }

    Spec(Test_2){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){6, 12, 4, 4, 12, 4, 10, 15, 4, 6, 2, 3, 14, 3, 5}' -DMIN='(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}' -DMAX='(int[]){15, 15, 5, 15, 15, 5, 15, 15, 5, 15, 15, 5, 15, 15, 5}'");
        std::string result = exec("echo 1 2 3 0 0 0 12 2 | ./temp");
        Assert::That(result, Equals("1. 6 / 12 = 1. 6 / 12 = 1. 6 / 12 = 1. 6 / 12 = \n2. 4 / 12 = \n3. 10 / 15 = \n4. 6 * 2 = \n5. 14 % 3 = \nQuestion 1 took you 4 attempts.\nQuestion 2 took you 1 attempts.\nQuestion 3 took you 1 attempts.\nQuestion 4 took you 1 attempts.\nQuestion 5 took you 1 attempts."));
    }

    Spec(Test_3){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){1, 2, 1, 3, 4, 2, 5, 6, 3, 7, 8, 4, 9, 10, 5}' -DMIN='(int[]){1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}' -DMAX='(int[]){15, 15, 5, 15, 15, 5, 15, 15, 5, 15, 15, 5, 15, 15, 5}'");
        std::string result = exec("echo 3 1 -1 30 1 0 1 2 3 4 5 6 7 8 9| ./temp");
        Assert::That(result, Equals("1. 1 + 2 = \n2. 3 - 4 = 2. 3 - 4 = \n3. 5 * 6 = \n4. 7 / 8 = 4. 7 / 8 = \n5. 9 % 10 = 5. 9 % 10 = 5. 9 % 10 = 5. 9 % 10 = 5. 9 % 10 = 5. 9 % 10 = 5. 9 % 10 = 5. 9 % 10 = 5. 9 % 10 = \nQuestion 1 took you 1 attempts.\nQuestion 2 took you 2 attempts.\nQuestion 3 took you 1 attempts.\nQuestion 4 took you 2 attempts.\nQuestion 5 took you 9 attempts."));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}