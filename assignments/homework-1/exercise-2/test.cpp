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
        std::string result = exec("cat personnel/claiborne.txt | ./temp");
        Assert::That(result, Equals("\n              | Claiborne Spring\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Computer Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | cspring@ucmerced.edu\n              | 544-478-5856\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_1_1){
        std::string result = exec("cat signatures/claiborne.txt");
        Assert::That(result, Equals("\n              | Claiborne Spring\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Computer Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | cspring@ucmerced.edu\n              | 544-478-5856\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_2){
        std::string result = exec("cat personnel/consalve.txt | ./temp");
        Assert::That(result, Equals("\n              | Consalve Reye\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Computer Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | creye@ucmerced.edu\n              | 563-179-7199\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_2_1){
        std::string result = exec("cat signatures/consalve.txt");
        Assert::That(result, Equals("\n              | Consalve Reye\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Computer Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | creye@ucmerced.edu\n              | 563-179-7199\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_3){
        std::string result = exec("cat personnel/cullie.txt | ./temp");
        Assert::That(result, Equals("\n              | Cullie Nottram\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | cnottram@ucmerced.edu\n              | 491-614-8302\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_3_1){
        std::string result = exec("cat signatures/cullie.txt");
        Assert::That(result, Equals("\n              | Cullie Nottram\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | cnottram@ucmerced.edu\n              | 491-614-8302\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_4){
        std::string result = exec("cat personnel/fin.txt | ./temp");
        Assert::That(result, Equals("\n              | Fin Stanyforth\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | fstanyforth@ucmerced.edu\n              | 805-128-1107\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_4_1){
        std::string result = exec("cat signatures/fin.txt");
        Assert::That(result, Equals("\n              | Fin Stanyforth\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | fstanyforth@ucmerced.edu\n              | 805-128-1107\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_5){
        std::string result = exec("cat personnel/giacobo.txt | ./temp");
        Assert::That(result, Equals("\n              | Giacobo Openshaw\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Environmental Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | gopenshaw@ucmerced.edu\n              | 129-882-4960\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_5_1){
        std::string result = exec("cat signatures/giacobo.txt");
        Assert::That(result, Equals("\n              | Giacobo Openshaw\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Environmental Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | gopenshaw@ucmerced.edu\n              | 129-882-4960\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_6){
        std::string result = exec("cat personnel/gianna.txt | ./temp");
        Assert::That(result, Equals("\n              | Gianna Minnock\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | gminnock@ucmerced.edu\n              | 986-924-5854\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_6_1){
        std::string result = exec("cat signatures/gianna.txt");
        Assert::That(result, Equals("\n              | Gianna Minnock\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | gminnock@ucmerced.edu\n              | 986-924-5854\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_7){
        std::string result = exec("cat personnel/hildagarde.txt | ./temp");
        Assert::That(result, Equals("\n              | Hildagarde Creyke\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | hcreyke@ucmerced.edu\n              | 967-905-8035\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_7_1){
        std::string result = exec("cat signatures/hildagarde.txt");
        Assert::That(result, Equals("\n              | Hildagarde Creyke\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | hcreyke@ucmerced.edu\n              | 967-905-8035\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_8){
        std::string result = exec("cat personnel/janna.txt | ./temp");
        Assert::That(result, Equals("\n              | Janna Forrestall\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | jforrestall@ucmerced.edu\n              | 471-934-4503\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_8_1){
        std::string result = exec("cat signatures/janna.txt");
        Assert::That(result, Equals("\n              | Janna Forrestall\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | jforrestall@ucmerced.edu\n              | 471-934-4503\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_9){
        std::string result = exec("cat personnel/job.txt | ./temp");
        Assert::That(result, Equals("\n              | Job Tyndall\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | jtyndall@ucmerced.edu\n              | 888-109-7377\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_9_1){
        std::string result = exec("cat signatures/job.txt");
        Assert::That(result, Equals("\n              | Job Tyndall\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | jtyndall@ucmerced.edu\n              | 888-109-7377\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_10){
        std::string result = exec("cat personnel/jobye.txt | ./temp");
        Assert::That(result, Equals("\n              | Jobye Sapson\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | jsapson@ucmerced.edu\n              | 958-978-6824\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_10_1){
        std::string result = exec("cat signatures/jobye.txt");
        Assert::That(result, Equals("\n              | Jobye Sapson\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | jsapson@ucmerced.edu\n              | 958-978-6824\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_11){
        std::string result = exec("cat personnel/kevan.txt | ./temp");
        Assert::That(result, Equals("\n              | Kevan Feaviour\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | kfeaviour@ucmerced.edu\n              | 268-911-8360\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_11_1){
        std::string result = exec("cat signatures/kevan.txt");
        Assert::That(result, Equals("\n              | Kevan Feaviour\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | kfeaviour@ucmerced.edu\n              | 268-911-8360\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_12){
        std::string result = exec("cat personnel/kitty.txt | ./temp");
        Assert::That(result, Equals("\n              | Kitty Meindl\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | kmeindl@ucmerced.edu\n              | 846-444-1752\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_12_1){
        std::string result = exec("cat signatures/kitty.txt");
        Assert::That(result, Equals("\n              | Kitty Meindl\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | kmeindl@ucmerced.edu\n              | 846-444-1752\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_13){
        std::string result = exec("cat personnel/madelle.txt | ./temp");
        Assert::That(result, Equals("\n              | Madelle Jeandillou\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Environmental Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | mjeandillou@ucmerced.edu\n              | 962-798-4123\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_13_1){
        std::string result = exec("cat signatures/madelle.txt");
        Assert::That(result, Equals("\n              | Madelle Jeandillou\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Environmental Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | mjeandillou@ucmerced.edu\n              | 962-798-4123\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_14){
        std::string result = exec("cat personnel/major.txt | ./temp");
        Assert::That(result, Equals("\n              | Major McCluskey\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | mmccluskey@ucmerced.edu\n              | 232-610-7601\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_14_1){
        std::string result = exec("cat signatures/major.txt");
        Assert::That(result, Equals("\n              | Major McCluskey\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | mmccluskey@ucmerced.edu\n              | 232-610-7601\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_15){
        std::string result = exec("cat personnel/maurizia.txt | ./temp");
        Assert::That(result, Equals("\n              | Maurizia Pettingall\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Civil Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | mpettingall@ucmerced.edu\n              | 273-340-0616\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_15_1){
        std::string result = exec("cat signatures/maurizia.txt");
        Assert::That(result, Equals("\n              | Maurizia Pettingall\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Civil Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | mpettingall@ucmerced.edu\n              | 273-340-0616\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_16){
        std::string result = exec("cat personnel/padget.txt | ./temp");
        Assert::That(result, Equals("\n              | Padget Sparke\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | psparke@ucmerced.edu\n              | 416-754-4535\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_16_1){
        std::string result = exec("cat signatures/padget.txt");
        Assert::That(result, Equals("\n              | Padget Sparke\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | psparke@ucmerced.edu\n              | 416-754-4535\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_17){
        std::string result = exec("cat personnel/padraig.txt | ./temp");
        Assert::That(result, Equals("\n              | Padraig McDuall\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Mechanical Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | pmcduall@ucmerced.edu\n              | 610-289-9872\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_17_1){
        std::string result = exec("cat signatures/padraig.txt");
        Assert::That(result, Equals("\n              | Padraig McDuall\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Mechanical Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | pmcduall@ucmerced.edu\n              | 610-289-9872\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_18){
        std::string result = exec("cat personnel/shannen.txt | ./temp");
        Assert::That(result, Equals("\n              | Shannen Hammell\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Electrical Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | shammell@ucmerced.edu\n              | 839-850-5947\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_18_1){
        std::string result = exec("cat signatures/shannen.txt");
        Assert::That(result, Equals("\n              | Shannen Hammell\n              | \n              | Student\n  UNIVERSITY  | \n      OF      | Electrical Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | shammell@ucmerced.edu\n              | 839-850-5947\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_19){
        std::string result = exec("cat personnel/ulises.txt | ./temp");
        Assert::That(result, Equals("\n              | Ulises Blacklidge\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | ublacklidge@ucmerced.edu\n              | 479-913-9791\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_19_1){
        std::string result = exec("cat signatures/ulises.txt");
        Assert::That(result, Equals("\n              | Ulises Blacklidge\n              | \n              | Staff\n  UNIVERSITY  | \n      OF      | Materials Science and Engineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | ublacklidge@ucmerced.edu\n              | 479-913-9791\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_20){
        std::string result = exec("cat personnel/verina.txt | ./temp");
        Assert::That(result, Equals("\n              | Verina Shatford\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | vshatford@ucmerced.edu\n              | 768-234-9428\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }

    Spec(Test_20_1){
        std::string result = exec("cat signatures/verina.txt");
        Assert::That(result, Equals("\n              | Verina Shatford\n              | \n              | Faculty\n  UNIVERSITY  | \n      OF      | Bioengineering\n  CALIFORNIA  | School of Engineering\n    MERCED    | \n              | 5200 Lake Road | Merced, CA 95343\n              | vshatford@ucmerced.edu\n              | 768-234-9428\n\nBUILDING THE FUTURE IN THE HEART OF CALIFORNIA"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}