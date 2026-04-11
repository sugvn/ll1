#include "parser.h" 
#include "grammar.h"
#include "table.h"
#include <stdlib.h>
#include <stdbool.h>

Parser* parser_create(Grammar* g){
        Parser* p = (Parser*)malloc(sizeof(Parser));
        if(!p) return NULL;
        p->grammar = g;
        p->table = parseTable_create();
        if(!p->table){
                free(p);
                return NULL;
        }
        return p;
} 


void parser_build(Parser* p){
}


bool parser_parse(char* input){}
