#include <stdio.h>
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
