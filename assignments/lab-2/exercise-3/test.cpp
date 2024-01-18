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

Context(TestPostcard){
    static void SetUpContext(){
        exec("g++ main.cpp -o temp");
    }
    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(PostcardOne){
        std::string result = compile_run("main.cpp");
        Assert::That(result, Equals(".----------------------------------------------------------------------------------------.\n| Ruth Williams                                                                .-------. |\n| 9096 Riverside Drive                                                         | STAMP | |\n| Los Angeles, CA 90006                                                        .-------. |\n|                                                                                        |\n|                                                                                        |\n| Dear Trudy Johnson,                                                                    |\n|                                                                                        |\n| Greetings from sunny Hawaii! I hope this postcard finds you well. I wanted to share a  |\n| glimpse of the breathtaking beach I'm lounging on right now. The sand is warm, the     |\n| water crystal clear, and the palm trees sway in the gentle breeze. It's like paradise  |\n| here!                                                                                  |\n|                                                                                        |\n| I've been trying all the local cuisine, from fresh pineapple to delicious seafood.     |\n| Yesterday, I even tried surfing for the first time - quite an adventure! I'm also      |\n| meeting wonderful people and soaking up the Hawaiian culture.                          |\n|                                                                                        |\n| Wish you were here to enjoy this tropical paradise with me. Sending you warm wishes    |\n| from afar. Can't wait to catch up and share more stories when I'm back.                |\n|                                                                                        |\n| Take care!                                                                             |\n|                                                                                        |\n| Warmest regards,                                                                       |\n|                                                                                        |\n| Ruth Williams                                                                          |\n|                                                                                        |\n|                                                                                        |\n|                                                                   Trudy Johnson        |\n|                                                                   8489 Fairview Street |\n|                                                                   Paramount, CA 90723  |\n.----------------------------------------------------------------------------------------."));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
