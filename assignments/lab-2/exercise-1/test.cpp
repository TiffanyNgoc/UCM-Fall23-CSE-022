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

Context(TestSonnet){
    static void SetUpContext(){
        exec("g++ main.cpp -o temp");
    }
    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(SonnetOne){
        std::string result = compile_run("main.cpp");
         Assert::That(result, Equals(".--------------------------------------------------------.\n|                                                        |\n| Sonnet 120: That You Were Once Unkind Befriends Me Now |\n|                                                        |\n| ------------------------------------------------------ |\n|                                                        |\n| That you were once unkind befriends me now,            |\n| And for that sorrow, which I then did feel,            |\n| Needs must I under my transgression bow,               |\n| Unless my nerves were brass or hammer'd steel.         |\n|                                                        |\n| For if you were by my unkindness shaken,               |\n| As I by yours, you've passed a hell of time;           |\n| And I, a tyrant, have no leisure taken                 |\n| To weigh how once I suffered in your crime.            |\n|                                                        |\n| O! that our night of woe might have remembered         |\n| My deepest sense, how hard true sorrow hits,           |\n| And soon to you, as you to me, then tendered           |\n| The humble salve, which wounded bosoms fits!           |\n|                                                        |\n|     But that your trespass now becomes a fee;          |\n|     Mine ransoms yours, and yours must ransom me.      |\n|                                                        |\n| ------------------------------------------------------ |\n|                                  - William Shakespeare |\n.--------------------------------------------------------."));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
