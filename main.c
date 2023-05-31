#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "parser.h"

// word a
// equal sign
// string "Hello"
// word add
// string " world"
// word to
// word a
// word print
// word a

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: rune [script]\n");
    return -1;
  }

  char *str = read_file(argv[1]);
  char *start = str;

  struct token token[100];
  int n_tokens = 0;

  do {

    str = scan(str, &token[n_tokens]);
  } while (token[n_tokens].type != T_NULL);

  parse(token[n_tokens]);

  return 0;
}
