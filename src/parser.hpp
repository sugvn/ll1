#ifndef REC_PARSER
#define REC_PARSER
#include "table.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

typedef struct {
        char left;
        string right;
} Rule;

class Grammar {
public:
        unordered_map<char, vector<string>> grammars;
        char startSymbol;
        Grammar(char s) { startSymbol = s; }
        bool addRule(Rule rule) {
                grammars[rule.left].push_back(rule.right);
                return true;
        }
};

class Parser {
public:
        Parser(string n) : name(n) {}
        bool parse(string input, Grammar g) {
                // as of now, assume empty strings are parseable for all
                // grammars(which is wrong)
                if (input.empty())
                        return true;
                unordered_set<char> non_terminals;
                unordered_set<char> terminals;
                // find all non_terminals and terminals from the grammar
                auto &grammar = g.grammars;
                for (auto i : grammar) {
                        non_terminals.insert(i.first);
                        for (auto s : i.second) {
                                for (auto c : s) {
                                        bool y = std::isupper(c);
                                        if(y) non_terminals.insert(c);
                                        else terminals.insert(c);
                                }
                        }
                }
        }

private:
        string name;
};

#endif
