#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "lexer.h"

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    printf("Usage: rune [script]\n");
    return -1;
  }

  char *str = read_file(argv[1]);
  char *start = str;

  Token token;
  do
  {
    str = scan(str, &token);
    printf("%d\n", token.type);

  } while (token.type != T_NULL);

  return 0;
}
