#include "lexer.h"
#include <math.h>
#include <stdio.h>

struct Expressions {
  unsigned int type[5];
} express[] = {
    // Example
    // a = "Hello World"
    {T_IDEN, T_EQUAL, T_STRING, T_NULL},

    // Example
    // add "Hello" to a
    {T_ADD, T_STRING, T_TO, T_IDEN, T_NULL},

    // Example
    // add "HELlO" to "World"
    {T_ADD, T_STRING, T_TO, T_STRING, T_NULL},

    // Example
    // print a
    {T_PRINT, T_IDEN, T_NULL},

    // Example
    // print "Hello World"
    {T_PRINT, T_STRING, T_NULL}};

int parse(struct token *token) {

  for (size_t i = 0; i < sizeof(express) / sizeof(express[0]); i++) {
    for (size_t j = 0; j < 5; j++) {
      if (express[i].type[j] != token[j].type) {
        break;
      }
      if (express[i].type[j] == 0) {
        return j;
      }
    }
  }
  return 0;
}
