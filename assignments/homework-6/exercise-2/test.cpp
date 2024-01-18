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

    Spec(UCMerced10){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        widthControlledHeader("UC Merced", 10);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("==========\n| UC ... |\n=========="));
    }

    Spec(UCMerced13){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        widthControlledHeader("UC Merced", 13);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("=============\n| UC Merced |\n============="));
    }

    Spec(UCMerced30){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        widthControlledHeader("UC Merced", 30);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("==============================\n| UC Merced                  |\n=============================="));
    }

    Spec(CSE22IntroductionToProgramming10){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        widthControlledHeader("CSE 22: Introduction to Programming", 10);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("==========\n| CSE... |\n=========="));
    }

    Spec(CSE22IntroductionToProgramming15){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        widthControlledHeader("CSE 22: Introduction to Programming", 15);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("===============\n| CSE 22: ... |\n==============="));
    }

    Spec(CSE22IntroductionToProgramming30){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        widthControlledHeader("CSE 22: Introduction to Programming", 30);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        Assert::That(exec("cat test.txt"), Equals("==============================\n| CSE 22: Introduction to... |\n=============================="));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}