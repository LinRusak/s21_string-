#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int count = s21_strlen(dest);
  for (s21_size_t i = 0; i < n; i++) {
    dest[count + i] = src[i];
  }
  return dest;
}
