#include <check.h>
#include <string.h>

#include "s21_string.h"

// memchr tests
// ----------------------------------------------------------------------------

START_TEST(test_memchr_found) {
  const char str[] = "Hello, School";
  void *result = s21_memchr(str, 'S', sizeof(str) - 1);
  void *expected = memchr(str, 'S', sizeof(str) - 1);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_first_character) {
  const char str[] = "Hello, School";
  void *result = s21_memchr(str, 'H', sizeof(str) - 1);
  void *expected = memchr(str, 'H', sizeof(str) - 1);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_last_character) {
  const char str[] = "Hello, School";
  void *result = s21_memchr(str, 'l', sizeof(str) - 1);
  void *expected = memchr(str, 'l', sizeof(str) - 1);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_character_not_found) {
  const char str[] = "Hello, School";
  void *result = s21_memchr(str, 'a', sizeof(str) - 1);
  void *expected = memchr(str, 'a', sizeof(str) - 1);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_empty_string) {
  const char str[] = "";
  void *result = s21_memchr(str, 'H', sizeof(str) - 1);
  void *expected = memchr(str, 'H', sizeof(str) - 1);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_zero_length) {
  const char str[] = "";
  void *result = s21_memchr(str, 'H', 0);
  void *expected = memchr(str, 'H', 0);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_search_after_n_characters) {
  const char str[] = "Hello, School";
  void *result = s21_memchr(str, 'l', 5);
  void *expected = memchr(str, 'l', 5);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_search_after_last_character) {
  const char str[] = "Hello, School";
  void *result = s21_memchr(str, 'h', sizeof(str) - 5);
  void *expected = memchr(str, 'h', sizeof(str) - 5);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_memchr_search_for_null_terminator) {
  const char str[] = "Hello, School";
  void *result = s21_memchr(str, '\0', sizeof(str) - 1);
  void *expected = memchr(str, '\0', sizeof(str) - 1);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// memcmp tests
// ----------------------------------------------------------------------------

START_TEST(test_memcmp_equal_memory) {
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  int result = s21_memcmp(str1, str2, sizeof(str1));
  int expected = memcmp(str1, str2, sizeof(str1));
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_memcmp_equal_memory1) {
  const char str1[] = "Hellp";
  const char str2[] = "Hello";
  int result = s21_memcmp(str1, str2, 6);
  int expected = memcmp(str1, str2, 6);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_memcmp_dop) {
  const char str1[] = "Hello";
  const char str2[] = "Hello";
  int result = s21_memcmp(str1, str2, 5);
  int expected = memcmp(str1, str2, 5);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_memcmp_equal_prefix) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, School!";
  int result = s21_memcmp(str1, str2, 7);
  int expected = memcmp(str1, str2, 7);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_memcmp_zero_length) {
  const char str1[] = "Hello";
  const char str2[] = "Hola";
  int result = s21_memcmp(str1, str2, 0);
  int expected = memcmp(str1, str2, 0);
  ck_assert_int_eq(result, expected);
}
END_TEST

// memcpy tests
// ----------------------------------------------------------------------------

START_TEST(test_memcpy_normal) {
  const char src[] = "Squizee";
  char dest[8];
  char dest_original[8];
  s21_size_t n = sizeof(src);
  s21_memcpy(dest, src, n);
  ck_assert_str_eq(src, dest);
  memcpy(dest_original, src, n);
  ck_assert_mem_eq(dest, dest_original, n);
}
END_TEST

// memset tests
// ----------------------------------------------------------------------------

START_TEST(test_memset_normal) {
  char str[10] = "123456789";
  char str_original[10] = "123456789";
  int c = 'X';
  s21_size_t n = 6;
  s21_memset(str, c, n);
  for (s21_size_t i = 0; i < n; i++) {
    ck_assert_int_eq(str[i], c);
  }
  for (s21_size_t i = n; i < sizeof(str); i++) {
    ck_assert_int_ne(str[i], 'X');
  }
  memset(str_original, c, n);
  ck_assert_mem_eq(str, str_original, sizeof(str));
}
END_TEST

START_TEST(test_memset_zero_length) {
  char str[10] = "123456789";
  char str_original[10] = "123456789";
  int c = 'X';
  s21_size_t n = 0;
  s21_memset(str, c, n);
  for (s21_size_t i = 0; i < n; i++) {
    ck_assert_int_eq(str[i], c);
  }
  for (s21_size_t i = n; i < sizeof(str); i++) {
    ck_assert_int_ne(str[i], 'X');
  }
  memset(str_original, c, n);
  ck_assert_mem_eq(str, str_original, sizeof(str));
}
END_TEST

START_TEST(test_memset_char_zero) {
  char str[10] = "123456789";
  char str_original[10] = "123456789";
  int c = 0;
  s21_size_t n = 5;
  s21_memset(str, c, n);
  for (s21_size_t i = 0; i < n; i++) {
    ck_assert_int_eq(str[i], c);
  }
  for (s21_size_t i = n; i < sizeof(str); i++) {
    ck_assert_int_ne(str[i], 'X');
  }
  memset(str_original, c, n);
  ck_assert_mem_eq(str, str_original, sizeof(str));
}
END_TEST

// strncat tests
// ----------------------------------------------------------------------------

START_TEST(test_strncat_normal) {
  char dest[20] = "Help me, ";
  char dest_original[20] = "Help me, ";
  const char src[10] = "Please!";
  s21_size_t n = 4;
  char *result = s21_strncat(dest, src, n);
  char *expected = strncat(dest_original, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strncat_append_to_empty_string) {
  char dest[20] = "";
  char dest_original[20] = "";
  const char src[10] = "Hello, ";
  s21_size_t n = 6;
  char *result = s21_strncat(dest, src, n);
  char *expected = strncat(dest_original, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strncat_append_zero_characters) {
  char dest[20] = "Help me, ";
  char dest_original[20] = "Help me, ";
  const char src[10] = "Please!";
  s21_size_t n = 0;
  char *result = s21_strncat(dest, src, n);
  char *expected = strncat(dest_original, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strncat_append_past_dest_size) {
  char dest[20] = "Help";
  char dest_original[20] = "Help";
  const char src[13] = " me, please!";
  s21_size_t n = strlen(src);
  char *result = s21_strncat(dest, src, n);
  char *expected = strncat(dest_original, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strncat_overflow_line) {
  char dest[20] = "Help";
  char dest_original[20] = "Help";
  const char src[13] = " me, please!";
  s21_size_t n = strlen(src) + 5;
  char *result = s21_strncat(dest, src, n);
  char *expected = strncat(dest_original, src, n);
  ck_assert_str_eq(result, expected);
}
END_TEST

// strchr tests
// ----------------------------------------------------------------------------

START_TEST(test_strchr_normal) {
  const char str[] = "elder";
  int c = 'e';
  char *result = s21_strchr(str, c);
  char *expected = strchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strchr_not_found) {
  const char str[] = "Hello, World!";
  char *result = s21_strchr(str, 'X');
  char *expected = strchr(str, 'X');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// strncmp tests
// ----------------------------------------------------------------------------

START_TEST(test_strncmp_normal) {
  const char str1[] = "hell";
  const char str2[] = "hell";
  s21_size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strncmp_much) {
  const char *str1 = "hell";
  const char *str2 = "hell";
  s21_size_t n = 20;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_s21_strncmp_normal) {
  const char str1[] = "hell";
  const char str2[] = "hell";
  s21_size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strncmp_different_strings) {
  const char str1[] = "Hellp";
  const char str2[] = "Hello";
  s21_size_t n = 6;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strncmp_n_zero) {
  const char str1[] = "Hello";
  const char str2[] = "World";
  s21_size_t n = 0;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strncmp_second_condition) {
  const char str1[] = "hello";
  const char str2[] = "hello world";
  s21_size_t n = 5;
  int result = s21_strncmp(str1, str2, n);
  int expected = strncmp(str1, str2, n);
  ck_assert_int_eq(result, expected);
}
END_TEST

// strncpy tests
// ----------------------------------------------------------------------------

START_TEST(test_strncpy_normal) {
  char dest[10];
  const char src[] = "Hello";
  char *result = s21_strncpy(dest, src, 5);
  char *expected = strncpy(dest, src, 5);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strncpy_long_n) {
  char dest[10];
  const char src[] = "Hello";
  char *result = s21_strncpy(dest, src, 6);
  char *expected = strncpy(dest, src, 6);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strncpy_empty_src) {
  char dest[10] = "Hello";
  char *result = s21_strncpy(dest, "", 3);
  char *expected = strncpy(dest, "", 3);
  ck_assert_ptr_eq(result, expected);
  ck_assert_str_eq(result, expected);
  ck_assert(result == dest);
  ck_assert(dest[0] == '\0');
}
END_TEST

// strcspn tests
// ----------------------------------------------------------------------------

START_TEST(test_strcspn_normal) {
  const char str1[] = "this text for test function";
  const char str2[] = "this text for test function";
  s21_size_t result = s21_strcspn(str1, "ieou");
  s21_size_t expected = strcspn(str2, "ieou");
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strcspn_empty) {
  const char str1[] = "";
  const char str2[] = "";
  s21_size_t result = s21_strcspn(str1, "ieou");
  s21_size_t expected = strcspn(str2, "ieou");
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strcspn_no_match) {
  const char str1[] = "this text for test function";
  const char str2[] = "this text for test function";
  s21_size_t result = s21_strcspn(str1, "yz");
  s21_size_t expected = strcspn(str2, "yz");
  ck_assert_int_eq(result, expected);
}
END_TEST

// strlen tests
// ----------------------------------------------------------------------------

START_TEST(test_strlen_normal_string) {
  const char str[] = "Hello, School";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_strlen_empty_string) {
  const char str[] = "";
  s21_size_t result = s21_strlen(str);
  s21_size_t expected = strlen(str);
  ck_assert_int_eq(result, expected);
}
END_TEST

// strpbrk tests
// ----------------------------------------------------------------------------

START_TEST(test_strpbrk_normal) {
  const char str1[] = "this text for test function";
  const char str2[] = "fe";
  const char *result = s21_strpbrk(str1, str2);
  const char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strpbrk_str1_empty) {
  const char str1[] = "";
  const char str2[] = "fe";
  const char *result = s21_strpbrk(str1, str2);
  const char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strpbrk_str2_empty) {
  const char str1[] = "this text for test function";
  const char str2[] = "";
  const char *result = s21_strpbrk(str1, str2);
  const char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strpbrk_empty) {
  const char str1[] = "";
  const char str2[] = "";
  const char *result = s21_strpbrk(str1, str2);
  const char *expected = strpbrk(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// strerror tests
// ----------------------------------------------------------------------------

// START_TEST(test_strerror_normal) {
//   int i = -20;
//   char *result = s21_strerror(i);
//   char *expected = strerror(i);
//   ck_assert_str_eq(result, expected);
// }
// END_TEST

// START_TEST(test_strerror_normal2) {
//   int i = 0;
//   char *result = s21_strerror(i);
//   char *expected = strerror(i);
//   ck_assert_str_eq(result, expected);
// }
// END_TEST

// START_TEST(test_strerror_normal3) {
//   int i = 140;
//   char *result = s21_strerror(i);
//   char *expected = strerror(i);
//   ck_assert_str_eq(result, expected);
// }
// END_TEST

// strrchr tests
// ----------------------------------------------------------------------------

START_TEST(test_strrchr_normal) {
  const char str[] = "elder";
  int c = 'e';
  char *result = s21_strrchr(str, c);
  char *expected = strrchr(str, c);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strrchr_not_found) {
  const char str[] = "Hello, World!";
  char *result = s21_strrchr(str, 'X');
  char *expected = strrchr(str, 'X');
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// strstr tests
// ----------------------------------------------------------------------------

START_TEST(test_strstr_normal) {
  char str1[] = "Hello world! My world? Your world... World, world";
  char str2[] = "world";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_empty) {
  char str1[] = "";
  char str2[] = "";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_nefull) {
  char str1[] = "Hello worl";
  char str2[] = "world";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_strstr_while_null) {
  char str1[] = "Hello world! My world? Your world... World, world";
  char str2[] = "summer";
  char *result = s21_strstr(str1, str2);
  char *expected = strstr(str1, str2);
  ck_assert_mem_eq(result, expected, 0);
}
END_TEST

// strtok tests
// ----------------------------------------------------------------------------

START_TEST(test_strtok_normal) {
  char str1[] = "Hello world! It's a good day!?";
  char str2[] = "Hello world! It's a good day!?";
  const char str3[] = " !?";
  char *result = s21_strtok(str1, str3);
  char *expected = strtok(str2, str3);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strtok_second_call) {
  char str1[] = "Hello world! It's me!";
  char str2[] = "Hello world! It's me!";
  const char str3[] = " !?";
  s21_strtok(str1, str3);
  char *result = s21_strtok(s21_NULL, str3);
  strtok(str2, str3);
  char *expected = strtok(s21_NULL, str3);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strtok_while_null) {
  char str1[] = "Hello world! This project is foolish shit??";
  char str2[] = "Hello world! This project is foolish shit??";
  const char str3[] = " !?";
  char *result = s21_strtok(str1, str3);
  while (result != NULL) {
    result = s21_strtok(s21_NULL, str3);
  }
  char *expected = strtok(str2, str3);
  while (expected != NULL) {
    expected = strtok(s21_NULL, str3);
  }
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_sprintf_specidier_d_0) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"str %% %+d", " %d",   "%-10d", "%-25d", "%0d",
                    "%020d",      "%25d",  "%+25d", "%.1d",  "%.5d",
                    "%.8d",       "%+.4d", "%4.8d", "%015d", "%025.4d"};
  int number[] = {-87654321, -87654321, -7654321, -543210, -43210,  -3210,
                  -210,      -11,       -4,       0,       6,       45,
                  213,       7895,      98522,    789878,  12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %d\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_d_0\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_d_1) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%*d",   " % *d", "%-*d",   "%+*d", "%*.1d",
                    "%*.5d", "%*.8d", "%+*.4d", "%*.8d"};
  int width[100];
  int number[] = {-87654321, -87654321, -7654321, -543210, -43210,  -3210,
                  -210,      -11,       -4,       0,       6,       45,
                  213,       7895,      98522,    789878,  12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < 100; i++) width[i] = i;
  for (int i = 0; i < count_1; i++) {
    for (int k = 0; k < 100; k++) {
      for (int j = 0; j < count_2; j++) {
        int result = sprintf(str_1, format[i], width[k], number[j]);
        int expected = s21_sprintf(str_2, format[i], width[k], number[j]);
        int condition = strcmp(str_1, str_2);
        if (condition != 0) {
          FAIL++;
          printf("\033[43m%s: %d, %d\033[0m\n", format[i], width[k], number[j]);
          printf("str_1: %s\n", str_1);
          printf("\033[41mstr_2: %s\033[0m\n", str_2);
          if ((result - expected) != 0)
            printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                   result - expected);
          else
            printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
        } else {
          SUCCESS++;
        }
        ck_assert_int_eq(condition, 0);
        ck_assert_int_eq(result, expected);
        memset(str_1, 0, sizeof(str_1));
        memset(str_2, 0, sizeof(str_2));
      }
    }
  }
  // printf("\ntest_sprintf_specidier_d_1\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_d_2) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {
      "%.*d", " % .*d", "%-25.*d", "%+5.*d", "%2.*d", "%47.*d",
  };
  int accuracy[15];
  int number[] = {-87654321, -87654321, -7654321, -543210, -43210,  -3210,
                  -210,      -11,       -4,       0,       6,       45,
                  213,       7895,      98522,    789878,  12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < 9; i++) accuracy[i] = i;
  for (int i = 0; i < count_1; i++) {
    for (int k = 0; k < 9; k++) {
      for (int j = 0; j < count_2; j++) {
        int result = sprintf(str_1, format[i], accuracy[k], number[j]);
        int expected = s21_sprintf(str_2, format[i], accuracy[k], number[j]);
        int condition = strcmp(str_1, str_2);
        if (condition != 0) {
          FAIL++;
          printf("\033[43m%s: %d\033[0m\n", format[i], number[j]);
          printf("str_1: %s\n", str_1);
          printf("\033[41mstr_2: %s\033[0m\n", str_2);
          if ((result - expected) != 0)
            printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                   result - expected);
          else
            printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
        } else {
          SUCCESS++;
        }
        ck_assert_int_eq(condition, 0);
        ck_assert_int_eq(result, expected);
        memset(str_1, 0, sizeof(str_1));
        memset(str_2, 0, sizeof(str_2));
      }
    }
  }
  // printf("\ntest_sprintf_specidier_d_2\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_ld_0) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+ld",   " %ld",   "%-10ld", "%-25ld", "%0ld",
                    "%020ld", "%25ld",  "%+25ld", "%.1ld",  "%.5ld",
                    "%.8ld",  "%+.4ld", "%4.8ld", "%015ld", "%025.4ld"};
  long int number[] = {-1156482378910145678,
                       -4654587654321,
                       -7456654321,
                       -5455210,
                       -43210,
                       -3210,
                       -210,
                       -11,
                       -4,
                       0,
                       6,
                       45,
                       21456873,
                       7895,
                       9854654822,
                       78981234578,
                       126354784645887};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %ld\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_ld_0\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_ld_1) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int width[100];
  char *format[] = {"%*d",   " % *d", "%-*d",   "%+*d", "%*.1d",
                    "%*.5d", "%*.8d", "%+*.4d", "%*.8d"};
  for (int i = 0; i < 100; i++) width[i] = i;
  long int number[] = {-1156482378910145678,
                       -4654587654321,
                       -7456654321,
                       -5455210,
                       -43210,
                       -3210,
                       -210,
                       -11,
                       -4,
                       0,
                       6,
                       45,
                       21456873,
                       7895,
                       9854654822,
                       78981234578,
                       126354784645887};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int k = 0; k < 100; k++) {
      for (int j = 0; j < count_2; j++) {
        int result = sprintf(str_1, format[i], width[k], number[j]);
        int expected = s21_sprintf(str_2, format[i], width[k], number[j]);
        int condition = strcmp(str_1, str_2);
        if (condition != 0) {
          FAIL++;
          printf("\033[43m%s: %d, %ld\033[0m\n", format[i], width[k],
                 number[j]);
          printf("str_1: %s\n", str_1);
          printf("\033[41mstr_2: %s\033[0m\n", str_2);
          if ((result - expected) != 0)
            printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                   result - expected);
          else
            printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
        } else {
          SUCCESS++;
        }
        ck_assert_int_eq(condition, 0);
        ck_assert_int_eq(result, expected);
        memset(str_1, 0, sizeof(str_1));
        memset(str_2, 0, sizeof(str_2));
      }
    }
  }
  // printf("\ntest_sprintf_specidier_ld_1\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_ld_2) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {
      "%.*d", " % .*d", "%-25.*d", "%+5.*d", "%2.*d", "%47.*d",
  };
  int accuracy[15];
  long int number[] = {-1156482378910145678,
                       -4654587654321,
                       -7456654321,
                       -5455210,
                       -43210,
                       -3210,
                       -210,
                       -11,
                       -4,
                       0,
                       6,
                       45,
                       21456873,
                       7895,
                       9854654822,
                       78981234578,
                       126354784645887};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < 9; i++) accuracy[i] = i;
  for (int i = 0; i < count_1; i++) {
    for (int k = 0; k < 9; k++) {
      for (int j = 0; j < count_2; j++) {
        int result = sprintf(str_1, format[i], accuracy[k], number[j]);
        int expected = s21_sprintf(str_2, format[i], accuracy[k], number[j]);
        int condition = strcmp(str_1, str_2);
        if (condition != 0) {
          FAIL++;
          printf("\033[43m%s: %d, %ld\033[0m\n", format[i], accuracy[k],
                 number[j]);
          printf("str_1: %s\n", str_1);
          printf("\033[41mstr_2: %s\033[0m\n", str_2);
          if ((result - expected) != 0)
            printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                   result - expected);
          else
            printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
        } else {
          SUCCESS++;
        }
        ck_assert_int_eq(condition, 0);
        ck_assert_int_eq(result, expected);
        memset(str_1, 0, sizeof(str_1));
        memset(str_2, 0, sizeof(str_2));
      }
    }
  }
  // printf("\ntest_sprintf_specidier_ld_2\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_hd_0) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+hd",   " %hd",   "%-10hd", "%-25hd", "%0hd",
                    "%020hd", "%25hd",  "%+25hd", "%.1hd",  "%.5hd",
                    "%.8hd",  "%+.4hd", "%4.8hd", "%015hd", "%025.4hd"};
  short int number[] = {-8765, -18321, -21, -543, -4210, -310, -210, -11, -4,
                        0,     6,      45,  213,  7895,  9852, 7878, 5478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %hd\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_hd_0\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_hd_1) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%*hd",   " % *hd", "%-*hd",   "%+*hd", "%*.1hd",
                    "%*.5hd", "%*.8hd", "%+*.4hd", "%*.8hd"};
  int width[100];
  short int number[] = {-8765, -18321, -21, -543, -4210, -310, -210, -11, -4,
                        0,     6,      45,  213,  7895,  9852, 7878, 5478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < 100; i++) width[i] = i;
  for (int i = 0; i < count_1; i++) {
    for (int k = 0; k < 100; k++) {
      for (int j = 0; j < count_2; j++) {
        int result = sprintf(str_1, format[i], width[k], number[j]);
        int expected = s21_sprintf(str_2, format[i], width[k], number[j]);
        int condition = strcmp(str_1, str_2);
        if (condition != 0) {
          FAIL++;
          printf("\033[43m%s: %d, %hd\033[0m\n", format[i], width[k],
                 number[j]);
          printf("str_1: %s\n", str_1);
          printf("\033[41mstr_2: %s\033[0m\n", str_2);
          if ((result - expected) != 0)
            printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                   result - expected);
          else
            printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
        } else {
          SUCCESS++;
        }
        ck_assert_int_eq(condition, 0);
        ck_assert_int_eq(result, expected);
        memset(str_1, 0, sizeof(str_1));
        memset(str_2, 0, sizeof(str_2));
      }
    }
  }
  // printf("\ntest_sprintf_specidier_hd_0\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_hd_2) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {
      "%.*hd", " % .*hd", "%-25.*hd", "%+5.*hd", "%2.*hd", "%47.*hd",
  };
  int accuracy[15];
  short int number[] = {-8765, -18321, -21, -543, -4210, -310, -210, -11, -4,
                        0,     6,      45,  213,  7895,  9852, 7878, 5478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < 9; i++) accuracy[i] = i;
  for (int i = 0; i < count_1; i++) {
    for (int k = 0; k < 9; k++) {
      for (int j = 0; j < count_2; j++) {
        int result = sprintf(str_1, format[i], accuracy[k], number[j]);
        int expected = s21_sprintf(str_2, format[i], accuracy[k], number[j]);
        int condition = strcmp(str_1, str_2);
        if (condition != 0) {
          FAIL++;
          printf("\033[43m%s: %d, %hd\033[0m\n", format[i], accuracy[k],
                 number[j]);
          printf("str_1: %s\n", str_1);
          printf("\033[41mstr_2: %s\033[0m\n", str_2);
          if ((result - expected) != 0)
            printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                   result - expected);
          else
            printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
        } else {
          SUCCESS++;
        }
        ck_assert_int_eq(condition, 0);
        ck_assert_int_eq(result, expected);
        memset(str_1, 0, sizeof(str_1));
        memset(str_2, 0, sizeof(str_2));
      }
    }
  }
  // printf("\ntest_sprintf_specidier_hd_2\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_f_0) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+f",   " %f",   "%-10f", "%-25f", "%0f",
                    "%020f", "%25f",  "%+25f", "%.1f",  "%.5f",
                    "%.8f",  "%+.4f", "%4.8f", "%015f", "%025.4f"};
  double number[] = {-87654321.45687845123,
                     -87654321.5594,
                     -7654321.412354,
                     -543210.777778444,
                     -43210.124578,
                     -3210.54687,
                     -210.5,
                     -11.78956,
                     -4.652322,
                     0.0,
                     6.65654,
                     45.45,
                     213.85487,
                     7895.688454,
                     98522.9856555,
                     789878.54684,
                     12635478.45684844};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %f\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_f_0\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_f_1) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {
      "%.*f", " % .*f", "%-25.*f", "%+5.*f", "%2.*f", "%47.*f",
  };
  int accuracy[15];
  double number[] = {-87654321.45687845123,
                     -87654321.5594,
                     -7654321.412354,
                     -543210.777778444,
                     -43210.124578,
                     -3210.54687,
                     -210.51,
                     -11.78956,
                     -4.652322,
                     0.0,
                     6.65654,
                     45.45,
                     213.85487,
                     7895.688454,
                     98522.9856555,
                     789878.54684,
                     12635478.45684844};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < 9; i++) accuracy[i] = i;
  for (int i = 0; i < count_1; i++) {
    for (int k = 0; k < 9; k++) {
      for (int j = 0; j < count_2; j++) {
        int result = sprintf(str_1, format[i], accuracy[k], number[j]);
        int expected = s21_sprintf(str_2, format[i], accuracy[k], number[j]);
        int condition = strcmp(str_1, str_2);
        if (condition != 0) {
          FAIL++;
          printf("\033[43m%s: %d, %f\033[0m\n", format[i], accuracy[k],
                 number[j]);
          printf("str_1: %s\n", str_1);
          printf("\033[41mstr_2: %s\033[0m\n", str_2);
          if ((result - expected) != 0)
            printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                   result - expected);
          else
            printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
        } else {
          SUCCESS++;
        }
        ck_assert_int_eq(condition, 0);
        ck_assert_int_eq(result, expected);
        memset(str_1, 0, sizeof(str_1));
        memset(str_2, 0, sizeof(str_2));
      }
    }
  }
  // printf("\ntest_sprintf_specidier_f_1\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_Lf) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+Lf",   " %Lf",   "%-10Lf", "%-25Lf", "%0Lf",
                    "%020Lf", "%25Lf",  "%+25Lf", "%.1Lf",  "%.5Lf",
                    "%.8Lf",  "%+.4Lf", "%4.8Lf", "%015Lf", "%025.4Lf"};
  long double number[] = {-4564646484848321.45687845123L,
                          -8765464654654321.5594L,
                          -7654321.412354L,
                          -543210.777778444L,
                          -43210.124578L,
                          -3210.54687L,
                          -210.5L,
                          -11.78956L,
                          -4.652322L,
                          6.65654L,
                          45.45L,
                          213.85487L,
                          7895.688454L,
                          98522.9856555L,
                          789878.54684L,
                          12635478.45684844L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %Lf\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_Lf\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_e) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+e",   " %e",   "%-10e", "%-25e", "%0e",
                    "%020e", "%25e",  "%+25e", "%.1e",  "%.5e",
                    "%.8e",  "%+.4e", "%4.8e", "%015e", "%025.4e"};
  double number[] = {-87654321.45687845123,
                     -87654321.5594,
                     -7654321.412354,
                     -543210.777778444,
                     -43210.124578,
                     -3210.54687,
                     -210.5,
                     -11.78956,
                     -4.652322,
                     6.65654,
                     45.45,
                     213.85487,
                     7895.688454,
                     98522.9856555,
                     789878.54684,
                     12635478.45684844,
                     0.0123458};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %f\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_e\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_Le) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+Le",   " %Le",   "%-10Le", "%-25Le", "%0Le",
                    "%020Le", "%25Le",  "%+25Le", "%.1Le",  "%.5Le",
                    "%.8Le",  "%+.4Le", "%4.8Le", "%015Le", "%025.4Le"};
  long double number[] = {-4564646484848321.45687845123L,
                          -8765464654654321.5594L,
                          -7654321.412354L,
                          -543210.777778444L,
                          -43210.124578L,
                          -3210.54687L,
                          -210.5L,
                          -11.78956L,
                          -4.652322L,
                          6.65654L,
                          45.45L,
                          213.85487L,
                          7895.688454L,
                          98522.9856555L,
                          789878.54684L,
                          12635478.45684844L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %Lf\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_Le\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_E) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+E",   " %E",   "%-10E", "%-25E", "%0E",
                    "%020E", "%25E",  "%+25E", "%.1E",  "%.5E",
                    "%.8E",  "%+.4E", "%4.8E", "%015E", "%025.4E"};
  double number[] = {-87654321.45687845123,
                     -87654321.5594,
                     -7654321.412354,
                     -543210.777778444,
                     -43210.124578,
                     -3210.54687,
                     -210.5,
                     -11.78956,
                     -4.652322,
                     6.65654,
                     45.45,
                     213.85487,
                     7895.688454,
                     98522.9856555,
                     789878.54684,
                     12635478.45684844,
                     0.0123458};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %f\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_E\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_LE) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+LE",   " %LE",   "%-10LE", "%-25LE", "%0LE",
                    "%020LE", "%25LE",  "%+25LE", "%.1LE",  "%.5LE",
                    "%.8LE",  "%+.4LE", "%4.8LE", "%015LE", "%025.4LE"};
  long double number[] = {-4564646484848321.45687845123L,
                          -8765464654654321.5594L,
                          -7654321.412354L,
                          -543210.777778444L,
                          -43210.124578L,
                          -3210.54687L,
                          -210.5L,
                          -11.78956L,
                          -4.652322L,
                          6.65654L,
                          45.45L,
                          213.85487L,
                          7895.688454L,
                          98522.9856555L,
                          789878.54684L,
                          12635478.45684844L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %Lf\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_LE\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_g) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+g",  " %g",   "%-10g", "%-25g", "%0g",   "%020g",
                    "%25g", "%+25g", "%.5g",  "%+.4g", "%015g", "%025.4g"};
  double number[] = {-87654321.5594, -7654321.412354, -543210.777778444,
                     -43210.124578,  -3210.54687,     -210.5145,
                     -1145648.78956, -4.652322,       6.65654,
                     45.4545645,     213.85487,       7895.688454,
                     98522.7856555,  789878.54684,    12635478.45684844};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %f\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_g\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_Lg) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+Lg",  " %Lg",   "%-10Lg", "%-25Lg",
                    "%0Lg",  "%020Lg", "%25Lg",  "%+25Lg",
                    "%.5Lg", "%+.4Lg", "%015Lg", "%025.4Lg"};
  long double number[] = {
      -87654321.5594L, -7654321.412354L, -543210.777778444L, -43210.124578L,
      -3210.54687L,    -210.5145L,       -1145648.78956L,    -4.652322L,
      6.65654L,        45.4545645L,      213.85487L,         7895.688454L,
      98522.7856555L,  789878.54684L,    12635478.45684844L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %Lf\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_Lg\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_G) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+G",  " %G",   "%-10G", "%-25G", "%0G",   "%020G",
                    "%25G", "%+25G", "%.5G",  "%+.4G", "%015G", "%025.4G"};
  double number[] = {-87654321.5594, -7654321.412354, -543210.777778444,
                     -43210.124578,  -3210.54687,     -210.5145,
                     -1145648.78956, -4.652322,       6.65654,
                     45.4545645,     213.85487,       7895.688454,
                     98522.7856555,  789878.54684,    12635478.45684844};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %f\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_g\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_LG) {
  char str_1[1000];
  char str_2[1000];
  int FAIL = 0;
  int SUCCESS = 0;
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  char *format[] = {"%+LG",  " %LG",   "%-10LG", "%-25LG",
                    "%0LG",  "%020LG", "%25LG",  "%+25LG",
                    "%.5LG", "%+.4LG", "%015LG", "%025.4LG"};
  long double number[] = {
      -87654321.5594L, -7654321.412354L, -543210.777778444L, -43210.124578L,
      -3210.54687L,    -210.5145L,       -1145648.78956L,    -4.652322L,
      6.65654L,        45.4545645L,      213.85487L,         7895.688454L,
      98522.7856555L,  789878.54684L,    12635478.45684844L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %Lf\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("\ntest_sprintf_specidier_Lg\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_u) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%u",    " %u",  "%-10u", "%-25u", "%0u",
                    "%020u", "%25u", "%27u",  "%.1u",  "%.5u",
                    "%.8u",  "%.4u", "%4.8u", "%015u", "%025.4u"};
  int number[] = {87654321, 87654321, 7654321, 543210,  43210, 3210,
                  210,      11,       4,       6,       45,    213,
                  7895,     98522,    789878,  12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %u\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_u\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_lu) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%lu",    " %lu",  "%-10lu", "%-25lu", "%0lu",
                    "%020lu", "%25lu", "%28lu",  "%.1lu",  "%.5lu",
                    "%.8lu",  "%.4lu", "%4.8lu", "%015lu", "%025.4lu"};
  long unsigned int number[] = {87654321154645,
                                87654321,
                                7654321,
                                543210,
                                43210,
                                3210,
                                210,
                                11,
                                4,
                                6,
                                45,
                                213,
                                7895,
                                98522,
                                789878,
                                12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %lu\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_lu\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_hu) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%hu",    " %hu",  "%-10hu", "%-25hu", "%0hu",
                    "%020hu", "%25hu", "%26hu",  "%.1hu",  "%.5hu",
                    "%.8hu",  "%.4hu", "%4.8hu", "%015hu", "%025.4hu"};
  int number[] = {87654321, 87654321, 7654321, 543210,  43210, 3210,
                  210,      11,       4,       6,       45,    213,
                  7895,     98522,    789878,  12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %u\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_u\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_x) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+x",  " %x",   "%-10x", "%-25x", "%x",
                    "%20x", "%25x",  "%+25x", "%.1x",  "%.5x",
                    "%.8x", "%+.4x", "%4.8x", "%15x",  "%25.4x"};
  int number[] = {87654321, 87654321, 7654321, 543210, 43210,   3210,
                  210,      11,       4,       0,      6,       45,
                  213,      7895,     98522,   789878, 12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %d\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_x\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_lx) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+lx",  " %lx",   "%-10lx", "%-25lx", "%lx",
                    "%20lx", "%25lx",  "%+25lx", "%.1lx",  "%.5lx",
                    "%.8lx", "%+.4lx", "%4.8lx", "%15lx",  "%25.4lx"};
  long int number[] = {-8765431111121L,
                       87654321L,
                       7654321L,
                       543210L,
                       43210L,
                       3210L,
                       210L,
                       11L,
                       4L,
                       0L,
                       6L,
                       45L,
                       213L,
                       7895L,
                       98522L,
                       789878L,
                       12635478L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %ld\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_lx\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_hx) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+hx",  " %hx",   "%-10hx", "%-25hx", "%hx",
                    "%20hx", "%25hx",  "%+25hx", "%.1hx",  "%.5hx",
                    "%.8hx", "%+.4hx", "%4.8hx", "%15hx",  "%25.4hx"};
  short int number[] = {-8765, -18321, -21, -543, -4210, -310, -210, -11, -4,
                        0,     6,      45,  213,  7895,  9852, 7878, 5478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %hd\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_lx\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_X) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+X",  " %X",   "%-10X", "%-25X", "%X",
                    "%20X", "%25X",  "%+25X", "%.1X",  "%.5X",
                    "%.8X", "%+.4X", "%4.8X", "%15X",  "%25.4X"};
  int number[] = {87654321, 87654321, 7654321, 543210, 43210,   3210,
                  210,      11,       4,       0,      6,       45,
                  213,      7895,     98522,   789878, 12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %d\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_X\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_lX) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+lX",  " %lX",   "%-10lX", "%-25lX", "%lX",
                    "%20lX", "%25lX",  "%+25lX", "%.1lX",  "%.5lX",
                    "%.8lX", "%+.4lX", "%4.8lX", "%15lX",  "%25.4lX"};
  long int number[] = {-8765431111121L,
                       87654321L,
                       7654321L,
                       543210L,
                       43210L,
                       3210L,
                       210L,
                       11L,
                       4L,
                       0L,
                       6L,
                       45L,
                       213L,
                       7895L,
                       98522L,
                       789878L,
                       12635478L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %ld\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_lX\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_hX) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+hX",  " %hX",   "%-10hX", "%-25hX", "%hX",
                    "%20hX", "%25hX",  "%+25hX", "%.1hX",  "%.5hX",
                    "%.8hX", "%+.4hX", "%4.8hX", "%15hX",  "%25.4hX"};
  short int number[] = {-8765, -18321, -21, -543, -4210, -310, -210, -11, -4,
                        0,     6,      45,  213,  7895,  9852, 7878, 5478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %hd\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_hX\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_o) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+o",  " %o",   "%-10o", "%-25o", "%o",
                    "%20o", "%25o",  "%+25o", "%.1o",  "%.5o",
                    "%.8o", "%+.4o", "%4.8o", "%15o",  "%25.4o"};
  int number[] = {87654321, 87654321, 7654321, 543210, 43210,   3210,
                  210,      11,       4,       0,      6,       45,
                  213,      7895,     98522,   789878, 12635478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %d\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_o\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_lo) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+lo",  " %lo",   "%-10lo", "%-25lo", "%lo",
                    "%20lo", "%25lo",  "%+25lo", "%.1lo",  "%.5lo",
                    "%.8lo", "%+.4lo", "%4.8lo", "%15lo",  "%25.4lo"};
  long int number[] = {-8765431111121L,
                       87654321L,
                       7654321L,
                       543210L,
                       43210L,
                       3210L,
                       210L,
                       11L,
                       4L,
                       0L,
                       6L,
                       45L,
                       213L,
                       7895L,
                       98522L,
                       789878L,
                       12635478L};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %ld\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_lo\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_ho) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%+ho",  " %ho",   "%-10ho", "%-25ho", "%ho",
                    "%20ho", "%25ho",  "%+25ho", "%.1ho",  "%.5ho",
                    "%.8ho", "%+.4ho", "%4.8ho", "%15ho",  "%25.4ho"};
  short int number[] = {-8765, -18321, -21, -543, -4210, -310, -210, -11, -4,
                        0,     6,      45,  213,  7895,  9852, 7878, 5478};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(number) / sizeof(number[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], number[j]);
      int expected = s21_sprintf(str_2, format[i], number[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %hd\033[0m\n", format[i], number[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_lx\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_p) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%p", " %10p", "%-15p"};

  int count_1 = sizeof(format) / sizeof(format[0]);
  for (int i = 0; i < count_1; i++) {
    int result = sprintf(str_1, format[i], str_1);
    int expected = s21_sprintf(str_2, format[i], str_1);
    int condition = strcmp(str_1, str_2);
    if (condition != 0) {
      FAIL++;
    } else {
      SUCCESS++;
    }
    ck_assert_int_eq(condition, 0);
    ck_assert_int_eq(result, expected);
    memset(str_1, 0, sizeof(str_1));
    memset(str_2, 0, sizeof(str_2));
  }
  // printf("test_sprintf_specidier_p\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_c) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%4c",   " %c",   "%-10c", "%-25c", "%0c",
                    "%020c", "%25c",  "%+25c", "%.1c",  "%.5c",
                    "%.8c",  "%+.4c", "%4.8c", "%015c", "%025.4c"};
  char symbol[] = {
      'a', 's', 'd', 'e', 'w',
  };
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(symbol) / sizeof(symbol[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], symbol[j]);
      int expected = s21_sprintf(str_2, format[i], symbol[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %c\033[0m\n", format[i], symbol[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }

      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_c\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_sprintf_specidier_s) {
  char str_1[1000];
  char str_2[1000];
  memset(str_1, 0, sizeof(str_1));
  memset(str_2, 0, sizeof(str_2));
  int FAIL = 0;
  int SUCCESS = 0;
  char *format[] = {"%4s",   " %s",   "%-10s",  "%-25s", "%0s",
                    "%020s", "%25s",  "%+25s",  "%.1s",  "%.5s",
                    "%+.4s", "%015s", "%025.4s"};
  char *string[] = {"string", "aboba", "school",
                    "kak je mne nadoel etot proekt"};
  int count_1 = sizeof(format) / sizeof(format[0]);
  int count_2 = sizeof(string) / sizeof(string[0]);
  for (int i = 0; i < count_1; i++) {
    for (int j = 0; j < count_2; j++) {
      int result = sprintf(str_1, format[i], string[j]);
      int expected = s21_sprintf(str_2, format[i], string[j]);
      int condition = strcmp(str_1, str_2);
      if (condition != 0) {
        FAIL++;
        printf("\033[43m%s: %s\033[0m\n", format[i], string[j]);
        printf("str_1: %s\n", str_1);
        printf("\033[41mstr_2: %s\033[0m\n", str_2);
        if ((result - expected) != 0)
          printf("\033[41mDIFF: %d - %d = %d\033[0m\n", result, expected,
                 result - expected);
        else
          printf("DIFF: %d - %d = %d\n", result, expected, result - expected);
      } else {
        SUCCESS++;
      }
      ck_assert_int_eq(condition, 0);
      ck_assert_int_eq(result, expected);
      memset(str_1, 0, sizeof(str_1));
      memset(str_2, 0, sizeof(str_2));
    }
  }
  // printf("test_sprintf_specidier_s\n");
  // printf("FAIL: %d\n", FAIL);
  // printf("SUCCESS: %d\n", SUCCESS);
}
END_TEST

START_TEST(test_to_lower_1) {
  char *str = "HeLlO, SchOOl";
  char expected[] = "hello, school";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str[] = "AbC$^dEfGhIjKlM";
  char expected[] = "abc$^defghijklm";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_lower_3) {
  char *str = NULL;
  char *expected = NULL;
  void *result = s21_to_lower(str);
  ck_assert_ptr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_lower_4) {
  char str[] = "Ra&NdOmStRi*ng";
  char expected[] = "ra&ndomstri*ng";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_lower_5) {
  char str[] = "12*3AbC";
  char expected[] = "12*3abc";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_lower_6) {
  char str[] = "T^eStInG";
  char expected[] = "t^esting";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_lower_7) {
  char str[] = "QwE@rTy123";
  char expected[] = "qwe@rty123";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_lower_8) {
  char str[] = "QWE RTY^&*=-+21";
  char expected[] = "qwe rty^&*=-+21";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

// to_upper tests
// ----------------------------------------------------------------------------

START_TEST(test_to_upper_1) {
  char *str = "hello, world!";
  char expected[] = "HELLO, WORLD!";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_upper_2) {
  char *str = NULL;
  char *expected = NULL;
  void *result = s21_to_upper(str);
  ck_assert_ptr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str[] = "is powerful";
  char expected[] = "IS POWERFUL";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_upper_4) {
  char str[] = "welcome to the future";
  char expected[] = "WELCOME TO THE FUTURE";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_upper_5) {
  char str[] = "char arrays manipulation";
  char expected[] = "CHAR ARRAYS MANIPULATION";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_upper_6) {
  char str[] = "123 numbers 456";
  char expected[] = "123 NUMBERS 456";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_upper_7) {
  char str[] = "!@# special ^&* characters";
  char expected[] = "!@# SPECIAL ^&* CHARACTERS";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_to_upper_8) {
  char str[] = "mixed CaSe LeTtErS";
  char expected[] = "MIXED CASE LETTERS";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

// insert tests
// ----------------------------------------------------------------------------

START_TEST(test_insert_1) {
  const char src[] = "I love my . He is very kind!";
  const char str[] = "School21";
  unsigned long index = 10;
  char expected[] = "I love my School21. He is very kind!";
  char result[100];
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_insert_2) {
  const char src[] = "Aboba!";
  const char str[] = "Hello, ";
  unsigned long index = 0;
  char expected[] = "Hello, Aboba!";
  char result[100];
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_insert_3) {
  const char src[] = "";
  const char str[] = "";
  unsigned long index = 100;
  char *expected = NULL;
  char result[100];
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_insert_4) {
  const char *src = NULL;
  const char str[] = "123";
  unsigned long index = 1;
  char *expected = NULL;
  char result[100];
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_insert_5) {
  const char src[] = "123";
  const char *str = NULL;
  unsigned long index = 1;
  char expected[] = "123";
  char result[100];
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_insert_6) {
  const char src[] = "123";
  const char *str = "";
  unsigned long index = 1;
  char expected[] = "123";
  char result[100];
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_str_eq(result, expected);
}
END_TEST

// insert tests
// ----------------------------------------------------------------------------

START_TEST(test_trim_1) {
  char str[] = "      qwerty Qwerty qwerty      ";
  char trim_ch[] = " ";
  char expected[] = "qwerty Qwerty qwerty";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_2) {
  char str[] = "     Hello, world!     ";
  char trim_ch[] = "";
  char expected[] = "Hello, world!";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_3) {
  char str[] = "  Hello, world!  ";
  char *trim_ch = NULL;
  char expected[] = "Hello, world!";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_4) {
  char *str = NULL;
  char trim_ch[] = " asd";
  char *expected = NULL;
  char *result = s21_trim(str, trim_ch);
  ck_assert_ptr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_5) {
  char str[] = "  Hello, world!  ";
  char trim_ch[] = "123";
  char expected[] = "  Hello, world!  ";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_6) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_7) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_8) {
  char str[] = "qwerty";
  char trim_ch[] = "qwerty";
  char *expected = NULL;
  char *result = s21_trim(str, trim_ch);
  ck_assert_ptr_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_9) {
  char str[] = "\tqwerty\t";
  char trim_ch[] = "";
  char *expected = "qwerty";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_10) {
  char str[] = "\nqwerty\n";
  char trim_ch[] = "";
  char *expected = "qwerty";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_11) {
  char str[] = "  \t\nqwerty \n \t";
  char trim_ch[] = "";
  char *expected = "qwerty";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

START_TEST(test_trim_12) {
  char str[] = "  \t\nqwerty \n \t";
  char *trim_ch = NULL;
  char *expected = "qwerty";
  char *result = s21_trim(str, trim_ch);
  ck_assert_str_eq(result, expected);
  if (result) free(result);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("s21_string");

  TCase *tc_memchr = tcase_create("s21_memchr");
  tcase_add_test(tc_memchr, test_memchr_found);
  tcase_add_test(tc_memchr, test_memchr_first_character);
  tcase_add_test(tc_memchr, test_memchr_last_character);
  tcase_add_test(tc_memchr, test_memchr_character_not_found);
  tcase_add_test(tc_memchr, test_memchr_empty_string);
  tcase_add_test(tc_memchr, test_memchr_zero_length);
  tcase_add_test(tc_memchr, test_memchr_search_after_n_characters);
  tcase_add_test(tc_memchr, test_memchr_search_after_last_character);
  tcase_add_test(tc_memchr, test_memchr_search_for_null_terminator);
  suite_add_tcase(suite, tc_memchr);

  TCase *tc_memcmp = tcase_create("s21_memcmp");
  tcase_add_test(tc_memcmp, test_memcmp_equal_memory);
  tcase_add_test(tc_memcmp, test_memcmp_equal_memory1);
  tcase_add_test(tc_memcmp, test_memcmp_equal_prefix);
  tcase_add_test(tc_memcmp, test_memcmp_dop);
  tcase_add_test(tc_memcmp, test_memcmp_zero_length);
  suite_add_tcase(suite, tc_memcmp);

  TCase *tc_memcpy = tcase_create("s21_memcpy");
  tcase_add_test(tc_memcpy, test_memcpy_normal);
  suite_add_tcase(suite, tc_memcpy);

  TCase *tc_memset = tcase_create("s21_memset");
  tcase_add_test(tc_memset, test_memset_normal);
  tcase_add_test(tc_memset, test_memset_zero_length);
  tcase_add_test(tc_memset, test_memset_char_zero);
  suite_add_tcase(suite, tc_memset);

  TCase *tc_strncat = tcase_create("s21_strncat");
  tcase_add_test(tc_strncat, test_strncat_normal);
  tcase_add_test(tc_strncat, test_strncat_append_to_empty_string);
  tcase_add_test(tc_strncat, test_strncat_append_zero_characters);
  tcase_add_test(tc_strncat, test_strncat_append_past_dest_size);
  tcase_add_test(tc_strncat, test_strncat_overflow_line);
  suite_add_tcase(suite, tc_strncat);

  TCase *tc_strchr = tcase_create("s21_strchr");
  tcase_add_test(tc_strchr, test_strchr_normal);
  tcase_add_test(tc_strchr, test_strchr_not_found);
  suite_add_tcase(suite, tc_strchr);

  TCase *tc_strncmp = tcase_create("s21_strncmp");
  tcase_add_test(tc_strncmp, test_strncmp_normal);
  tcase_add_test(tc_strncmp, test_s21_strncmp_normal);
  tcase_add_test(tc_strncmp, test_strncmp_different_strings);
  tcase_add_test(tc_strncmp, test_strncmp_much);
  tcase_add_test(tc_strncmp, test_strncmp_n_zero);
  tcase_add_test(tc_strncmp, test_strncmp_second_condition);
  suite_add_tcase(suite, tc_strncmp);

  TCase *tc_strncpy = tcase_create("s21_strncpy");
  tcase_add_test(tc_strncpy, test_strncpy_normal);
  tcase_add_test(tc_strncpy, test_strncpy_long_n);
  tcase_add_test(tc_strncpy, test_strncpy_empty_src);
  suite_add_tcase(suite, tc_strncpy);

  TCase *tc_strcspn = tcase_create("s21_strcspn");
  tcase_add_test(tc_strcspn, test_strcspn_normal);
  tcase_add_test(tc_strcspn, test_strcspn_empty);
  tcase_add_test(tc_strcspn, test_strcspn_no_match);
  suite_add_tcase(suite, tc_strcspn);

  TCase *tc_strlen = tcase_create("s21_strlen");
  tcase_add_test(tc_strlen, test_strlen_normal_string);
  tcase_add_test(tc_strlen, test_strlen_empty_string);
  suite_add_tcase(suite, tc_strlen);

  TCase *tc_strpbrk = tcase_create("s21_strpbrk");
  tcase_add_test(tc_strpbrk, test_strpbrk_normal);
  tcase_add_test(tc_strpbrk, test_strpbrk_str1_empty);
  tcase_add_test(tc_strpbrk, test_strpbrk_str2_empty);
  tcase_add_test(tc_strpbrk, test_strpbrk_empty);
  suite_add_tcase(suite, tc_strpbrk);

  // TCase *tc_strerror = tcase_create("s21_strerror");
  // tcase_add_test(tc_strerror, test_strerror_normal);
  // tcase_add_test(tc_strerror, test_strerror_normal2);
  // tcase_add_test(tc_strerror, test_strerror_normal3);
  // suite_add_tcase(suite, tc_strerror);

  TCase *tc_strrchr = tcase_create("s21_strrchr");
  tcase_add_test(tc_strrchr, test_strrchr_normal);
  tcase_add_test(tc_strrchr, test_strrchr_not_found);
  suite_add_tcase(suite, tc_strrchr);

  TCase *tc_strstr = tcase_create("s21_strstr");
  tcase_add_test(tc_strstr, test_strstr_normal);
  tcase_add_test(tc_strstr, test_strstr_empty);
  tcase_add_test(tc_strstr, test_strstr_nefull);
  tcase_add_test(tc_strstr, test_strstr_while_null);
  suite_add_tcase(suite, tc_strstr);

  TCase *tc_strtok = tcase_create("s21_strtok");
  tcase_add_test(tc_strtok, test_strtok_normal);
  tcase_add_test(tc_strtok, test_strtok_second_call);
  tcase_add_test(tc_strtok, test_strtok_while_null);
  suite_add_tcase(suite, tc_strtok);

  TCase *tc_sprintf = tcase_create("s21_sprintf");
  tcase_add_test(tc_sprintf, test_sprintf_specidier_d_0);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_d_1);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_d_2);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_ld_0);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_ld_1);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_ld_2);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd_0);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd_1);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd_2);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_f_0);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_f_1);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_Lf);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_e);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_Le);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_E);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_LE);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_g);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_Lg);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_G);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_LG);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_u);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_lu);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hu);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_x);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_lx);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hx);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_X);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_lX);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hX);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_o);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_lo);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_ho);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_p);

  tcase_add_test(tc_sprintf, test_sprintf_specidier_c);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_s);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd);
  tcase_add_test(tc_sprintf, test_sprintf_specidier_hd);
  suite_add_tcase(suite, tc_sprintf);

  TCase *tc_lower = tcase_create("s21_to_lower");
  tcase_add_test(tc_lower, test_to_lower_1);
  tcase_add_test(tc_lower, test_to_lower_2);
  tcase_add_test(tc_lower, test_to_lower_3);
  tcase_add_test(tc_lower, test_to_lower_4);
  tcase_add_test(tc_lower, test_to_lower_5);
  tcase_add_test(tc_lower, test_to_lower_6);
  tcase_add_test(tc_lower, test_to_lower_7);
  tcase_add_test(tc_lower, test_to_lower_8);
  suite_add_tcase(suite, tc_lower);

  TCase *tc_upper = tcase_create("s21_to_upper");
  tcase_add_test(tc_upper, test_to_upper_1);
  tcase_add_test(tc_upper, test_to_upper_2);
  tcase_add_test(tc_upper, test_to_upper_3);
  tcase_add_test(tc_upper, test_to_upper_4);
  tcase_add_test(tc_upper, test_to_upper_5);
  tcase_add_test(tc_upper, test_to_upper_6);
  tcase_add_test(tc_upper, test_to_upper_7);
  tcase_add_test(tc_upper, test_to_upper_8);
  suite_add_tcase(suite, tc_upper);

  TCase *tc_insert = tcase_create("s21_insert");
  tcase_add_test(tc_insert, test_insert_1);
  tcase_add_test(tc_insert, test_insert_2);
  tcase_add_test(tc_insert, test_insert_3);
  tcase_add_test(tc_insert, test_insert_4);
  tcase_add_test(tc_insert, test_insert_5);
  tcase_add_test(tc_insert, test_insert_6);
  suite_add_tcase(suite, tc_insert);

  TCase *tc_trim = tcase_create("s21_trim");
  tcase_add_test(tc_trim, test_trim_1);
  tcase_add_test(tc_trim, test_trim_2);
  tcase_add_test(tc_trim, test_trim_3);
  tcase_add_test(tc_trim, test_trim_4);
  tcase_add_test(tc_trim, test_trim_5);
  tcase_add_test(tc_trim, test_trim_6);
  tcase_add_test(tc_trim, test_trim_7);
  tcase_add_test(tc_trim, test_trim_8);
  tcase_add_test(tc_trim, test_trim_9);
  tcase_add_test(tc_trim, test_trim_10);
  tcase_add_test(tc_trim, test_trim_11);
  tcase_add_test(tc_trim, test_trim_12);
  suite_add_tcase(suite, tc_trim);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  // srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  if (failed_count != 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}