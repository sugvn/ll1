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
        public:
                ParseTable(){}
                ParseTable(vector<char> non_terminals,vector<char> terminals){

                }
};

#endif
