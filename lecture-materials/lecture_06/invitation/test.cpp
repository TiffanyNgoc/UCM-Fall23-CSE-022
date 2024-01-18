#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>

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

std::string run_executable(std::string input) {
    std::string output = exec("echo \"" + input + "\" | ./temp");
    return output;
}

Context(TestProgram) {
    static void SetUpContext(){
        exec("g++ main.cpp -o temp");
    }

    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(Test_1){
        std::string result = run_executable("Alice");
        Assert::That(result, Equals("Dear Alice,\n\nI'm excited to invite you to my birthday party!\n\nDate: Saturday, September 16th\nLocation: 5200 Lake Road\nTime: 3PM - 10PM\n\nPlease RSVP by September 13th to:\nEmail: jane96@gmail.com\nPhone: 209-123-4567\n\nSincerely,\n\nJane"));
    }

    Spec(Test_2){
        std::string result = run_executable("Bob");
        Assert::That(result, Equals("Dear Bob,\n\nI'm excited to invite you to my birthday party!\n\nDate: Saturday, September 16th\nLocation: 5200 Lake Road\nTime: 3PM - 10PM\n\nPlease RSVP by September 13th to:\nEmail: jane96@gmail.com\nPhone: 209-123-4567\n\nSincerely,\n\nJane"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}