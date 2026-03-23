#ifndef REC_PARSER
#define REC_PARSER
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using std::unordered_map;
using std::string;
using std::cout;
using std::vector;
using std::endl;

typedef struct Rule{
        char left;
        string right;
}Rule;

class Grammar {
        public:
                unordered_map<char,vector<string>> grammars;
                char startSymbol;
                Grammar(){}
                bool addRule(Rule rule){
                        if(grammars.empty()) startSymbol = rule.left;
                        grammars[rule.left].push_back(rule.right);
                        cout<<"hello world"<<endl;
                        return true;
                }
};


class Parser {
        public:
                Parser(string n):name(n){}
                bool parse(string input,Grammar g){
                        if(input.empty()) return true;
                        int length=input.size();
                        int i=0;
                        while(i<length){
                                char look=input[i];
                                char current_nt=g.startSymbol;
                        }

                }
        private:
                string name;
};

#endif
