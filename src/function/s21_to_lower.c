#include "../s21_string.h"

void to_lower(char* str) {
  if (str == NULL) {
    return;
  }

  int i = 0;
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
    i++;
  }
}