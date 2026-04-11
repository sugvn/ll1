#include "table.h"
#include <stdlib.h>
#include <string.h>


ParseTable* parseTable_create(){
        ParseTable* pt = (ParseTable*)malloc(sizeof(ParseTable));
        if(pt) memset(pt->table,0,sizeof(pt->table));
        return pt;
}

int parseTable_calculate_row_idx(char nt){
        int row_idx = nt - 'A';
        return row_idx;
}

int parseTable_calculate_column_idx(char t){
        int col_idx = t - 'a';
        return col_idx;
}

void parseTable_set(ParseTable *pt,char nt,char t,int val){
        int row_idx = parseTable_calculate_row_idx(nt);
        if(row_idx < 0 && row_idx >= MAX_NT) return;
        int col_idx = parseTable_calculate_column_idx(t);
        if(col_idx < 0 && col_idx >= MAX_T) return;
        pt->table[row_idx][col_idx] = val;

}

int parseTable_get(ParseTable* pt,char nt,char t){
        int row_idx = parseTable_calculate_row_idx(nt);
        if(row_idx < 0 && row_idx >= MAX_NT) return 0;
        int col_idx = parseTable_calculate_column_idx(t);
        if(col_idx < 0 && col_idx >= MAX_T) return 0;
        return pt->table[row_idx][col_idx];
}
