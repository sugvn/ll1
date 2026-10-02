#ifndef PARSER_GRAMMAR_IMPLEMENTATION
#define PARSER_GRAMMAR_IMPLEMENTATION
#define MAX_PRODUCTIONS 32

#include "str.h"
#include <stdbool.h>

typedef struct {
        char nt;
        Str rhs;
} Production;

// start symbol is always s
typedef struct {
        Production *productions;
        int no_of_productions;
} Grammar;

Grammar grammar_init(Production *productions,int no_of_productions);
void grammar_destroy(Grammar* g);

#endif
