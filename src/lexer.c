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
  Token *token;
  token->type = type;
  token->literal = literal;
  return token;
}

Lexer *lexer_new(char *input) {

  Lexer *l = (Lexer *)malloc(sizeof(Lexer));

  if (!l)
    return NULL;

  l->input = input;
  read_char(l);
  return l;
}

void *read_char(Lexer *l) {

  if (l->read_position >= sizeof(&l->input) / sizeof(l->input[0]))
    l->ch = 0;
  else
    l->ch = l->input[l->read_position];

  l->position = l->read_position;
  l->read_position++;

  return l;
}

Token *token_next(Lexer *l) {

  Token *token = (Token *)malloc(sizeof(Token));

  switch (l->ch) {
  case '=':
    token = token_create(T_ASSIGN, l->ch);
    break;
  case ';':
    token = token_create(T_SEMICOLON, l->ch);
    break;
  case '(':
    token = token_create(T_LPAREN, l->ch);
    break;
  case ')':
    token = token_create(T_RPAREN, l->ch);
    break;
  case ',':
    token = token_create(T_COMMA, l->ch);
    break;
  case '+':
    token = token_create(T_PLUS, l->ch);
    break;
  case '{':
    token = token_create(T_LBRACE, l->ch);
    break;
  case '}':
    token = token_create(T_RBRACE, l->ch);
    break;

  default:
    token->literal = 0;
    token->type = T_NULL;
    break;
  }

  read_char(l);

  return token;
};
