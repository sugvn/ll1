#ifndef REC_PARSER_IMPLEMENTATION
#define REC_PARSER_IMPLEMENTATION
#include "arena.h"
#include <stdbool.h>

typedef struct {
        char nt;
        char* t;
} Production;

typedef struct {
        Production *productions;
        char startSymbol;
        int count;
        int no_of_productions;
        Arena* arena;
} Grammar;

Grammar* grammar_create(int no_of_productions);
void grammar_destroy(Grammar* g);
bool grammar_add_production(Grammar* g,char nt,char* t); //return false if error , true if success

#endif
