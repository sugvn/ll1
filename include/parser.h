#ifndef REC_PARSER_IMPLEMENTATION
#define REC_PARSER_IMPLEMENTATION

#include "table.h"
#include <stdbool.h>
#include "grammar.h"
 typedef struct {
         Grammar* grammar;
         ParseTable* table;
 } Parser;

// Public facing api
/* the given grammar should be free of left recursion 
 and should be left factored and is a valid grammar */
Parser* parser_create(Grammar* g);
// builds a parse table for the given grammar
void parser_build(Parser* p);
// parses the given input against the grammar using 1 token look ahead
bool parser_parse(char* input);

// Private helpers
bool parser_parseable(Grammar* g);
bool parser_is_valid_grammar(Grammar *g);
bool parser_is_left_recursive(Grammar* g);
bool parser_is_left_factorable(Grammar* g);

#endif
