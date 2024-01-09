#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  s21_size_t len_str1 = s21_strlen(str1);
  s21_size_t len_str2 = s21_strlen(str2);
  if (len_str1 == len_str2 && n > len_str2) n = len_str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (*str1 != *str2) {
      result = *str1 - *str2;
      i = n;
    }
    str1++;
    str2++;
  }
  return result;
}
