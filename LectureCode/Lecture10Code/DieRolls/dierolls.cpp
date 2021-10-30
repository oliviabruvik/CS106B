/*
 * dierolls.cpp
 *
 * @author Cynthia Lee
 * @version 2122-Aut
 *
 * Demonstrates combining loops with recursion to generate all possible
 * sequences. The program generates all possible die roll sequences,
 * i.e., sequences of numbers 1-6.
 */

#include <iostream>
#include "console.h"
#include "strlib.h"
#include "vector.h"
#include "testing/SimpleTest.h"
using namespace std;


/* Function Prototypes */
void generateAllSequences(int length, Vector<string>& allSequences);
void generateAllSequences(int length, Vector<string>& allSequences, string sequence);


int main()
{
    if (runSimpleTests(SELECTED_TESTS)) {
        return 0;
    }
    cout << "All done, exiting" << endl;
    return 0;
}


/*
 * Generates all sequences of numbers 1-6, and stores them in the
 * provided vector.
 * @param length is the number of die rolls to perform
 * @param allSequences is the vector to fill with sequences
 * @pre the parameter allSequences should be initially empty
 */
void generateAllSequences(int length, Vector<string>& allSequences)
{
    string sequence;
    generateAllSequences(length, allSequences, sequence);
}

/*
 * Recursive implementation (private)
 * Generates all sequences of numbers 1-6, and stores them in the provided vector.
 * @param length is the number of die rolls to perform
 * @param allSequences is the vector to fill with sequences
 * @pre the parameter allSequences should be initially empty
 * @pre the parameter sequence should be empty string in the originating call
 *     to this function, and will fill as the recursion unfolds
 */
void generateAllSequences(int length, Vector<string>& allSequences, string sequence)
{
    // TODO: write recursion (we will start with a copy-paste of the Coin Flip code)
}


/* * * * * * Test Cases * * * * * */

PROVIDED_TEST("Sequences of length 0") {
    Vector<string> allSequences;
    generateAllSequences(0, allSequences);
    EXPECT_EQUAL(allSequences, {""});
}

PROVIDED_TEST("Sequences of length 1") {
    Vector<string> allSequences;
    generateAllSequences(1, allSequences);
    allSequences.sort(); // don't want to assume a certain ordering
    EXPECT_EQUAL(allSequences, {"1", "2", "3", "4", "5", "6"});
}

