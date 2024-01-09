#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int find = 0;
  for (; *str1 != '\0'; str1++) {
    for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
      if (*str1 == str2[i]) find = 1;
    }
    if (!find) len++;
  }
  return len;
}