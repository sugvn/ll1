#include "parser.hpp"

int main() {
        Grammar g;
        vector<Rule> rules;
        rules = {{'E', "E+T"}, {'E', "T"},   {'T', "T*F"},
                 {'T', "F"},   {'F', "(E)"}, {'F', "i"}};
        g.addRules(rules);

        Parser recDesc("charizard");
        recDesc.build(g);
        recDesc.printTable();
        return 0;
}
