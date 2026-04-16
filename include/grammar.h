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
// all Non terminals should have atleast one terminal in their first set
bool gramar_is_valid(Grammar *g);
// a non terminal should not produce itself as a prefix in its production
bool grammar_is_left_recursive(Grammar* g);
// no two productions of a same Non terminal should have same prefix
bool grammar_is_left_factorable(Grammar* g);

#endif
