#include <igloo/igloo.h>
#include <iostream>
#include "ucm_utils.h"

using namespace igloo;


Context(TextProgram){
    Spec(OneLetterWord){
        bool output = wordExists("a", "a");

        Assert::That(output, IsTrue());
    }

    Spec(ThreeLetterWord){
        bool output = wordExists("car", "car");

        Assert::That(output, IsTrue());
    }

    Spec(TestCase){
        bool output = wordExists("DOGS", "dogs");

        Assert::That(output, IsTrue());
    }

    Spec(TestSubstringOneWord){
        bool output = wordExists("apples", "apple");

        Assert::That(output, IsFalse());
    }

    Spec(TestSubstringOneWord2){
        bool output = wordExists("computer", "computers");

        Assert::That(output, IsFalse());
    }

    Spec(TestPeriod){
        bool output = wordExists("I enjoy to golf.", "golf");

        Assert::That(output, IsTrue());
    }

    Spec(TestPeriodAndCase){
        bool output = wordExists("I enjoy to golf.", "Golf");

        Assert::That(output, IsTrue());
    }

    Spec(TestSubstringInSentence){
        bool output = wordExists("I enjoy to code in C++.", "joy");

        Assert::That(output, IsFalse());
    }

    Spec(TestComma){
        bool output = wordExists("This is an invalid, sentence.", "invalid");

        Assert::That(output, IsTrue());
    }

    Spec(TestCommaAndCase){
        bool output = wordExists("This is an invalid, sentence.", "Invalid");

        Assert::That(output, IsTrue());
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}