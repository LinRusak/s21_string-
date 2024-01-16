#include "../s21_string.h"

void s21_to_upper(const char* str, char* result) {
  if (str == NULL || result == NULL) {
    return;
  }

  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - 32;
    } else {
      result[i] = str[i];
    }
    i++;
  }
  result[i] = '\0';
}
