#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>

extern FILE *fp;
// Token Structure
struct token {
    int token;
    char *value;
};

// Tokens
enum {
  T_EQUAL, T_ADD, T_PRINT, T_TO, T_VAR, T_COMMA,T_STRING,T_A
};

char *next();
void run_file(char * file);

#endif // !

