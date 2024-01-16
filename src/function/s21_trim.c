#include "../s21_string.h"

char *s21_trim(char *str, const char *trim_chars) {
  if (str == NULL || trim_chars == NULL) {
    return NULL;
  }

  s21_size_t str_length = 0;
  while (str[str_length] != '\0') {
    str_length++;
  }

  s21_size_t start = 0;
  s21_size_t end = str_length - 1;

  while (start <= end && s21_strchr(trim_chars, str[start]) != NULL) {
    start++;
  }

  while (end >= start && s21_strchr(trim_chars, str[end]) != NULL) {
    end--;
  }

  if (start > end) {
    str[0] = '\0';
    return str;
  }

  s21_size_t new_length = end - start + 1;
  for (s21_size_t i = 0; i < new_length; i++) {
    str[i] = str[start + i];
  }
  str[new_length] = '\0';  // Гарантирует корректное завершение строки

  return str;
}
