#include "parser.h"
#include <string.h>

Grammar* grammar_create(int no_of_productions){
        int size = sizeof(Grammar) + (no_of_productions * sizeof(Production));
        Arena* a = arena_create(size);
        if(!a) return NULL;
        Grammar* g = (Grammar*)arena_alloc(a,sizeof(Grammar));
        if(!g) {
                free(a);
                return NULL;
        }
        g->productions = (Production*)arena_alloc(a,sizeof(Production) * no_of_productions);
        g->arena = a;
        g->no_of_productions = no_of_productions;
        g->count = 0;
        g->startSymbol = '$'; // default placeholder
        return g;
}


bool grammar_add_production(Grammar* g,char nt,char* t){
        if(g->count+1 < g->no_of_productions){
                g->productions[g->count].t = t;
                g->productions[g->count].nt = nt;
                g->count++;
                return true;
        }
        return false;
}
