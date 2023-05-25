#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"

int line = 0;
char *_put_back = "";

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

char *skip(char *str) {
  while (isspace(*str)) {
    str++;
  }
  return str;
}

char *scan(char *str, struct token *token) {

  static const struct {
    char *word;
    unsigned int type;

  } key_words[] = {
      {
          "add",
          T_ADD,
      },

      {
          "print",
          T_PRINT,
      },
      {
          "to",
          T_TO,
      },

  };

  str = skip(str);

  if (strncmp(str, "add", 3) == 0) {
    token->type = T_ADD;
    str += 3;
    return str;
  }
  if (strncmp(str, "to", 2) == 0) {
    token->type = T_TO;
    str += 2;
    return str;
  }

  if (strncmp(str, "print", 5) == 0) {
    token->type = T_PRINT;
    str += 5;
    return str;
  }

  if (isalpha(*str)) {
    while (isalpha(*str)) {
      token->type = T_IDEN;
      str++;
    }
    return str;
  }

  switch (*str) {
  case 0:
    token->type = T_NULL;
    return str;
  case '=':
    token->type = T_EQUAL;
    str++;
    return str;
  case '"':
    token->type = T_COMMA;
    str++;
    return str;
  }

  return str;
}
