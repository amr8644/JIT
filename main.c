#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

int main(int argc, char *argv[]) {

  FILE *fp;

  if (argc != 2) {
    printf("Usage: rune [script]\n");
    return -1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("Error in opening file");
    return (-1);
  }

  next();

  return 0;
}
