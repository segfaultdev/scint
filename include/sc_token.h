#ifndef __SC_TOKEN_H__
#define __SC_TOKEN_H__

typedef struct token_t token_t;

struct token_t {
  int type;

  char *buffer;
  int length;

  int line, column;
};

#define TOKEN_INVALID     0
#define TOKEN_INTEGER     1
#define TOKEN_IDENTIFIER  2
#define TOKEN_RETURN      3
#define TOKEN_SEMICOLON   4
#define TOKEN_PAREN_OPEN  5
#define TOKEN_PAREN_CLOSE 6
#define TOKEN_BLOCK_OPEN  7
#define TOKEN_BLOCK_CLOSE 8

int sc_identify(const char *buffer, int size);
token_t sc_consume(const char **buffer_ptr);

#endif
