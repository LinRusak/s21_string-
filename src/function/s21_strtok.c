#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *first_str = s21_NULL;
  static char *end_str = s21_NULL;
  static int len = 0;
  static int count = 0;

  if (str != s21_NULL) {
    len = s21_strlen(str);
    first_str = str;
    end_str = str + s21_strlen(str);
  }
  if (str == s21_NULL) {
    while (*first_str != '\0') {
      first_str++;
      count++;
    }
    while (*first_str == '\0' && count != len) {
      first_str++;
      count++;
    }
  } else {
    s21_size_t len_str = s21_strlen(str);
    s21_size_t len_delim = s21_strlen(delim);
    for (s21_size_t i = 0; i < len_str; i++) {
      for (s21_size_t j = 0; j < len_delim; j++) {
        if (first_str[i] == delim[j]) first_str[i] = '\0';
      }
    }
  }
  if (first_str >= end_str) first_str = s21_NULL;

  return first_str;
}
