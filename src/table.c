#include "table.h"
#include <stdlib.h>
#include <string.h>


ParseTable* parseTable_create(){
        ParseTable* pt = (ParseTable*)malloc(sizeof(ParseTable));
        memset(pt->table,0,sizeof(pt->table));
        return pt;
}
