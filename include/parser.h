#ifndef REC_PARSER_IMPLEMENTATION
#define REC_PARSER_IMPLEMENTATION

#include "table.h"
#include <stdbool.h>
#include "grammar.h"
typedef struct {
        Grammar *grammar;
        ParseTable table;
        Str first_set[MAX_PRODUCTIONS]; // because first set is part of the parsing process not grammar
} Parser;

// Public facing api
/* the given grammar should be free of left recursion 
 and should be left factored and should be a valid grammar */
void parser_init(Parser *p,Grammar* g);
// builds a parse table for the given grammar
void parser_build(Parser* p);
// parses the given input against the grammar using 1 token look ahead
bool parser_parse(Parser* p,Str input);

// Private helpers
// checks if the grammar is 1.valid 2.left recursive 3.left factorable
bool _parser_is_parseable(Parser *p);
// find the first set of all non terminals containing only the terminals they produce directly
void _parser_compute_first_terminals(Parser *p);

#endif
