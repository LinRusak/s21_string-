#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index,
                 char *result) {
  s21_size_t i, j;
  s21_size_t src_length = (src != s21_NULL) ? s21_strlen(src) : 0;
  s21_size_t str_length = (str != s21_NULL) ? s21_strlen(str) : 0;
  s21_size_t fin_length = src_length + str_length;

  for (i = 0, j = 0; i < fin_length; i++, j++) {
    if (i < start_index) {
      result[i] = src[i];
    } else if (i < start_index + str_length) {
      result[i] = str[i - start_index];
    } else {
      result[i] = src[j];
    }
    result[fin_length] = '\0';
  }
  return result;
}