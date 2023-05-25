#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>

// Token Structure
struct token {
  unsigned int type; // type of the token
  unsigned int pos;  // or offset (offset inside the file)
};

// Tokens
enum { T_NULL, T_EQUAL, T_ADD, T_PRINT, T_TO, T_COMMA, T_IDEN};

// Functions
char *read_file(const char *path);
char *scan(char *str, struct token *token);
char *skip(char *str);

#endif // !
