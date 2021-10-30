#include <iostream>
#include "testing/SimpleTest.h"
#include "console.h"
#include "vector.h"
#include <algorithm>
using namespace std;

struct BackpackItem {
    int survivalValue;  // You can assume this value will always >= 0
    int weight;         // You can assume this value will always >= 0
};

int fillBackpack(Vector<BackpackItem>& items, int targetWeight, int survivalValue, int index){
    if (index >= items.size()) {
        if (targetWeight >= 0) {
            return survivalValue;
        } else {
            return 0;
        }
    } else {
        return max(fillBackpack(items,
                                targetWeight - items[index].weight,
                                survivalValue + items[index].survivalValue,
                                index + 1),
                   fillBackpack(items,
                                targetWeight,
                                survivalValue,
                                index + 1));
    }
}

int fillBackpack(Vector<BackpackItem>& items, int targetWeight){
    return fillBackpack(items, targetWeight, 0, 0);
}

PROVIDED_TEST("Simple knapsack examples.") {
    int targetWeight = 18;
    Vector<BackpackItem> items = {
        {12, 4},
        {10,6},
        {8, 5},
        {11, 7},
        {14, 3},
        {7, 1},
        {9, 6}
    };
    EXPECT_EQUAL(fillBackpack(items, targetWeight), 44);

    targetWeight = 25;
    items = {
       {5, 6},
       {20, 15},
       {3, 11},
       {50, 12},
       {5, 6},
       {4, 11},
       {15, 13},
       {12, 7},
       {6, 17},
       {7, 13}
    };

    EXPECT_EQUAL(fillBackpack(items, targetWeight), 67);

    targetWeight = 5;
    items = {
       {3, 2},
       {4, 3},
       {5, 4},
       {6, 5}
    };

    EXPECT_EQUAL(fillBackpack(items, targetWeight), 7);
}
