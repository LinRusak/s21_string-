#ifndef S_21_STRING_H_
#define S_21_STRING_H_
#include <stdio.h>
#include <stdlib.h>
#define s21_NULL ((void *)0)
typedef unsigned long s21_size_t;

char *s21_strncpy(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *s, const char *accept);
char *s21_strtok(char *str, const char *delim);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_reverse(char *str);
void *s21_to_upper(const char *str);
char *s21_strncat(char *str_main, const char *str_aux, s21_size_t accuracy);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index, char *result);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // S_21_STRING_H_