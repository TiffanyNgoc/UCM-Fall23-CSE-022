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
        std::string result = exec("echo '10.5882\n7.9189\n10.5882\n11.478\n12.3677\n11.478\n11.478\n9.69843' | ./temp");
        Assert::That(result, Equals("10.6994"));
    }

    Spec(Test_2){
        std::string result = exec("echo '9.116\n13.867\n5.785\n10.448\n7.221\n8.927\n14.259\n13.278' | ./temp");
        Assert::That(result, Equals("10.3626"));
    }

    Spec(Test_3){
        std::string result = exec("echo '7.023\n6.489\n7.709\n10.701\n8.373\n13.734\n7.809\n6.236' | ./temp");
        Assert::That(result, Equals("8.50925"));
    }

    Spec(ExecutableInstalled){
        std::string result = exec("ls ~/bin | grep ghandicap");
        Assert::That(result, Equals("ghandicap"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}