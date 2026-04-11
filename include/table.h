#ifndef PARSE_TABLE_IMPLEMENTATION
#define PARSE_TABLE_IMPLEMENTATION

typedef struct {
        /* initially
         26 non terminals A-Z
         28 Terminals a-z,~(epsilon),$(start symbol) */
        int table[26][28];
} ParseTable;

ParseTable* parseTable_create();
#endif
