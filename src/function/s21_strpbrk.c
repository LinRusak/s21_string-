#include <stdbool.h>

#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  bool trigger = false;
  char *str1_temp = (char *)str1;
  while (*str1 != '\0') {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (*str1_temp == str2[j]) {
        trigger = true;
      }
    }
    str1++;
    if (!trigger) str1_temp++;
  }
  if (trigger == false) str1_temp = s21_NULL;
  return str1_temp;
}
