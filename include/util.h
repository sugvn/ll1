#ifndef LL1_PARSER_UTIL
#define LL1_PARSER_UTIL
#include "grammar.h"
#include "str.h"
#include "dynamic_array.h"
#include "dynamic_array_str.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int* build_nullable_set(Grammar *grammar) {
        if (!grammar) return NULL;

        vec_str *productions = grammar->productions;
        int n = grammar->no_of_productions;
        char* non_terminals = grammar->non_terminals;
        int n_non_terminals = grammar->n_non_terminals;

        if (!productions || !non_terminals || n<=0) return NULL;

        int *epsl = calloc(26, sizeof(int));
        if (!epsl) return NULL;

        // find non terminals that produce epsilon by itself
        for(int i=0;i<n_non_terminals;i++) {
                char non_terminal = non_terminals[i];
                vec_str production = productions[non_terminal - 'A'];
                if(vec_str_is_empty(&production)) continue;
                int n_strings = production.size;
                for(int j=0;j<n_strings;j++){
                        Str rhs = production.ptr[j];
                        if(!rhs.val) {
                                perror("String not initialised");
                                exit(EXIT_FAILURE);
                        }
                        if(rhs.len==1 && rhs.val[0]=='!'){
                                epsl[non_terminal - 'A'] = 1;
                        }
                }
        }

        bool changed = true;
        // iterate as long as epsl changes
        // since the new state of epsl may make other productions nullable
        while(changed) {
                changed = false;

                // iterate over all productions
                for(int i=0;i<n_non_terminals;i++) {
                        char nt = non_terminals[i];
                        if(epsl[nt - 'A']) continue;
                        vec_str production = productions[nt - 'A'];
                        if(vec_str_is_empty(&production)) continue;
                        int n_strings = production.size;
                        for(int j=0;j<n_strings;j++){
                                Str rhs = production.ptr[j];
                                if(!rhs.val) {
                                        perror("String not initialised");
                                        exit(EXIT_FAILURE);
                                }
                                int rhslen = rhs.len;

                                // check nullability of rhs of one production
                                for(int k=0;k<rhslen;k++){
                                        char c = str_at(rhs, k);

                                        // if c is epsilon
                                        if(c=='!') {
                                                if (k==rhslen-1) {
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
                                        if(k==rhslen-1){
                                                epsl[nt-'A'] = 1;
                                                // epsl[] is changed
                                                changed = true;
                                        }
                                }
                        }

                }
        }
        return epsl;
}

bool is_grammar_valid(Grammar* g){
        if(!g || g->no_of_productions==0) return false;
        Production* productions = g->productions;
        if(!productions) return false;
        int n = g->no_of_productions;

        // build a set of all non terminals reachable from start symbol
        int reachable[26] = {0};
        vec_int start_symbol_productions_index;

        if(vec_init(&start_symbol_productions_index, MAX_PRODUCTIONS)!=0){
                perror("Error initialising vector");
                exit(EXIT_FAILURE);
        }

        //find the productions of start symbol S
        for (int i=0;i<n;i++){
                if(productions[i].nt == 'S'){
                        vec_append(&start_symbol_productions_index, i);
                }
        }
        
        if(vec_is_empty(&start_symbol_productions_index)){
                return false; 
        }
        int start_productions_count = start_symbol_productions_index.size;

        // build directly reachable from start symbol S
        for (int j=0; j < start_productions_count; j++) {
                Str s = (productions[vec_get(&start_symbol_productions_index,j)]).rhs;
                int s_len = s.len;

                for(int k=0;k<s_len;k++){
                        char c = str_at(s,k);
                        if(!isupper(c)) {
                                continue;
                        }
                        reachable[c-'A']=1;
                }
        }

        // build other reachables from directly reachables
        bool changed=true;
        while(changed){
                changed = false;
                for(int j=0;j<26;j++){

                }
        }

}
#endif
