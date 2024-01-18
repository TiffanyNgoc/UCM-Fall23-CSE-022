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
        std::string result = exec("echo '1\n1\n2023' | ./temp");
        Assert::That(result, Equals("January 1st, 2023"));
    }
    Spec(Test_2){
        std::string result = exec("echo '1\n2\n2023' | ./temp");
        Assert::That(result, Equals("January 2nd, 2023"));
    }
    Spec(Test_3){
        std::string result = exec("echo '1\n3\n2023' | ./temp");
        Assert::That(result, Equals("January 3rd, 2023"));
    }
    Spec(Test_4){
        std::string result = exec("echo '1\n4\n2023' | ./temp");
        Assert::That(result, Equals("January 4th, 2023"));
    }
    Spec(Test_5){
        std::string result = exec("echo '1\n21\n2023' | ./temp");
        Assert::That(result, Equals("January 21st, 2023"));
    }
    Spec(Test_6){
        std::string result = exec("echo '1\n22\n2023' | ./temp");
        Assert::That(result, Equals("January 22nd, 2023"));
    }
    Spec(Test_7){
        std::string result = exec("echo '1\n23\n2023' | ./temp");
        Assert::That(result, Equals("January 23rd, 2023"));
    }
    Spec(Test_8){
        std::string result = exec("echo '1\n31\n2023' | ./temp");
        Assert::That(result, Equals("January 31st, 2023"));
    }


    Spec(Test_9){
        std::string result = exec("echo '1\n5\n2023' | ./temp");
        Assert::That(result, Equals("January 5th, 2023"));
    }
    Spec(Test_10){
        std::string result = exec("echo '2\n6\n2023' | ./temp");
        Assert::That(result, Equals("February 6th, 2023"));
    }
    Spec(Test_11){
        std::string result = exec("echo '3\n7\n2023' | ./temp");
        Assert::That(result, Equals("March 7th, 2023"));
    }
    Spec(Test_12){
        std::string result = exec("echo '4\n8\n2023' | ./temp");
        Assert::That(result, Equals("April 8th, 2023"));
    }
    Spec(Test_13){
        std::string result = exec("echo '5\n9\n2023' | ./temp");
        Assert::That(result, Equals("May 9th, 2023"));
    }
    Spec(Test_14){
        std::string result = exec("echo '6\n10\n2023' | ./temp");
        Assert::That(result, Equals("June 10th, 2023"));
    }
    Spec(Test_15){
        std::string result = exec("echo '7\n11\n2023' | ./temp");
        Assert::That(result, Equals("July 11th, 2023"));
    }
    Spec(Test_16){
        std::string result = exec("echo '8\n12\n2023' | ./temp");
        Assert::That(result, Equals("August 12th, 2023"));
    }
    Spec(Test_17){
        std::string result = exec("echo '9\n13\n2023' | ./temp");
        Assert::That(result, Equals("September 13th, 2023"));
    }
    Spec(Test_18){
        std::string result = exec("echo '10\n14\n2023' | ./temp");
        Assert::That(result, Equals("October 14th, 2023"));
    }
    Spec(Test_19){
        std::string result = exec("echo '11\n15\n2023' | ./temp");
        Assert::That(result, Equals("November 15th, 2023"));
    }
    Spec(Test_20){
        std::string result = exec("echo '12\n16\n2023' | ./temp");
        Assert::That(result, Equals("December 16th, 2023"));
    }
    Spec(Test_21){
        std::string result = exec("echo '1\n17\n2023' | ./temp");
        Assert::That(result, Equals("January 17th, 2023"));
    }
    Spec(Test_22){
        std::string result = exec("echo '2\n18\n2023' | ./temp");
        Assert::That(result, Equals("February 18th, 2023"));
    }
    Spec(Test_23){
        std::string result = exec("echo '3\n19\n2023' | ./temp");
        Assert::That(result, Equals("March 19th, 2023"));
    }
    Spec(Test_24){
        std::string result = exec("echo '4\n20\n2023' | ./temp");
        Assert::That(result, Equals("April 20th, 2023"));
    }
    Spec(Test_25){
        std::string result = exec("echo '5\n24\n2023' | ./temp");
        Assert::That(result, Equals("May 24th, 2023"));
    }
    Spec(Test_26){
        std::string result = exec("echo '6\n25\n2023' | ./temp");
        Assert::That(result, Equals("June 25th, 2023"));
    }
    Spec(Test_27){
        std::string result = exec("echo '7\n26\n2023' | ./temp");
        Assert::That(result, Equals("July 26th, 2023"));
    }
    Spec(Test_28){
        std::string result = exec("echo '8\n27\n2023' | ./temp");
        Assert::That(result, Equals("August 27th, 2023"));
    }
    Spec(Test_29){
        std::string result = exec("echo '9\n28\n2023' | ./temp");
        Assert::That(result, Equals("September 28th, 2023"));
    }
    Spec(Test_30){
        std::string result = exec("echo '10\n29\n2023' | ./temp");
        Assert::That(result, Equals("October 29th, 2023"));
    }
    Spec(Test_31){
        std::string result = exec("echo '11\n30\n2023' | ./temp");
        Assert::That(result, Equals("November 30th, 2023"));
    }


    Spec(Test_32){
        std::string result = exec("echo '2\n29\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }
    Spec(Test_33){
        std::string result = exec("echo '4\n31\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }
    Spec(Test_34){
        std::string result = exec("echo '6\n31\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }
    Spec(Test_35){
        std::string result = exec("echo '9\n31\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }
    Spec(Test_36){
        std::string result = exec("echo '11\n31\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }


    Spec(Test_37){
        std::string result = exec("echo '0\n1\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }
    Spec(Test_38){
        std::string result = exec("echo '13\n1\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }

    Spec(Test_39){
        std::string result = exec("echo '1\n32\n2023' | ./temp");
        Assert::That(result, Equals("Invalid date"));
    }

    
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}