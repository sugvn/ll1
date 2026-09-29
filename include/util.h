#ifndef LL1_PARSER_UTIL
#define LL1_PARSER_UTIL
#include "grammar.h"
#include "str.h"
#include <ctype.h>
#include <stdbool.h>

int* build_nullable_set(Grammar *grammar) {
        if (!grammar) return NULL;
        Production *p = grammar->productions;
        int n = grammar->no_of_productions;
        if (!p || n<=0) return NULL;

        int* epsl = calloc(26,sizeof(int));
        if(!epsl) return NULL;

        // find productions that produce epsilon by itself
        for(int i=0;i<n;i++) {
                char nt = p[i].nt;
                Str rhs = p[i].rhs;        
                bool is_null = str_eq(rhs,STR("!"));
                if (is_null) {
                        epsl[nt - 'A'] = 1;
                } 
        }

        bool changed = true;
        // iterate as long as epsl changes
        // since the new state of epsl may make other productions nullable
        while(changed) {
                changed = false;

                // iterate over all productions
                for(int i=0;i<n;i++) {
                        char nt = p[i].nt;
                        Str rhs = p[i].rhs;        
                        if(epsl[nt - 'A']) continue;
                        int rhslen = rhs.len;

                        // check nullability of rhs of one production
                        for(int j=0;j<rhslen;j++){
                                char c = str_at(rhs, j);

                                // if c is epsilon
                                if(c=='!') {
                                        if (j==rhslen-1) {
                                                epsl[nt-'A'] = 1;
                                                // epsl[] is changed
                                                changed = true;
                                        }
                                        continue;
                                }

                                // atleast one terminal found
                                if(!isupper(c)) break;

                                // if non terminal
                                // if atleast one non terminal is not nullable,production is not nullable,break
                                if(epsl[c-'A']==0) break;
                                // if non terminal is nullable,check remaining
                                
                                // if loop continues until last element of rhs ,then the whole rhs is
                                // nullable,thus set production as nullable
                                if(j==rhslen-1){
                                        epsl[nt-'A'] = 1;
                                        // epsl[] is changed
                                        changed = true;
                                }
                        }
                }
        }
        return epsl;
}
#endif
