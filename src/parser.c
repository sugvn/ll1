#include "parser.h" 
#include "grammar.h"
#include "table.h"
#include <stdlib.h>
#include <stdbool.h>

void parser_init(Parser *p, Grammar *g){
        if(!p) return;
        if(!g) return;
        p->grammar = g;
}

bool _parser_is_parseable(Parser *p){
        bool valid = grammar_is_valid(p->grammar);
        bool left_recursive = grammar_is_left_recursive(p->grammar);
        bool left_factorable = grammar_is_left_factorable(p->grammar);
        return valid && !left_recursive && !left_factorable;
}

