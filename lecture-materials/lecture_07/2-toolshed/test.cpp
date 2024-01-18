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

std::string compile_run(std::string filename){
    std::string compile = exec("g++ -o temp " + filename);
    std::string output = compile;
    if (compile == ""){
        output = exec("./temp");
        system("rm -f temp");
    }

    return output;
}

std::string compile_run(std::string filename, std::string input){
    std::string compile = exec("g++ -o temp " + filename);
    std::string output = compile;
    if (compile == ""){
        output = exec("echo \"" + input + "\" | ./temp");
        system("rm -f temp");
    }

    return output;
}

std::string run_executable(std::string input) {
    std::string output = exec("echo \"" + input + "\" | ./temp");
    return output;
}

Context(TestToolshedCalculator){
    static void SetUpContext(){
        exec("g++ main.cpp -o temp");
    }
    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(Test8x6x8_1_5){
        std::string result = run_executable("8 6 8 1.5");
         Assert::That(result, Equals("$336"));
    }
    Spec(Test8x6x8_1_25){
        std::string result = run_executable("8 6 8 1.25");
         Assert::That(result, Equals("$280"));
    }
    Spec(Test8x8x8_1_25){
        std::string result = run_executable("8 8 8 1.25");
         Assert::That(result, Equals("$320"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
