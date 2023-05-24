#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>

extern FILE *fp;
// Token Structure
struct token {
  unsigned int type; // type of the token
  unsigned int pos;  // or offset (offset inside the file)
};

// Tokens
enum { T_NULL, T_EQUAL, T_ADD, T_PRINT, T_TO, T_VAR, T_COMMA, T_STRING, T_A };

char *next();
char *skip();
int scan(struct token *t);
void run_file(char *file);

#endif // !
