#ifndef LEXER_H
#define LEXER_H

// Tokens
enum {
  T_IDEN,
  T_INT,
  T_NULL,
  T_ASSIGN,
  T_PLUS,
  T_STRING,
  T_COMMA,
  T_SEMICOLON,
  T_LPAREN,
  T_RPAREN,
  T_LBRACE,
  T_RBRACE,
  T_FUNCTION,
  T_LET
};

typedef struct Token {
  unsigned int type;
  char literal;
} Token;

char *read_file(const char *path);
Token *token_create(char type, char literal);

#endif // !
