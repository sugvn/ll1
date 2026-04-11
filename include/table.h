#ifndef PARSE_TABLE_IMPLEMENTATION
#define PARSE_TABLE_IMPLEMENTATION
/* initially
 26 non terminals A-Z
 28 Terminals a-z,~(epsilon),$(start symbol) */
#define MAX_NT 26
#define MAX_T 26

typedef struct {
        int table[MAX_NT][MAX_T];
} ParseTable;

ParseTable* parseTable_create();

/* if at all our non terminal size grows
 handle idx calculation manually */
int parseTable_calculate_row_idx(char nt); 
/* if at all our terminal size grows
 handle idx calculation manually */
int parseTable_calculate_column_idx(char t); 

void parseTable_set(ParseTable *pt,char nt,char t,int val);
#endif
