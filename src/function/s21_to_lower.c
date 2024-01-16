#include "../s21_string.h"

void s21_to_lower(const char* str, char* result) {
  if (str == NULL || result == NULL) {
    return;
  }

  s21_size_t i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      result[i] = str[i] + 32;
    } else {
      result[i] = str[i];
    }
    i++;
  }
  result[i] = '\0';
}
