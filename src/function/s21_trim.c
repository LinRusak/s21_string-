#include "../s21_string.h"

char *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t src_length = s21_strlen(src);
  s21_size_t start = 0;
  s21_size_t end = src_length - 1;

  while (start <= end && (trim_chars == s21_NULL ||
                          s21_strchr(trim_chars, src[start]) != s21_NULL)) {
    start++;
  }

  while (end >= start && (trim_chars == s21_NULL ||
                          s21_strchr(trim_chars, src[end]) != s21_NULL)) {
    end--;
  }

  if (start > end) {
    static char empty[] = "";
    return empty;
  }

  static char result[4096];
  s21_size_t new_length = end - start + 1;
  for (s21_size_t i = 0; i < new_length; i++) {
    result[i] = src[start + i];
  }
  result[new_length] = '\0';

  return result;
}
