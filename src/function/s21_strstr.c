#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *begin_haystack = (char *)haystack;
  s21_size_t len = s21_strlen(haystack);
  s21_size_t lenNeedle = s21_strlen(needle);
  for (s21_size_t j = 0; j < len; j++) {
    while (*haystack != '\0' && *haystack != *needle) {
      haystack++;
    }
    if (*haystack != '\0') {
      s21_size_t matchCount = 0;
      for (s21_size_t i = 0; i < lenNeedle; i++) {
        if (haystack[i] == needle[i]) matchCount++;
      }
      if (lenNeedle != matchCount) haystack += matchCount;
    }
  }
  if (!lenNeedle) haystack = begin_haystack;
  if (*haystack == '\0' && len > 0) haystack = s21_NULL;
  if (*begin_haystack == '\0' && *needle != '\0') haystack = s21_NULL;
  return (char *)haystack;
}
