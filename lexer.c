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
  while (*str != '\t' || *str != '\n' || *str != '\r')
    str++;
  return str;
}

 char *scan(char *str, struct token *token) {
  switch (*str) {
  case 0:
    token->type = T_NULL;
    break;
  case '=':
    token->type = T_EQUAL;
    break;
  case '"':
    token->type = T_COMMA;
    break;
  }

  if (strcmp(str, "add") == 0)
    token->type = T_ADD;
  if (strcmp(str, "to") == 0)
    token->type = T_TO;
  if (strcmp(str, "print") == 0)
    token->type = T_PRINT;

  return str;
}
