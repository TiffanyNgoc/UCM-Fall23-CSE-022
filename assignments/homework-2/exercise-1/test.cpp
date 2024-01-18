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
        std::string result = exec("echo '5\n6\n6\n2\n4\n4\n6\n3\n5\n5\n4\n5\n7\n3\n4\n5\n3\n5\n70.1\n127' | ./temp");
        Assert::That(result, Equals("10.5882"));
    }

    Spec(Test_2){
        std::string result = exec("echo '4\n4\n5\n3\n5\n4\n5\n4\n6\n5\n2\n4\n4\n4\n4\n6\n5\n5\n70.1\n127' | ./temp");
        Assert::That(result, Equals("7.9189"));
    }

    Spec(Test_3){
        std::string result = exec("echo '4\n4\n3\n3\n8\n3\n5\n5\n6\n5\n4\n3\n4\n4\n5\n5\n4\n6\n70.1\n127' | ./temp");
        Assert::That(result, Equals("9.69843"));
    }

    Spec(Test_4){
        std::string result = exec("echo '4\n4\n5\n4\n6\n4\n7\n4\n6\n5\n4\n5\n4\n4\n4\n5\n3\n5\n70.1\n127' | ./temp");
        Assert::That(result, Equals("11.478"));
    }

    Spec(ExecutableInstalled){
        std::string result = exec("ls ~/bin | grep gdifferential");
        Assert::That(result, Equals("gdifferential"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}