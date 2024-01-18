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
        std::string result = exec("echo '18\n120000' | ./temp");
        Assert::That(result, Equals("2.25% rate"));
    }
    Spec(Test_2){
        std::string result = exec("echo '24\n125000' | ./temp");
        Assert::That(result, Equals("2.25% rate"));
    }
    Spec(Test_3){
        std::string result = exec("echo '25\n130000' | ./temp");
        Assert::That(result, Equals("2.25% rate"));
    }
    Spec(Test_4){
        std::string result = exec("echo '64\n135000' | ./temp");
        Assert::That(result, Equals("2.25% rate"));
    }
    Spec(Test_5){
        std::string result = exec("echo '65\n140000' | ./temp");
        Assert::That(result, Equals("2.25% rate"));
    }
    Spec(Test_6){
        std::string result = exec("echo '18\n20000' | ./temp");
        Assert::That(result, Equals("7.25% rate"));
    }
    Spec(Test_7){
        std::string result = exec("echo '24\n25000' | ./temp");
        Assert::That(result, Equals("7.25% rate"));
    }
    Spec(Test_8){
        std::string result = exec("echo '25\n30000' | ./temp");
        Assert::That(result, Equals("5.25% rate"));
    }
    Spec(Test_9){
        std::string result = exec("echo '64\n35000' | ./temp");
        Assert::That(result, Equals("5.25% rate"));
    }
    Spec(Test_10){
        std::string result = exec("echo '65\n40000' | ./temp");
        Assert::That(result, Equals("3.25% rate"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}