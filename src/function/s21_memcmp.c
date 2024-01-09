#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *begin = (const char *)str;
  const char *temp_str = (const char *)str;
  while (((s21_size_t)temp_str - (s21_size_t)begin) < n && *temp_str != c) {
    temp_str++;
  }
  if (((s21_size_t)temp_str - (s21_size_t)begin) >= n) {
    temp_str = s21_NULL;
  }
  return (void *)temp_str;
}