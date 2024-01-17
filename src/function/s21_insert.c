#include "../s21_string.h"

void s21_insert(char *result, const char *src, const char *str,
                s21_size_t start_index) {
  if (src != s21_NULL && str != s21_NULL && result != s21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_str = s21_strlen(str);
    s21_size_t new_len = len_src + len_str;

    if (start_index > len_src) {
      return;
    }

    s21_size_t i = 0;

    for (i = 0; i < start_index; i++) {
      result[i] = src[i];
    }

    for (s21_size_t j = 0; j < len_str; j++) {
      result[i++] = str[j];
    }

    for (s21_size_t j = start_index; j < len_src; j++) {
      result[i++] = src[j];
    }

    result[new_len] = '\0';
  }
}
