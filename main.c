#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

int main(int argc, char *argv[]) {


  if (argc != 2) {
    printf("Usage: rune [script]\n");
    return -1;
  }

  char *str = read_file(argv[1]);
  return 0;
}
