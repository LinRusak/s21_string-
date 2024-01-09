#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *tmp_str = str;
  while (*str != '\0') {
    str++;
    if (*str == c) tmp_str = str;
  }
  if (*tmp_str != c) tmp_str = s21_NULL;
  return (char *)tmp_str;
}
