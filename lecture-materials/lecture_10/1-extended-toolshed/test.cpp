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

Context(GitRepo){
    Spec(Test_GitRepo){
       bool gitRepo = exec("git rev-parse --is-inside-work-tree") == "true";
       if (gitRepo) {
        Context(GitRepoCommits) {
            Spec(Test_Commits){
                std::string commits = exec("git rev-list --count --all");
                if (stoi(commits) > 2) {
                    Assert::That(true, IsTrue());

                    Context(TestProgram) {
                        static void SetUpContext(){
                            exec("g++ main.cpp -o temp");
                        }

                        static void TearDownContext() {
                            system("rm -rf temp");
                        }

                        Spec(Test_1){
                            std::string result = exec("cat inquiries/01.txt | ./temp");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nSim Doggett\n5759 Drewry Point\nMerced, CA 95344\n\nDESCRIPTION SUMMARY\nDimensions: 10 x 17 x 10\nMaterial: Metal\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $1080\nRoof:     $510\nDelivery: $0\nTotal:    $1590"));
                        }
                        
                        Spec(Test_2){
                            std::string result = exec("cat inquiries/02.txt | ./temp");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nShirlene Shadrack\n6320 Grayhawk Junction\nMerced, CA 95344\n\nDESCRIPTION SUMMARY\nDimensions: 8 x 18 x 9\nMaterial: Metal\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $936\nRoof:     $432\nDelivery: $100\nTotal:    $1468"));
                        }

                        Spec(Test_3){
                            std::string result = exec("cat inquiries/03.txt | ./temp");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nXenos Landrean\n6201 Sloan Center\nMerced, CA 95342\n\nDESCRIPTION SUMMARY\nDimensions: 7 x 10 x 11\nMaterial: Metal\nDelivery: No\n\nPRICE SUMMARY\nWalls:    $748\nRoof:     $210\nDelivery: $0\nTotal:    $958"));
                        }

                        Spec(Test_4){
                            std::string result = exec("cat inquiries/04.txt | ./temp");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nXylia Fearfull\n55 John Wall Trail\nMerced, CA 95343\n\nDESCRIPTION SUMMARY\nDimensions: 9 x 27 x 9\nMaterial: Wood\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $972\nRoof:     $729\nDelivery: $0\nTotal:    $1701"));
                        }
                        
                        Spec(Test_5){
                            std::string result = exec("cat inquiries/05.txt | ./temp");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nWeidar Jeffs\n4 Sunbrook Terrace\nMerced, CA 95345\n\nDESCRIPTION SUMMARY\nDimensions: 5 x 21 x 8\nMaterial: Wood\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $624\nRoof:     $315\nDelivery: $100\nTotal:    $1039"));
                        }

                        Spec(Test_6){
                            std::string result = exec("cat inquiries/06.txt | ./temp");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nFlorencia Sallarie\n9361 Roth Place\nMerced, CA 95346\n\nDESCRIPTION SUMMARY\nDimensions: 6 x 10 x 10\nMaterial: Wood\nDelivery: No\n\nPRICE SUMMARY\nWalls:    $480\nRoof:     $180\nDelivery: $0\nTotal:    $660"));
                        }
                        
                        Spec(Test_1_1){
                            std::string result = exec("cat quotes/quote-01.txt");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nSim Doggett\n5759 Drewry Point\nMerced, CA 95344\n\nDESCRIPTION SUMMARY\nDimensions: 10 x 17 x 10\nMaterial: Metal\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $1080\nRoof:     $510\nDelivery: $0\nTotal:    $1590"));
                        }
                        
                        Spec(Test_2_1){
                            std::string result = exec("cat quotes/quote-02.txt");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nShirlene Shadrack\n6320 Grayhawk Junction\nMerced, CA 95344\n\nDESCRIPTION SUMMARY\nDimensions: 8 x 18 x 9\nMaterial: Metal\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $936\nRoof:     $432\nDelivery: $100\nTotal:    $1468"));
                        }

                        Spec(Test_3_1){
                            std::string result = exec("cat quotes/quote-03.txt");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nXenos Landrean\n6201 Sloan Center\nMerced, CA 95342\n\nDESCRIPTION SUMMARY\nDimensions: 7 x 10 x 11\nMaterial: Metal\nDelivery: No\n\nPRICE SUMMARY\nWalls:    $748\nRoof:     $210\nDelivery: $0\nTotal:    $958"));
                        }

                        Spec(Test_4_1){
                            std::string result = exec("cat quotes/quote-04.txt");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nXylia Fearfull\n55 John Wall Trail\nMerced, CA 95343\n\nDESCRIPTION SUMMARY\nDimensions: 9 x 27 x 9\nMaterial: Wood\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $972\nRoof:     $729\nDelivery: $0\nTotal:    $1701"));
                        }
                        
                        Spec(Test_5_1){
                            std::string result = exec("cat quotes/quote-05.txt");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nWeidar Jeffs\n4 Sunbrook Terrace\nMerced, CA 95345\n\nDESCRIPTION SUMMARY\nDimensions: 5 x 21 x 8\nMaterial: Wood\nDelivery: Yes\n\nPRICE SUMMARY\nWalls:    $624\nRoof:     $315\nDelivery: $100\nTotal:    $1039"));
                        }

                        Spec(Test_6_1){
                            std::string result = exec("cat quotes/quote-06.txt");
                            Assert::That(result, Equals("-------------------------\n          QUOTE          \n-------------------------\nFlorencia Sallarie\n9361 Roth Place\nMerced, CA 95346\n\nDESCRIPTION SUMMARY\nDimensions: 6 x 10 x 10\nMaterial: Wood\nDelivery: No\n\nPRICE SUMMARY\nWalls:    $480\nRoof:     $180\nDelivery: $0\nTotal:    $660"));
                        }
                    };
                } else {
                    Assert::Failure("Not enough commit history");
                }
            }
        };
       } else {
           Assert::Failure("No git repository");
       }
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}