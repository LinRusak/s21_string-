#include "../s21_string.h"

void *trim(const char *src, const char *trim_chars) {
  if (src == NULL || trim_chars == NULL) {
    return NULL;
  }

  size_t src_length = 0;
  while (src[src_length] != '\0') {
    src_length++;
  }

  size_t start = 0;
  size_t end = src_length - 1;

  while (src[start] != '\0') {
    int found = 0;
    for (size_t i = 0; trim_chars[i] != '\0'; i++) {
      if (src[start] == trim_chars[i]) {
        found = 1;
        break;
      }
    }
    if (found == 0) {
      break;
    }
    start++;
  }

  while (end > start) {
    int found = 0;
    for (size_t i = 0; trim_chars[i] != '\0'; i++) {
      if (src[end] == trim_chars[i]) {
        found = 1;
        break;
      }
    }
    if (found == 0) {
      break;
    }
    end--;
  }

  if (end < start) {
    return "";
  }

  return (void *)(src + start);
}