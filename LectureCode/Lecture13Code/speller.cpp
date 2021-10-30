#include "speller.h"
using namespace std;


void printStateWords(int n, Set<string>& states, Lexicon& lex, string sofar)
{
    if (n == 0) {
        if (lex.contains(sofar)) {
            cout << sofar << endl;
        }
    } else {
        for (string option : states) {
            printStateWords(n - 1, states, lex, sofar + option);
        }
    }
}

void printAll(Set<string>& states, Lexicon& lex, string sofar)
{
    if (!lex.containsPrefix(sofar)) {
        return;
    } else if (lex.contains(sofar)) {
        cout << sofar << endl;
    }
    for (string option : states) {
        printAll(states, lex, sofar + option);
    }
}

void printNoRepeat(Set<string>& states, Lexicon& lex, string sofar)
{
    if (!lex.containsPrefix(sofar)) {
        return;
    } else if (lex.contains(sofar)) {
        cout << sofar << endl;
    }
    for (string option : states) {
        Set<string> rest = states - option;
        printNoRepeat(rest, lex, sofar + option);
    }
}

bool findOne(Set<string>& states, Lexicon& lex, string sofar)
{
    if (!lex.containsPrefix(sofar)) {
        return false;
    } else if (lex.contains(sofar)) {
        return true;
    }
    for (string option : states) {
        if (findOne(states, lex, sofar + option))
            return true;
    }
    return false;
}

string findWord(Set<string>& states, Lexicon& lex, string sofar)
{
    if (!lex.containsPrefix(sofar)) {
        return "";
    } else if (lex.contains(sofar)) {
        return sofar;
    }
    for (string option : states) {
        string result = findWord(states, lex, sofar + option);
        if (!result.empty()) return result;
    }
    return "";
}

string findLongest(Set<string>& states, Lexicon& lex, string sofar)
{
    string best;

    if (!lex.containsPrefix(sofar)) {
        return "";
    } else if (lex.contains(sofar)) {
        best = sofar;
    }
    for (string option : states) {
        string cur = findLongest(states, lex, sofar + option);
        if (cur.length() > best.length()) {
            best = cur;
        }
    }
    return best;
}


void playground()
{
    Lexicon lex = sharedLex();
    Set<string> smallSet = {"AL", "CA", "DE", "ID", "ND", "OR", "SC", "WI"};
    Set<string> fullSet = allStates();
    Set<string> states = fullSet;

    cout << endl << "Print 2-state words" << endl;
    printStateWords(2, states, lex, "");

    cout << endl << "Print 3-state words" << endl;
    printStateWords(3, states, lex, "");

    cout << endl << "Print all words" << endl;
    printAll(states, lex, "");

    cout << endl << "Print without repeats" << endl;
    printNoRepeat(states, lex, "");

    cout << endl << "Find one T/F" << endl;
    cout << findOne(states, lex, "");

    cout << endl << "Find one word " << endl;
    cout << findWord(states, lex, "");

    cout << endl << "Find longest word" << endl;
    cout << findLongest(states, lex, "");
}


