#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"

int line = 0;
char *_put_back = "";

char *next() {

  char *buffer;
  int i, ch;

  for (i = 0;
       (i < (sizeof(buffer) - 1) && ((ch = fgetc(fp)) != EOF) && (ch != '\n'));
       i++) {
    buffer[i] = ch;
  }

  buffer[i] = '\0';

  if (fclose(fp))
    perror("fclose error");

  return buffer;
}

char *skip() {
  char *c;

  c = next();
  while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
    c = next();
  }
  return (c);
}

int scan(struct token *t) {
  char *c;
  c = skip();

  switch (*c) {
  case EOF:
    return 0;
  case '=':
    t->type = T_EQUAL;
    break;
  case '"':
    t->type = T_COMMA;
    break;
  }

  if (strcmp(c, "add") == 0)
    t->type = T_ADD;
  if (strcmp(c, "to") == 0)
    t->type = T_TO;
  if (strcmp(c, "print") == 0)
    t->type = T_PRINT;

  return 0;
}
