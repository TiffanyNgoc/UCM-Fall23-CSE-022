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
        std::string result = exec("cat sonnets/sonnet-1.txt | ./temp");
        Assert::That(result, Equals("Sonnet 1: From fairest creatures we desire increase\nBy: William Shakespeare\n\nFrom fairest creatures we desire increase,\nThat thereby beauty's rose might never die,\nBut as the riper should by time decease,\nHis tender heir might bear his memory:\n\nBut thou contracted to thine own bright eyes,\nFeed'st thy light's flame with self-substantial fuel,\nMaking a famine where abundance lies,\nThy self thy foe, to thy sweet self too cruel:\n\nThou that art now the world's fresh ornament,\nAnd only herald to the gaudy spring,\nWithin thine own bud buriest thy content,\nAnd tender churl mak'st waste in niggarding:\n\n    Pity the world, or else this glutton be,\n    To eat the world's due, by the grave and thee."));
    }

    Spec(Test_1_1){
        std::string result = exec("cat pretty-sonnets/sonnet-1.txt");
        Assert::That(result, Equals("Sonnet 1: From fairest creatures we desire increase\nBy: William Shakespeare\n\nFrom fairest creatures we desire increase,\nThat thereby beauty's rose might never die,\nBut as the riper should by time decease,\nHis tender heir might bear his memory:\n\nBut thou contracted to thine own bright eyes,\nFeed'st thy light's flame with self-substantial fuel,\nMaking a famine where abundance lies,\nThy self thy foe, to thy sweet self too cruel:\n\nThou that art now the world's fresh ornament,\nAnd only herald to the gaudy spring,\nWithin thine own bud buriest thy content,\nAnd tender churl mak'st waste in niggarding:\n\n    Pity the world, or else this glutton be,\n    To eat the world's due, by the grave and thee."));
    }

    Spec(Test_2){
        std::string result = exec("cat sonnets/sonnet-2.txt | ./temp");
        Assert::That(result, Equals("Sonnet 2: When forty winters shall besiege thy brow\nBy: William Shakespeare\n\nWhen forty winters shall besiege thy brow,\nAnd dig deep trenches in thy beauty's field,\nThy youth's proud livery so gazed on now,\nWill be a tatter'd weed of small worth held:\n\nThen being asked, where all thy beauty lies,\nWhere all the treasure of thy lusty days;\nTo say, within thine own deep sunken eyes,\nWere an all-eating shame, and thriftless praise.\n\nHow much more praise deserv'd thy beauty's use,\nIf thou couldst answer 'This fair child of mine\nShall sum my count, and make my old excuse,'\nProving his beauty by succession thine!\n\n    This were to be new made when thou art old,\n    And see thy blood warm when thou feel'st it cold."));
    }

    Spec(Test_2_1){
        std::string result = exec("cat pretty-sonnets/sonnet-2.txt");
        Assert::That(result, Equals("Sonnet 2: When forty winters shall besiege thy brow\nBy: William Shakespeare\n\nWhen forty winters shall besiege thy brow,\nAnd dig deep trenches in thy beauty's field,\nThy youth's proud livery so gazed on now,\nWill be a tatter'd weed of small worth held:\n\nThen being asked, where all thy beauty lies,\nWhere all the treasure of thy lusty days;\nTo say, within thine own deep sunken eyes,\nWere an all-eating shame, and thriftless praise.\n\nHow much more praise deserv'd thy beauty's use,\nIf thou couldst answer 'This fair child of mine\nShall sum my count, and make my old excuse,'\nProving his beauty by succession thine!\n\n    This were to be new made when thou art old,\n    And see thy blood warm when thou feel'st it cold."));
    }

    Spec(Test_3){
        std::string result = exec("cat sonnets/sonnet-3.txt | ./temp");
        Assert::That(result, Equals("Sonnet 3: Look in thy glass and tell the face thou viewest\nBy: William Shakespeare\n\nLook in thy glass and tell the face thou viewest\nNow is the time that face should form another;\nWhose fresh repair if now thou not renewest,\nThou dost beguile the world, unbless some mother.\n\nFor where is she so fair whose unear'd womb\nDisdains the tillage of thy husbandry?\nOr who is he so fond will be the tomb,\nOf his self-love to stop posterity?\n\nThou art thy mother's glass and she in thee\nCalls back the lovely April of her prime;\nSo thou through windows of thine age shalt see,\nDespite of wrinkles this thy golden time.\n\n    But if thou live, remember'd not to be,\n    Die single and thine image dies with thee."));
    }

    Spec(Test_3_1){
        std::string result = exec("cat pretty-sonnets/sonnet-3.txt");
        Assert::That(result, Equals("Sonnet 3: Look in thy glass and tell the face thou viewest\nBy: William Shakespeare\n\nLook in thy glass and tell the face thou viewest\nNow is the time that face should form another;\nWhose fresh repair if now thou not renewest,\nThou dost beguile the world, unbless some mother.\n\nFor where is she so fair whose unear'd womb\nDisdains the tillage of thy husbandry?\nOr who is he so fond will be the tomb,\nOf his self-love to stop posterity?\n\nThou art thy mother's glass and she in thee\nCalls back the lovely April of her prime;\nSo thou through windows of thine age shalt see,\nDespite of wrinkles this thy golden time.\n\n    But if thou live, remember'd not to be,\n    Die single and thine image dies with thee."));
    }

    Spec(Test_4){
        std::string result = exec("cat sonnets/sonnet-4.txt | ./temp");
        Assert::That(result, Equals("Sonnet 4: Unthrifty loveliness, why dost thou spend\nBy: William Shakespeare\n\nUnthrifty loveliness, why dost thou spend\nUpon thy self thy beauty's legacy?\nNature's bequest gives nothing, but doth lend,\nAnd being frank she lends to those are free:\n\nThen, beauteous niggard, why dost thou abuse\nThe bounteous largess given thee to give?\nProfitless usurer, why dost thou use\nSo great a sum of sums, yet canst not live?\n\nFor having traffic with thy self alone,\nThou of thy self thy sweet self dost deceive:\nThen how when nature calls thee to be gone,\nWhat acceptable audit canst thou leave?\n\n    Thy unused beauty must be tombed with thee,\n    Which, used, lives th' executor to be."));
    }

    Spec(Test_4_1){
        std::string result = exec("cat pretty-sonnets/sonnet-4.txt");
        Assert::That(result, Equals("Sonnet 4: Unthrifty loveliness, why dost thou spend\nBy: William Shakespeare\n\nUnthrifty loveliness, why dost thou spend\nUpon thy self thy beauty's legacy?\nNature's bequest gives nothing, but doth lend,\nAnd being frank she lends to those are free:\n\nThen, beauteous niggard, why dost thou abuse\nThe bounteous largess given thee to give?\nProfitless usurer, why dost thou use\nSo great a sum of sums, yet canst not live?\n\nFor having traffic with thy self alone,\nThou of thy self thy sweet self dost deceive:\nThen how when nature calls thee to be gone,\nWhat acceptable audit canst thou leave?\n\n    Thy unused beauty must be tombed with thee,\n    Which, used, lives th' executor to be."));
    }


    Spec(Test_5){
        std::string result = exec("cat sonnets/sonnet-5.txt | ./temp");
        Assert::That(result, Equals("Sonnet 5: Those hours, that with gentle work did frame\nBy: William Shakespeare\n\nThose hours, that with gentle work did frame\nThe lovely gaze where every eye doth dwell,\nWill play the tyrants to the very same\nAnd that unfair which fairly doth excel;\n\nFor never-resting time leads summer on\nTo hideous winter, and confounds him there;\nSap checked with frost, and lusty leaves quite gone,\nBeauty o'er-snowed and bareness every where:\n\nThen were not summer's distillation left,\nA liquid prisoner pent in walls of glass,\nBeauty's effect with beauty were bereft,\nNor it, nor no remembrance what it was:\n\n    But flowers distill'd, though they with winter meet,\n    Leese but their show; their substance still lives sweet."));
    }

    Spec(Test_5_1){
        std::string result = exec("cat pretty-sonnets/sonnet-5.txt");
        Assert::That(result, Equals("Sonnet 5: Those hours, that with gentle work did frame\nBy: William Shakespeare\n\nThose hours, that with gentle work did frame\nThe lovely gaze where every eye doth dwell,\nWill play the tyrants to the very same\nAnd that unfair which fairly doth excel;\n\nFor never-resting time leads summer on\nTo hideous winter, and confounds him there;\nSap checked with frost, and lusty leaves quite gone,\nBeauty o'er-snowed and bareness every where:\n\nThen were not summer's distillation left,\nA liquid prisoner pent in walls of glass,\nBeauty's effect with beauty were bereft,\nNor it, nor no remembrance what it was:\n\n    But flowers distill'd, though they with winter meet,\n    Leese but their show; their substance still lives sweet."));
    }

    Spec(Test_6){
        std::string result = exec("cat sonnets/sonnet-6.txt | ./temp");
        Assert::That(result, Equals("Sonnet 6: Then let not winter's ragged hand deface\nBy: William Shakespeare\n\nThen let not winter's ragged hand deface,\nIn thee thy summer, ere thou be distill'd:\nMake sweet some vial; treasure thou some place\nWith beauty's treasure ere it be self-kill'd.\n\nThat use is not forbidden usury,\nWhich happies those that pay the willing loan;\nThat's for thy self to breed another thee,\nOr ten times happier, be it ten for one;\n\nTen times thy self were happier than thou art,\nIf ten of thine ten times refigur'd thee:\nThen what could death do if thou shouldst depart,\nLeaving thee living in posterity?\n\n    Be not self-will'd, for thou art much too fair\n    To be death's conquest and make worms thine heir."));
    }

    Spec(Test_6_1){
        std::string result = exec("cat pretty-sonnets/sonnet-6.txt");
        Assert::That(result, Equals("Sonnet 6: Then let not winter's ragged hand deface\nBy: William Shakespeare\n\nThen let not winter's ragged hand deface,\nIn thee thy summer, ere thou be distill'd:\nMake sweet some vial; treasure thou some place\nWith beauty's treasure ere it be self-kill'd.\n\nThat use is not forbidden usury,\nWhich happies those that pay the willing loan;\nThat's for thy self to breed another thee,\nOr ten times happier, be it ten for one;\n\nTen times thy self were happier than thou art,\nIf ten of thine ten times refigur'd thee:\nThen what could death do if thou shouldst depart,\nLeaving thee living in posterity?\n\n    Be not self-will'd, for thou art much too fair\n    To be death's conquest and make worms thine heir."));
    }

    Spec(Test_7){
        std::string result = exec("cat sonnets/sonnet-7.txt | ./temp");
        Assert::That(result, Equals("Sonnet 7: Lo! in the orient when the gracious light\nBy: William Shakespeare\n\nLo! in the orient when the gracious light\nLifts up his burning head, each under eye\nDoth homage to his new-appearing sight,\nServing with looks his sacred majesty;\n\nAnd having climb'd the steep-up heavenly hill,\nResembling strong youth in his middle age,\nYet mortal looks adore his beauty still,\nAttending on his golden pilgrimage:\n\nBut when from highmost pitch, with weary car,\nLike feeble age, he reeleth from the day,\nThe eyes, 'fore duteous, now converted are\nFrom his low tract, and look another way:\n\n    So thou, thyself outgoing in thy noon:\n    Unlook'd, on diest unless thou get a son."));
    }

    Spec(Test_7_1){
        std::string result = exec("cat pretty-sonnets/sonnet-7.txt");
        Assert::That(result, Equals("Sonnet 7: Lo! in the orient when the gracious light\nBy: William Shakespeare\n\nLo! in the orient when the gracious light\nLifts up his burning head, each under eye\nDoth homage to his new-appearing sight,\nServing with looks his sacred majesty;\n\nAnd having climb'd the steep-up heavenly hill,\nResembling strong youth in his middle age,\nYet mortal looks adore his beauty still,\nAttending on his golden pilgrimage:\n\nBut when from highmost pitch, with weary car,\nLike feeble age, he reeleth from the day,\nThe eyes, 'fore duteous, now converted are\nFrom his low tract, and look another way:\n\n    So thou, thyself outgoing in thy noon:\n    Unlook'd, on diest unless thou get a son."));
    }

    Spec(Test_8){
        std::string result = exec("cat sonnets/sonnet-8.txt | ./temp");
        Assert::That(result, Equals("Sonnet 8: Music to hear, why hear'st thou music sadly?\nBy: William Shakespeare\n\nMusic to hear, why hear'st thou music sadly?\nSweets with sweets war not, joy delights in joy:\nWhy lov'st thou that which thou receiv'st not gladly,\nOr else receiv'st with pleasure thine annoy?\n\nIf the true concord of well-tuned sounds,\nBy unions married, do offend thine ear,\nThey do but sweetly chide thee, who confounds\nIn singleness the parts that thou shouldst bear.\n\nMark how one string, sweet husband to another,\nStrikes each in each by mutual ordering;\nResembling sire and child and happy mother,\nWho, all in one, one pleasing note do sing:\n\n    Whose speechless song being many, seeming one,\n    Sings this to thee: 'Thou single wilt prove none.'"));
    }

    Spec(Test_8_1){
        std::string result = exec("cat pretty-sonnets/sonnet-8.txt");
        Assert::That(result, Equals("Sonnet 8: Music to hear, why hear'st thou music sadly?\nBy: William Shakespeare\n\nMusic to hear, why hear'st thou music sadly?\nSweets with sweets war not, joy delights in joy:\nWhy lov'st thou that which thou receiv'st not gladly,\nOr else receiv'st with pleasure thine annoy?\n\nIf the true concord of well-tuned sounds,\nBy unions married, do offend thine ear,\nThey do but sweetly chide thee, who confounds\nIn singleness the parts that thou shouldst bear.\n\nMark how one string, sweet husband to another,\nStrikes each in each by mutual ordering;\nResembling sire and child and happy mother,\nWho, all in one, one pleasing note do sing:\n\n    Whose speechless song being many, seeming one,\n    Sings this to thee: 'Thou single wilt prove none.'"));
    }

    Spec(Test_9){
        std::string result = exec("cat sonnets/sonnet-9.txt | ./temp");
        Assert::That(result, Equals("Sonnet 9: Is it for fear to wet a widow's eye\nBy: William Shakespeare\n\nIs it for fear to wet a widow's eye,\nThat thou consum'st thy self in single life?\nAh! if thou issueless shalt hap to die,\nThe world will wail thee like a makeless wife;\n\nThe world will be thy widow and still weep\nThat thou no form of thee hast left behind,\nWhen every private widow well may keep\nBy children's eyes, her husband's shape in mind:\n\nLook! what an unthrift in the world doth spend\nShifts but his place, for still the world enjoys it;\nBut beauty's waste hath in the world an end,\nAnd kept unused the user so destroys it.\n\n    No love toward others in that bosom sits\n    That on himself such murd'rous shame commits."));
    }

    Spec(Test_9_1){
        std::string result = exec("cat pretty-sonnets/sonnet-9.txt");
        Assert::That(result, Equals("Sonnet 9: Is it for fear to wet a widow's eye\nBy: William Shakespeare\n\nIs it for fear to wet a widow's eye,\nThat thou consum'st thy self in single life?\nAh! if thou issueless shalt hap to die,\nThe world will wail thee like a makeless wife;\n\nThe world will be thy widow and still weep\nThat thou no form of thee hast left behind,\nWhen every private widow well may keep\nBy children's eyes, her husband's shape in mind:\n\nLook! what an unthrift in the world doth spend\nShifts but his place, for still the world enjoys it;\nBut beauty's waste hath in the world an end,\nAnd kept unused the user so destroys it.\n\n    No love toward others in that bosom sits\n    That on himself such murd'rous shame commits."));
    }

    Spec(Test_10){
        std::string result = exec("cat sonnets/sonnet-10.txt | ./temp");
        Assert::That(result, Equals("Sonnet 10: For shame! deny that thou bear'st love to any\nBy: William Shakespeare\n\nFor shame! deny that thou bear'st love to any,\nWho for thy self art so unprovident.\nGrant, if thou wilt, thou art belov'd of many,\nBut that thou none lov'st is most evident:\n\nFor thou art so possess'd with murderous hate,\nThat 'gainst thy self thou stick'st not to conspire,\nSeeking that beauteous roof to ruinate\nWhich to repair should be thy chief desire.\n\nO! change thy thought, that I may change my mind:\nShall hate be fairer lodg'd than gentle love?\nBe, as thy presence is, gracious and kind,\nOr to thyself at least kind-hearted prove:\n\n    Make thee another self for love of me,\n    That beauty still may live in thine or thee."));
    }

    Spec(Test_10_1){
        std::string result = exec("cat pretty-sonnets/sonnet-10.txt");
        Assert::That(result, Equals("Sonnet 10: For shame! deny that thou bear'st love to any\nBy: William Shakespeare\n\nFor shame! deny that thou bear'st love to any,\nWho for thy self art so unprovident.\nGrant, if thou wilt, thou art belov'd of many,\nBut that thou none lov'st is most evident:\n\nFor thou art so possess'd with murderous hate,\nThat 'gainst thy self thou stick'st not to conspire,\nSeeking that beauteous roof to ruinate\nWhich to repair should be thy chief desire.\n\nO! change thy thought, that I may change my mind:\nShall hate be fairer lodg'd than gentle love?\nBe, as thy presence is, gracious and kind,\nOr to thyself at least kind-hearted prove:\n\n    Make thee another self for love of me,\n    That beauty still may live in thine or thee."));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}