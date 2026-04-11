#ifndef REC_PARSER_IMPLEMENTATION
#define REC_PARSER_IMPLEMENTATION

#include "table.h"
#include <stdbool.h>
#include "grammar.h"
 typedef struct {
         Grammar* grammar;
         ParseTable* table;
 } Parser;

Parser* parser_create(Grammar* g);
void parser_build(Parser* p);
bool parser_parse(char* input);

#endif
