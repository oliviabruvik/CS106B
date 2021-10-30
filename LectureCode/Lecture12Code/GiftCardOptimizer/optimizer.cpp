/*
 * optimizer.cpp
 *
 * @author Cynthia Lee
 * @version 2122-Aut
 *
 * Demonstrates backtracking recursion to generate all possible
 * subsets. This program considers a list of items available for purchase,
 * and attempts to see if some subset of them will sum to exactly the
 * amount that is available on a gift card.
 */

#include <iostream>
#include "console.h"
#include "strlib.h"
#include "set.h"
#include "testing/SimpleTest.h"
using namespace std;


/* Function Prototypes */
bool canUseFullGiftCard(int giftCardAmt, Set<int>& itemsForSale, Set<int>& itemsToBuy);


int main()
{
    if (runSimpleTests(SELECTED_TESTS)) {
        return 0;
    }
    cout << "All done, exiting" << endl;
    return 0;
}

/* canUseFullGiftCard()
 * The function seeks to find a subset of items to buy whose prices
 * will sum to EXACTLY the amount of funds available on the gift card.
 * @param giftCardAmt is the amount of funds available to purchase items
 * @param itemsForSale is a set of items (by price) that are available for
 *        purchase. We assume that only one item exists per price, so if
 *        13 is in the list then you may only purchase one item for $13.
 * @param itemsToBuy is an initially-empty set that--if the function returns
 *        true--will contain the list of items (by price) that should be
 *        purchased
 * @returns true if a successful set of items was found, else false
 */
bool canUseFullGiftCard(int giftCardAmt, Set<int>& itemsForSale, Set<int>& itemsToBuy)
{
    // base case success: card amount is spent down to 0 exactly
    if (giftCardAmt == 0) {
        return true;
    }
    // base case failure: we either overspent, or we need to spend more but there are
    //                    no more items for sale, so we can't succeed
    if (giftCardAmt < 0 || itemsForSale.size() == 0) {
        return false;
    }

    // recursive case: consider 1 next item (and remove it from future consideration,
    //                 since we are fully considering it now)
    int item = itemsForSale.first();
    Set<int> newItemsForSale = itemsForSale - item;
    // Our two choices are that we can either BUY THE ITEM and go on to consider
    //   other additional purchases with less money to spend...
    itemsToBuy += item;
    if (canUseFullGiftCard(giftCardAmt - item, newItemsForSale, itemsToBuy)) {
        return true;
    }
    // ...or NOT BUY THE ITEM and go on to conider other additional purchases with
    //    the same amount to spend.
    itemsToBuy -= item;
    if (canUseFullGiftCard(giftCardAmt, newItemsForSale, itemsToBuy)) {
        return true;
    }
    return false; // if neither of the two options can work, we have exhausted all options
}




/* * * * * * Test Cases * * * * * */

PROVIDED_TEST("Simple successful example")
{
    Set<int> itemsForSale = {2, 3, 4, 6};
    Set<int> itemsToBuy;
    EXPECT(canUseFullGiftCard(7, itemsForSale, itemsToBuy));
    EXPECT_EQUAL(itemsToBuy, {3, 4});
}

PROVIDED_TEST("Unsuccessful example: can buy some items, but not exact total")
{
    Set<int> itemsForSale = {1, 3, 4, 5};
    Set<int> itemsToBuy;
    EXPECT(!canUseFullGiftCard(2, itemsForSale, itemsToBuy));
}

PROVIDED_TEST("Unsuccessful example: buying everything still not enough")
{
    Set<int> itemsForSale = {1, 3, 4, 5};
    Set<int> itemsToBuy;
    EXPECT(!canUseFullGiftCard(25, itemsForSale, itemsToBuy));
}

PROVIDED_TEST("Edge case: invalid initial gift card amount (negative)")
{
    Set<int> itemsForSale = {1, 2, 3, 4, 5};
    Set<int> itemsToBuy;
    EXPECT(!canUseFullGiftCard(-10, itemsForSale, itemsToBuy));
}

PROVIDED_TEST("Edge case: no items for sale, but also $0 gift card = success")
{
    Set<int> itemsForSale = {};
    Set<int> itemsToBuy;
    EXPECT(canUseFullGiftCard(0, itemsForSale, itemsToBuy));
    EXPECT_EQUAL(itemsToBuy, {});
}
