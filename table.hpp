#ifndef PARSE_TABLE
#define PARSE_TABLE
#include <vector>
#include <unordered_map>
#include <string>
using std::vector;
using std::unordered_map;
using std::string;

class ParseTable {
        private:
                unordered_map<string,int> table;
                vector<char> non_terminals;
                vector<char> terminals;
        public:
                ParseTable(){}
                ParseTable(vector<char> non_terminals,vector<char> terminals){
                        this->non_terminals = non_terminals;
                        this->terminals = terminals;
                        for(char n:non_terminals){
                                for(char t:terminals){
                                        string s = std::to_string(n) + std::to_string(t);
                                        table[s] = -1; // No production
                                }
                        }
                }
};

#endif
