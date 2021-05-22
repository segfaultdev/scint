#include <sc_token.h>
#include <stdlib.h>
#include <string.h>

static inline int is_space(char c) {
  return (c <= 32);
}

static int is_integer(const char *buffer, int size) {
  char *last_valid;
  strtol(buffer, &last_valid, 0);

  int is_int = !(*last_valid);
  int is_hex = (*last_valid == 'x') && (*(last_valid - 1) = '0');

  return is_int || is_hex;
}

int sc_identify(const char *buffer, int size) {
  if (!strncmp(buffer, ";", size)) return TOKEN_SEMICOLON;
  if (!strncmp(buffer, "(", size)) return TOKEN_PAREN_OPEN;
  if (!strncmp(buffer, ")", size)) return TOKEN_PAREN_CLOSE;
  if (!strncmp(buffer, "{", size)) return TOKEN_BLOCK_OPEN;
  if (!strncmp(buffer, "}", size)) return TOKEN_BLOCK_CLOSE;

  if (!strncmp(buffer, "return", size)) return TOKEN_RETURN;

  if (is_integer(buffer, size)) return TOKEN_INTEGER;
  if (is_identifier(buffer, size)) return TOKEN_IDENTIFIER;

  return TOKEN_INVALID;
}

token_t sc_consume(const char **buffer_ptr) {
  int length = 0;

  const char *buffer = *buffer_ptr;

  int type = TOKEN_INVALID;

  char c;
  while ((c = *buffer)) {
    if (!length && is_space(c)) {
      buffer++;
      continue;
    }

    int new_type = sc_identify(buffer, length + 1);

    if (new_type == TOKEN_INVALID && type != TOKEN_INVALID) {
      token_t token;

      token.buffer = buffer;
    } else if (!is_space())
  }

  *buffer_ptr = buffer;
}
