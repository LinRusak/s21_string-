#include "../s21_string.h"

const char *trim(const char *str, const char *trim_chars) {
  if (str == NULL || trim_chars == NULL) {
    return NULL;
  }

  s21_size_t str_length = 0;
  while (str[str_length] != '\0') {
    str_length++;
  }

  s21_size_t start = 0;
  s21_size_t end = str_length - 1;

  while (str[start] != '\0') {
    int found = 0;
    for (s21_size_t i = 0; trim_chars[i] != '\0'; i++) {
      if (str[start] == trim_chars[i]) {
        found = 1;
        break;
      }
    }
    if (found == 0) {
      break;
    }
    start++;
  }

  while (end > start) {
    int found = 0;
    for (s21_size_t i = 0; trim_chars[i] != '\0'; i++) {
      if (str[end] == trim_chars[i]) {
        found = 1;
        break;
      }
    }
    if (found == 0) {
      break;
    }
    end--;
  }

  if (end < start) {
    return str + start;
  }

  return str + start;
}