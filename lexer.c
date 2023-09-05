#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
char *read_file(const char *path)
{
  FILE *file = fopen(path, "rb");

  if (file == NULL)
  {
    fprintf(stderr, "Could not open file \"%s\".\n", path);
    exit(74);
  }

  fseek(file, 0L, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = (char *)malloc(file_size + 1);

  if (buffer == NULL)
  {
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(74);
  }

  size_t bytes_read = fread(buffer, sizeof(char), file_size, file);

  if (bytes_read < file_size)
  {
    fprintf(stderr, "Could not read file \"%s\".\n", path);
    exit(74);
  }

  buffer[bytes_read] = '\0';

  fclose(file);
  return buffer;
}

char *skip(char *str)
{
  while (isspace(*str))
  {
    str++;
  }
  return str;
}

char *scan(char *str, Token *token)
{

  str = skip(str);

  if (strncmp(str, "let", 3) == 0)
  {
    token->type = T_LET;
    str += 3;
    return str;
  }

  if (isalpha(*str))
  {
    while (isalpha(*str))
    {
      token->type = T_IDEN;
      str++;
    }
    return str;
  }

  if (isdigit(*str))
  {
    while (isdigit(*str))
    {
      if (*str == 0)
        break;
      token->type = T_INT;
      str++;
    }

    return str;
  }

  if (strncmp(str, "fn", 2) == 0)
  {
    token->type = T_FUNCTION;
    str += 2;
    return str;
  }

  switch (*str)
  {
  case 0:
    token->type = T_NULL;
    return str;
  case '=':
    token->type = T_ASSIGN;
    str++;
    return str;
  case ',':
    token->type = T_COMMA;
    str++;
    return str;
  case '{':
    token->type = T_LBRACE;
    str++;
    return str;

  case '}':
    token->type = T_RBRACE;
    str++;
    return str;

  case '(':
    token->type = T_LPAREN;
    str++;
    return str;

  case ')':
    token->type = T_RPAREN;
    str++;
    return str;
  case '"':
    token->type = T_STRING;
    str++;
    while (*str != '"')
    {
      str++;
    }
    str++;
    return str;
  }

  return str;
}
