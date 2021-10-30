/*
 * combolock.cpp
 *
 * @author Cynthia Lee
 * @version 2122-Aut
 *
 * Demonstrates combining loops with recursion to generate all possible
 * sequences. The program generates all possible combo lock sequences,
 * i.e., sequences of 3 numbers 1-39, and tests each to see if it opens
 * the lock.
 */

#include <iostream>
#include "console.h"
#include "strlib.h"
#include "vector.h"
#include "testing/SimpleTest.h"
using namespace std;


/* Function Prototypes */
bool findCombo(Vector<int>& combo);
bool tryCombo(Vector<int>& combo);

/* Constants */
const int MIN_COMBO_NUM  = 1;
const int MAX_COMBO_NUM  = 39;
const int COMBO_LENGTH   = 3;
const Vector<int> ANSWER = {7, 33, 21};


int main()
{
    if (runSimpleTests(SELECTED_TESTS)) {
        return 0;
    }
    cout << "All done, exiting" << endl;
    return 0;
}

/* findCombo()
 * The program generates all possible combo lock sequences, i.e.,
 * sequences of 3 numbers 1-39, and tests each to see if it
 * opens the lock.
 * @param combo is an initially-empty vector that will contain the
 *        three numbers of the lock upon successful (true) return
 * @returns true if a successful combo was found, else false
 */
bool findCombo(Vector<int>& combo)
{
    // base case: this sequence is full-length and ready to try on the lock!
    if (combo.size() == COMBO_LENGTH) {
        return tryCombo(combo);
    }

    // recursive cases: add 1-39 and continue
    for (int i = MIN_COMBO_NUM; i <= MAX_COMBO_NUM; i++) {
        combo += i;
        if (findCombo(combo)) {
            return true;
        }
        combo.remove(combo.size() - 1);
    }
    return false;
}

/* tryCombo()
 * This is meant to simulate trying a 3-number combination on
 * the actual lock to see if it opens it. Above is defined an
 * arbitrary 3-number combination that we treat as the right one.
 * @param combo should contain 3 numbers in the range 1-39
 * @returns true if the combo opened the lock, otherwise false
 */
bool tryCombo(Vector<int>& combo)
{
    return combo == ANSWER;
}


/* * * * * * Test Cases * * * * * */

PROVIDED_TEST("Basic correctness") {
    Vector<int> combo;
    EXPECT(findCombo(combo));
    EXPECT_EQUAL(combo, ANSWER);
}


