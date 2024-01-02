#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/lexer.h"

char *read_file(const char *path) {
  FILE *file = fopen(path, "rb");

  if (file == NULL) {
    fprintf(stderr, "Could not open file \"%s\".\n", path);
    exit(74);
  }

  fseek(file, 0L, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = (char *)malloc(file_size + 1);

  if (buffer == NULL) {
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(74);
  }

  size_t bytes_read = fread(buffer, sizeof(char), file_size, file);

  if (bytes_read < file_size) {
    fprintf(stderr, "Could not read file \"%s\".\n", path);
    exit(74);
  }

  buffer[bytes_read] = '\0';

  fclose(file);
  return buffer;
}

Token *token_create(unsigned int type, char literal) {
  Token *token = (Token *)malloc(sizeof(Token));
  token->type = type;
  token->literal = literal;
  return token;
}

Token *token_next(char ch) {
  Token *token = (Token *)malloc(sizeof(Token));
  switch (ch) {
  case '=':
    token = token_create(T_ASSIGN, ch);
    break;
  case ';':
    token = token_create(T_SEMICOLON, ch);
    break;
  case '(':
    token = token_create(T_LPAREN, ch);
    break;
  case ')':
    token = token_create(T_RPAREN, ch);
    break;
  case ',':
    token = token_create(T_COMMA, ch);
    break;
  case '+':
    token = token_create(T_PLUS, ch);
    break;
  case '{':
    token = token_create(T_LBRACE, ch);
    break;
  case '}':
    token = token_create(T_RBRACE, ch);
    break;

  default:
    token->literal = 0;
    token->type = T_NULL;
    break;
  }

  return token;
};
