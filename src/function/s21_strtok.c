#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *olds = s21_NULL;
  char *token;

  if (str == s21_NULL) {
    str = olds;
  }

  str += s21_strcspn(str, delim);
  if (*str == '\0') {
    olds = str;
    return s21_NULL;
  }

  token = str;
  str = s21_strpbrk(token, delim);
  if (str == s21_NULL) {
    olds = s21_strchr(token, '\0');
  } else {
    *str = '\0';
    olds = str + 1;
  }
  return token;
}
