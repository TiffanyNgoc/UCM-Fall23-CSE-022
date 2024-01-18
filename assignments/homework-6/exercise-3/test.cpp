#include <igloo/igloo.h>
#include <iostream>
#include "ucm_utils.h"

using namespace igloo;


Context(TextProgram){
    Spec(LowerCaseOneLetter){
        std::string output = funkyString("a");

        Assert::That(output, Equals("A"));
    }

    Spec(LowercaseWordTwoLetters){
        std::string output = funkyString("no");

        Assert::That(output, Equals("NO"));
    }

    Spec(LowercaseWordThreeLetters){
        std::string output = funkyString("dog");

        Assert::That(output, Equals("DoG"));
    }

    Spec(MixedCaseWord){
        std::string output = funkyString("cAt");

        Assert::That(output, Equals("CaT"));
    }

    Spec(WordAllUppercase){
        std::string output = funkyString("APPLE");

        Assert::That(output, Equals("ApplE"));
    }

    Spec(AllDots){
        std::string output = funkyString("...");

        Assert::That(output, Equals("..."));
    }

    Spec(Spaces){
        std::string output = funkyString("UC  Merced");

        Assert::That(output, Equals("UC  MerceD"));
    }

    Spec(CommaAndPeriodMixedCase){
        std::string output = funkyString("University of California, Merced.");

        Assert::That(output, Equals("UniversitY OF CaliforniA, MerceD."));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}