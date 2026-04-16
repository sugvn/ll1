#ifndef PARSER_GRAMMAR_IMPLEMENTATION
#define PARSER_GRAMMAR_IMPLEMENTATION
#define MAX_PRODUCTIONS 32

#include "str.h"
#include <stdbool.h>

typedef struct {
        char nt;
        Str t;
} Production;

typedef struct {
        Production productions[MAX_PRODUCTIONS];
        char startSymbol;
        int no_of_productions;
} Grammar;

void grammar_init(Grammar *g,int no_of_productions);
void grammar_destroy(Grammar* g);
void grammar_add_production(Grammar *g,char nt,Str t); 

#endif
