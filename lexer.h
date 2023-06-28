#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
// Token Structure
typedef struct Token
{
  unsigned int type; // type of the token
  unsigned int pos;  // or offset (offset inside the file)
} Token;

// Tokens
enum
{
  T_NULL,
  T_ASSIGN,
  T_PLUS,
  T_STRING,
  T_IDEN,
  T_INT,
  T_COMMA,
  T_SEMICOLON,
  T_LPAREN,
  T_RPAREN,
  T_LBRACE,
  T_RBRACE,
  T_FUNCTION,
  T_LET
};

// Functions
char *read_file(const char *path);
char *scan(char *str, Token *token);
char *skip(char *str);
Token lookup_inden(char *str);

#endif // !
