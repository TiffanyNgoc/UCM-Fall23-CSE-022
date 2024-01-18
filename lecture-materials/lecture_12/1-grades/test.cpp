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

    Spec(Test_1){
        std::string result = exec("echo '-1' | ./temp");
        Assert::That(result, Equals("Invalid grade"));
    }
    Spec(Test_2){
        std::string result = exec("echo '0' | ./temp");
        Assert::That(result, Equals("F"));
    }
    Spec(Test_3){
        std::string result = exec("echo '59.9' | ./temp");
        Assert::That(result, Equals("F"));
    }
    Spec(Test_4){
        std::string result = exec("echo '60' | ./temp");
        Assert::That(result, Equals("D"));
    }
    Spec(Test_5){
        std::string result = exec("echo '69.9' | ./temp");
        Assert::That(result, Equals("D"));
    }
    Spec(Test_6){
        std::string result = exec("echo '70' | ./temp");
        Assert::That(result, Equals("C"));
    }
    Spec(Test_7){
        std::string result = exec("echo '79.9' | ./temp");
        Assert::That(result, Equals("C"));
    }
    Spec(Test_8){
        std::string result = exec("echo '80' | ./temp");
        Assert::That(result, Equals("B"));
    }
    Spec(Test_9){
        std::string result = exec("echo '89.9' | ./temp");
        Assert::That(result, Equals("B"));
    }
    Spec(Test_10){
        std::string result = exec("echo '90' | ./temp");
        Assert::That(result, Equals("A"));
    }
    Spec(Test_11){
        std::string result = exec("echo '100' | ./temp");
        Assert::That(result, Equals("A"));
    }
    Spec(Test_12){
        std::string result = exec("echo '100.1' | ./temp");
        Assert::That(result, Equals("Invalid grade"));
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}