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
        std::string result = exec("echo '10.6994\n73.5\n134\n72' | ./temp");
        Assert::That(result, Equals("14.1878"));
    }

    Spec(Test_2){
        std::string result = exec("echo '8.558\n71.9\n140\n72' | ./temp");
        Assert::That(result, Equals("10.5028"));
    }

    Spec(Test_3){
        std::string result = exec("echo '12.926\n74.8\n128\n72' | ./temp");
        Assert::That(result, Equals("17.4418"));
    }

    Spec(ExecutableInstalled){
        std::string result = exec("ls ~/bin | grep gcoursehandicap");
        Assert::That(result, Equals("gcoursehandicap"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}





