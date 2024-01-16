#include "../s21_string.h"

char *s21_strncat(char *result, const char *str, s21_size_t size) {
  s21_size_t i;

  for (i = 0; result[i] != '\0'; i++)
    ;
  for (s21_size_t j = 0; j < size && str[j] != '\0'; j++, i++) {
    result[i] = str[j];
  }

  result[i] = '\0';

  return result;
}
