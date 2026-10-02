#ifndef PARSER_GRAMMAR_IMPLEMENTATION
#define PARSER_GRAMMAR_IMPLEMENTATION
#define MAX_TERMINALS 50

#include "str.h"
#include "dynamic_array_str.h"
#include <stdbool.h>

// start symbol is always S
typedef struct {
        vec_str productions[26];

        char non_terminals[26];
        int n_non_terminals;

        char terminals[MAX_TERMINALS];
        int n_terminals;

        int no_of_productions;
} Grammar;

Grammar grammar_init();
void grammar_destroy(Grammar* g);
void grammar_add_production(char nt,Str rhs);

#endif
