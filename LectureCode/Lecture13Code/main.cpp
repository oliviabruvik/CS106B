#include "console.h"
#include <iostream>
#include "speller.h"

using namespace std;

int main() {
    sharedLex(); // warm up lexicon here
    cout << "Welcome to the state speller playground!" << endl << endl;
    playground();
    cout << endl << "All done, exiting." << endl;
    return 0;
}

// Move helper code here to avoid cluttering the module to edit in lecture
Lexicon& sharedLex() {
    static Lexicon lex("res/EnglishWords.txt");
    return lex;
}

Set<string>& allStates() {
   static Set<string> all = {"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "FL", "GA",
                   "HI", "ID", "IL", "IN", "IA", "KS", "KY", "LA", "ME", "MD",
                   "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ",
                   "NM", "NY", "NC", "ND", "OH", "OK", "OR", "PA", "RI", "SC",
                   "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};
   return all;
}
