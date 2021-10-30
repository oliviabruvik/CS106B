/*
 * container.cpp
 *
 * @author Cynthia Lee
 * @version 2122
 *
 * A program to demonstrate how container-within-a-container works
 * in terms of deep or shallow copies.
 */

#include <iostream>
#include "console.h"
#include "vector.h"
#include "map.h"
#include "testing/SimpleTest.h"
using namespace std;

int main()
{
    runSimpleTests(SELECTED_TESTS);
    return 0;
}

/* * * * * * Test Cases * * * * * */

PROVIDED_TEST("Attempt to add with numbers.add(4)")
{
    Vector<int> numbers;
    numbers.add(1);
    numbers.add(2);
    numbers.add(3);
    Map<string, Vector<int>> mymap;
    mymap["abc"] = numbers;

    // This is the part that differs
    numbers.add(4);

    EXPECT_EQUAL(mymap["abc"].size(), 4);
}

PROVIDED_TEST("Attempt to add with mymap[\"abc\"].add(4)")
{
    Vector<int> numbers;
    numbers.add(1);
    numbers.add(2);
    numbers.add(3);
    Map<string, Vector<int>> mymap;
    mymap["abc"] = numbers;

    // This is the part that differs
    mymap["abc"].add(4);

    EXPECT_EQUAL(mymap["abc"].size(), 4);
}

PROVIDED_TEST("Attempt to add with test.add(4)")
{
    Vector<int> numbers;
    numbers.add(1);
    numbers.add(2);
    numbers.add(3);
    Map<string, Vector<int>> mymap;
    mymap["abc"] = numbers;

    // This is the part that differs
    Vector<int> test = mymap["abc"];
    test.add(4);

    EXPECT_EQUAL(mymap["abc"].size(), 4);
}

