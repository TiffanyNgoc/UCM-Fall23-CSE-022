#include <igloo/igloo.h>
#include <iostream>
#include <fstream>
#include "ucm_utils.h"

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
        system("rm -rf temp test.txt");
    }

    Spec(UCMercedL){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("UC Merced", 'l');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=============\nUC Merced    \n============="));
    }

    Spec(UCMercedM){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("UC Merced", 'm');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=================\n    UC Merced    \n================="));
    }

    Spec(UCMercedR){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("UC Merced", 'r');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=============\n    UC Merced\n============="));
    }

    Spec(UCMercedP){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("UC Merced", 'p');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=============\nUC Merced    \n============="));
    }

    Spec(CSE22L){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("CSE22", 'l');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=========\nCSE22    \n========="));
    }

    Spec(CSE22M){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("CSE22", 'm');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=============\n    CSE22    \n============="));
    }

    Spec(CSE22R){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("CSE22", 'r');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=========\n    CSE22\n========="));
    }

    Spec(CSE22P){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        alignedHeader("CSE22", 'p');

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=========\nCSE22    \n========="));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}