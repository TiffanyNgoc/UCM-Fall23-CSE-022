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

    Spec(Test_01) {
        std::string result = exec("echo 'Monday\nMorning\n18\n1\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Monday\nTime: Morning\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $45\nCart Fee:     $20\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $87"));
    }

    Spec(Test_02) {
        std::string result = exec("echo 'Monday\nAfternoon\n18\n1\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Monday\nTime: Afternoon\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $30\nCart Fee:     $20\nRental Clubs: $15\nTotal:        $65"));
    }

    Spec(Test_03) {
        std::string result = exec("echo 'Monday\nTwilight\n18\n1\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Monday\nTime: Twilight\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $25\nCart Fee:     $20\nRange Balls:  $7\nTotal:        $52"));
    }

    Spec(Test_04) {
        std::string result = exec("echo 'Monday\nMorning\n9\n0\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Monday\nTime: Morning\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $22.5\nCart Fee:     $0\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $44.5"));
    }

    Spec(Test_05) {
        std::string result = exec("echo 'Monday\nAfternoon\n9\n1\n0\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Monday\nTime: Afternoon\nHoles: 9\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $15\nCart Fee:     $10\nTotal:        $25"));
    }

    Spec(Test_06) {
        std::string result = exec("echo 'Monday\nTwilight\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Monday\nTime: Twilight\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $12.5\nCart Fee:     $0\nRental Clubs: $15\nTotal:        $27.5"));
    }

    Spec(Test_07) {
        std::string result = exec("echo 'Tuesday\nMorning\n18\n1\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Tuesday\nTime: Morning\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $45\nCart Fee:     $20\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $87"));
    }

    Spec(Test_08) {
        std::string result = exec("echo 'Tuesday\nAfternoon\n18\n1\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Tuesday\nTime: Afternoon\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $30\nCart Fee:     $20\nRental Clubs: $15\nTotal:        $65"));
    }

    Spec(Test_09) {
        std::string result = exec("echo 'Tuesday\nTwilight\n18\n1\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Tuesday\nTime: Twilight\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $25\nCart Fee:     $20\nRange Balls:  $7\nTotal:        $52"));
    }

    Spec(Test_10) {
        std::string result = exec("echo 'Tuesday\nMorning\n9\n0\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Tuesday\nTime: Morning\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $22.5\nCart Fee:     $0\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $44.5"));
    }

    Spec(Test_11) {
        std::string result = exec("echo 'Tuesday\nAfternoon\n9\n1\n0\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Tuesday\nTime: Afternoon\nHoles: 9\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $15\nCart Fee:     $10\nTotal:        $25"));
    }

    Spec(Test_12) {
        std::string result = exec("echo 'Tuesday\nTwilight\n9\n0\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Tuesday\nTime: Twilight\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $12.5\nCart Fee:     $0\nRange Balls:  $7\nTotal:        $19.5"));
    }

    Spec(Test_13) {
        std::string result = exec("echo 'Wednesday\nMorning\n18\n1\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Wednesday\nTime: Morning\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $45\nCart Fee:     $20\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $87"));
    }

    Spec(Test_14) {
        std::string result = exec("echo 'Wednesday\nAfternoon\n18\n1\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Wednesday\nTime: Afternoon\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $30\nCart Fee:     $20\nRental Clubs: $15\nTotal:        $65"));
    }

    Spec(Test_15) {
        std::string result = exec("echo 'Wednesday\nTwilight\n18\n1\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Wednesday\nTime: Twilight\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $25\nCart Fee:     $20\nRange Balls:  $7\nTotal:        $52"));
    }

    Spec(Test_16) {
        std::string result = exec("echo 'Wednesday\nMorning\n9\n0\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Wednesday\nTime: Morning\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $22.5\nCart Fee:     $0\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $44.5"));
    }

    Spec(Test_17) {
        std::string result = exec("echo 'Wednesday\nAfternoon\n9\n1\n0\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Wednesday\nTime: Afternoon\nHoles: 9\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $15\nCart Fee:     $10\nTotal:        $25"));
    }

    Spec(Test_18) {
        std::string result = exec("echo 'Wednesday\nTwilight\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Wednesday\nTime: Twilight\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $12.5\nCart Fee:     $0\nRental Clubs: $15\nTotal:        $27.5"));
    }

    Spec(Test_19) {
        std::string result = exec("echo 'Thursday\nMorning\n18\n1\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Thursday\nTime: Morning\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $45\nCart Fee:     $20\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $87"));
    }

    Spec(Test_20) {
        std::string result = exec("echo 'Thursday\nAfternoon\n18\n1\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Thursday\nTime: Afternoon\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $30\nCart Fee:     $20\nRental Clubs: $15\nTotal:        $65"));
    }

    Spec(Test_21) {
        std::string result = exec("echo 'Thursday\nTwilight\n18\n1\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Thursday\nTime: Twilight\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $25\nCart Fee:     $20\nRange Balls:  $7\nTotal:        $52"));
    }

    Spec(Test_22) {
        std::string result = exec("echo 'Thursday\nMorning\n9\n0\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Thursday\nTime: Morning\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $22.5\nCart Fee:     $0\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $44.5"));
    }

    Spec(Test_23) {
        std::string result = exec("echo 'Thursday\nAfternoon\n9\n1\n0\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Thursday\nTime: Afternoon\nHoles: 9\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $15\nCart Fee:     $10\nTotal:        $25"));
    }

    Spec(Test_24) {
        std::string result = exec("echo 'Thursday\nTwilight\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Thursday\nTime: Twilight\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $12.5\nCart Fee:     $0\nRental Clubs: $15\nTotal:        $27.5"));
    }

    Spec(Test_25) {
        std::string result = exec("echo 'Friday\nMorning\n18\n1\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Friday\nTime: Morning\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $45\nCart Fee:     $20\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $87"));
    }

    Spec(Test_26) {
        std::string result = exec("echo 'Friday\nAfternoon\n18\n1\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Friday\nTime: Afternoon\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $30\nCart Fee:     $20\nRental Clubs: $15\nTotal:        $65"));
    }

    Spec(Test_27) {
        std::string result = exec("echo 'Friday\nTwilight\n18\n1\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Friday\nTime: Twilight\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $25\nCart Fee:     $20\nRange Balls:  $7\nTotal:        $52"));
    }

    Spec(Test_28) {
        std::string result = exec("echo 'Friday\nMorning\n9\n0\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Friday\nTime: Morning\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $22.5\nCart Fee:     $0\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $44.5"));
    }

    Spec(Test_29) {
        std::string result = exec("echo 'Friday\nAfternoon\n9\n1\n0\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Friday\nTime: Afternoon\nHoles: 9\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $15\nCart Fee:     $10\nTotal:        $25"));
    }

    Spec(Test_30) {
        std::string result = exec("echo 'Friday\nTwilight\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Friday\nTime: Twilight\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $12.5\nCart Fee:     $0\nRental Clubs: $15\nTotal:        $27.5"));
    }

    Spec(Test_31) {
        std::string result = exec("echo 'Saturday\nMorning\n18\n1\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Saturday\nTime: Morning\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $60\nCart Fee:     $20\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $102"));
    }

    Spec(Test_32) {
        std::string result = exec("echo 'Saturday\nAfternoon\n18\n1\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Saturday\nTime: Afternoon\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $40\nCart Fee:     $20\nRental Clubs: $15\nTotal:        $75"));
    }

    Spec(Test_33) {
        std::string result = exec("echo 'Saturday\nTwilight\n18\n1\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Saturday\nTime: Twilight\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $35\nCart Fee:     $20\nRange Balls:  $7\nTotal:        $62"));
    }

    Spec(Test_34) {
        std::string result = exec("echo 'Saturday\nMorning\n9\n0\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Saturday\nTime: Morning\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $30\nCart Fee:     $0\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $52"));
    }

    Spec(Test_35) {
        std::string result = exec("echo 'Saturday\nAfternoon\n9\n1\n0\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Saturday\nTime: Afternoon\nHoles: 9\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $20\nCart Fee:     $10\nTotal:        $30"));
    }

    Spec(Test_36) {
        std::string result = exec("echo 'Saturday\nTwilight\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Saturday\nTime: Twilight\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $17.5\nCart Fee:     $0\nRental Clubs: $15\nTotal:        $32.5"));
    }

    Spec(Test_37) {
        std::string result = exec("echo 'Sunday\nMorning\n18\n1\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Sunday\nTime: Morning\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $60\nCart Fee:     $20\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $102"));
    }

    Spec(Test_38) {
        std::string result = exec("echo 'Sunday\nAfternoon\n18\n1\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Sunday\nTime: Afternoon\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $40\nCart Fee:     $20\nRental Clubs: $15\nTotal:        $75"));
    }

    Spec(Test_39) {
        std::string result = exec("echo 'Sunday\nTwilight\n18\n1\n0\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Sunday\nTime: Twilight\nHoles: 18\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $35\nCart Fee:     $20\nRange Balls:  $7\nTotal:        $62"));
    }

    Spec(Test_40) {
        std::string result = exec("echo 'Sunday\nMorning\n9\n0\n1\n1' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Sunday\nTime: Morning\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: Yes\n\nPRICE SUMMARY\nGreen Fee:    $30\nCart Fee:     $0\nRental Clubs: $15\nRange Balls:  $7\nTotal:        $52"));
    }

    Spec(Test_41) {
        std::string result = exec("echo 'Sunday\nAfternoon\n9\n1\n0\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Sunday\nTime: Afternoon\nHoles: 9\nCart: Yes\n\nEXTRAS\nRental Clubs: No\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $20\nCart Fee:     $10\nTotal:        $30"));
    }

    Spec(Test_42) {
        std::string result = exec("echo 'Sunday\nTwilight\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("---------------------\n       RECEIPT       \n---------------------\nDay: Sunday\nTime: Twilight\nHoles: 9\nCart: No\n\nEXTRAS\nRental Clubs: Yes\nRange Balls: No\n\nPRICE SUMMARY\nGreen Fee:    $17.5\nCart Fee:     $0\nRental Clubs: $15\nTotal:        $32.5"));
    }

    Spec(Test_43) {
        std::string result = exec("echo 'Today\nMorning\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("Invalid information"));
    }

    Spec(Test_44) {
        std::string result = exec("echo 'Monday\nMidday\n9\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("Invalid information"));
    }

    Spec(Test_45) {
        std::string result = exec("echo 'Monday\nAfternoon\n27\n0\n1\n0' | ./temp");
        Assert::That(result, Equals("Invalid information"));
    }



    
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}