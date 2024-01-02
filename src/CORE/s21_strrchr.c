#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  s21_size_t count = s21_strlen(str);
  char *buffer = s21_NULL;
  for (s21_size_t i = 0; i < count; i++) {
    if (str[i] == c) {
      buffer = (char *)&str[i];
    }
  }
  return buffer;
}
