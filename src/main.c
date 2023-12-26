#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../includes/lexer.h"

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: rune [script]\n");
    return -1;
  }

  Token token;
  char *str = read_file(argv[1]);
  size_t size = sizeof(&str) / sizeof(str[0]);

  for (size_t i = 0; str[i] != '\0'; i++) {
    printf("%c", str[i]);
  }

  return 0;
}
