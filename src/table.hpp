#ifndef PARSE_TABLE
#define PARSE_TABLE
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class ParseTable {
private:
        // non terminal and terminal is concatenated to form a string key
        // table[key] returns a rule number (int) as a value
        unordered_map<string, int> table;

        // to iterate the table
        unordered_set<char> non_terminals;
        unordered_set<char> terminals;

public:
        // takes in all the non terminals and terminals and builds the table
        // with default value as 0
        ParseTable(unordered_set<char> &non_terminals, unordered_set<char> &terminals) {
                this->non_terminals = non_terminals;
                this->terminals = terminals;
                for (char n : non_terminals) {
                        for (char t : terminals) {
                                string s ={n,t};
                                table[s] = 0; // No production
                        }
                }
        }

        bool set(char non_terminal, char terminal, int ruleNo) {
                string s = {non_terminal,terminal};
                auto v = table.find(s);
                if (v == table.end()) {
                        return false;
                }
                v->second = ruleNo;
                return true;
        }

        // returns 0 if no (non_terminal,terminal) pair exists
        int get(char non_terminal, char terminal) {
                string s = {non_terminal,terminal};
                auto v = table.find(s);
                if (v == table.end()) {
                        return 0;
                }
                return v->second;
        }

        void printTable(){
                //print the column headings
                std::cout<<" ";
                for(auto i:terminals){
                       std::cout<<" "<<i ;
                }
                //print each rows
                for(auto i:non_terminals){
                        std::cout<<i; 
                        for(auto j:terminals){
                                std::cout<<" "<<table[{i,j}] ;
                        }
                        std::cout<<"\n";
                }
        }
};

#endif
