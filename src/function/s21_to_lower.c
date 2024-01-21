#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }

  s21_size_t length = s21_strlen(str);
  static char res[4096];

  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      res[i] = str[i] + 32;
    } else {
      res[i] = str[i];
    }
  }
  res[length] = '\0';
  return res;
}
