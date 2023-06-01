#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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
  int index = 0;
  int cons = 0;

  const char *list[] = {"null","equal", "add" ,"print" ,"to", "string", "iden"};

  // Get the tokens from the file
  do {

    str = scan(str, &token[n_tokens]);
    n_tokens++;

  } while (token[n_tokens].type != T_NULL);

  // We get syntax expressions from the token
  do {

    // Go the next set of tokens
    index += cons;

    // Gets the number of tokens of the syntax expressions
    cons = parse((struct token *)(token + index));

    printf("%d\n", cons);

  } while (cons && index + cons < n_tokens);

  return 0;
}
