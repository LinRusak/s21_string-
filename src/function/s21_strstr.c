#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *h, *n;
  const char *start = s21_NULL;

  for (h = haystack; *h != '\0'; h++) {
    if (*h == *needle) {
      start = h;
      for (n = needle; *n != '\0'; n++) {
        if (*h++ != *n) {
          start = s21_NULL;
          break;
        }
      }
      if (start != s21_NULL) {
        return (char *)start;
      }
    }
  }
  return s21_NULL;
}
