#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 0;
  char *buffer = s21_NULL;
  for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
    for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
      if (str2[j] == str1[i] && flag == 0) {
        buffer = (char *)&str1[i];
        flag = 1;
      }
    }
  }
  return buffer;
}
