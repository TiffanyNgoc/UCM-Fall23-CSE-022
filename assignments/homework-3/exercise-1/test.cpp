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
        Assert::That(result, Equals("D-"));
    }
    Spec(Test_5){
        std::string result = exec("echo '62.9' | ./temp");
        Assert::That(result, Equals("D-"));
    }
    Spec(Test_6){
        std::string result = exec("echo '63' | ./temp");
        Assert::That(result, Equals("D"));
    }
    Spec(Test_7){
        std::string result = exec("echo '66.9' | ./temp");
        Assert::That(result, Equals("D"));
    }
    Spec(Test_8){
        std::string result = exec("echo '67' | ./temp");
        Assert::That(result, Equals("D+"));
    }
    Spec(Test_9){
        std::string result = exec("echo '69.9' | ./temp");
        Assert::That(result, Equals("D+"));
    }

    Spec(Test_10){
        std::string result = exec("echo '70' | ./temp");
        Assert::That(result, Equals("C-"));
    }
    Spec(Test_11){
        std::string result = exec("echo '72.9' | ./temp");
        Assert::That(result, Equals("C-"));
    }
    Spec(Test_12){
        std::string result = exec("echo '73' | ./temp");
        Assert::That(result, Equals("C"));
    }
    Spec(Test_13){
        std::string result = exec("echo '76.9' | ./temp");
        Assert::That(result, Equals("C"));
    }
    Spec(Test_14){
        std::string result = exec("echo '77' | ./temp");
        Assert::That(result, Equals("C+"));
    }
    Spec(Test_15){
        std::string result = exec("echo '79.9' | ./temp");
        Assert::That(result, Equals("C+"));
    }

    Spec(Test_16){
        std::string result = exec("echo '80' | ./temp");
        Assert::That(result, Equals("B-"));
    }
    Spec(Test_17){
        std::string result = exec("echo '82.9' | ./temp");
        Assert::That(result, Equals("B-"));
    }
    Spec(Test_18){
        std::string result = exec("echo '83' | ./temp");
        Assert::That(result, Equals("B"));
    }
    Spec(Test_19){
        std::string result = exec("echo '86.9' | ./temp");
        Assert::That(result, Equals("B"));
    }
    Spec(Test_20){
        std::string result = exec("echo '87' | ./temp");
        Assert::That(result, Equals("B+"));
    }
    Spec(Test_21){
        std::string result = exec("echo '89.9' | ./temp");
        Assert::That(result, Equals("B+"));
    }

    Spec(Test_22){
        std::string result = exec("echo '90' | ./temp");
        Assert::That(result, Equals("A-"));
    }
    Spec(Test_23){
        std::string result = exec("echo '92.9' | ./temp");
        Assert::That(result, Equals("A-"));
    }
    Spec(Test_24){
        std::string result = exec("echo '93' | ./temp");
        Assert::That(result, Equals("A"));
    }
    Spec(Test_25){
        std::string result = exec("echo '96.9' | ./temp");
        Assert::That(result, Equals("A"));
    }
    Spec(Test_26){
        std::string result = exec("echo '97' | ./temp");
        Assert::That(result, Equals("A+"));
    }
    Spec(Test_27){
        std::string result = exec("echo '100' | ./temp");
        Assert::That(result, Equals("A+"));
    }

    Spec(Test_28){
        std::string result = exec("echo '100.1' | ./temp");
        Assert::That(result, Equals("Invalid grade"));
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}