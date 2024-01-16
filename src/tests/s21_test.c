#include <check.h>
#include <string.h>

#include "../s21_string.h"

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

START_TEST(test_strerror_normal) {
  int i = -20;
  const char *result = s21_strerror(i);
  char *expected = strerror(i);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strerror_normal2) {
  int i = 0;
  char *result = s21_strerror(i);
  char *expected = strerror(i);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_strerror_normal3) {
  int i = 140;
  char *result = s21_strerror(i);
  char *expected = strerror(i);
  ck_assert_str_eq(result, expected);
}
END_TEST

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

START_TEST(s21_sprintf_f_test) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%.f", b);
  int res_1_orig = sprintf(str_orig, "%.f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  double b_2 = 0.00000002345;
  int res_2 = s21_sprintf(str, "%+-10.3f", b_2);
  int res_2_orig = sprintf(str_orig, "%+-10.3f", b_2);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  long double b_3 = -23.087654;
  int res_3 = s21_sprintf(str, "%20.10Lf", -23.087654);
  int res_3_orig = sprintf(str_orig, "%20.10Lf", b_3);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);
  double b_4 = 0;
  int res_4 = s21_sprintf(str, "%0+.15F", b_4);
  int res_4_orig = sprintf(str_orig, "%0+.15F", b_4);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  long double b_5 = 0;
  int res_5 = s21_sprintf(str, "%#.0Lf", b_5);
  int res_5_orig = sprintf(str_orig, "%#.0Lf", b_5);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  double b_6 = 1.0 / 0.0;

  int res_6 = s21_sprintf(str, "%#10.0f", b_6);
  int res_6_orig = sprintf(str_orig, "%#10.0f", b_6);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  double b_7 = 1234523459.123456789;
  int res_7 = s21_sprintf(str, "%.5f", b_7);
  int res_7_orig = sprintf(str_orig, "%.5f", b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_8 = 1;
  int res_8 = s21_sprintf(str, "%f", b_8);
  int res_8_orig = sprintf(str_orig, "%f", b_8);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  double b_9 = 0.00345;
  int res_9 = s21_sprintf(str, "%f", b_9);
  int res_9_orig = sprintf(str_orig, "%f", b_9);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  double b_10 = 0.00345;
  int res_10 = s21_sprintf(str, "%f", b_10);
  int res_10_orig = sprintf(str_orig, "%f", b_10);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  double b_11 = 1234567.0034598765432987654321;
  int res_11 = s21_sprintf(str, "%.20f", b_11);
  int res_11_orig = sprintf(str_orig, "%.20f", b_11);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_g_test) {
  char str[80];
  char str_orig[80];

  double b_1 = -22.25600;
  int res_1 = s21_sprintf(str, "%+-10.4G", b_1);
  int res_1_orig = sprintf(str_orig, "%+-10.4G", b_1);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  // double b_2 = 0.000000000001;
  // int res_2 = s21_sprintf(str, "%#G", b_2);
  // int res_2_orig = sprintf(str_orig, "%#G", b_2);

  // ck_assert_int_eq(res_2, res_2_orig);
  // ck_assert_str_eq(str, str_orig);

  int a = -10;
  long double b_3 = 12345.2345678;
  int res_3 = s21_sprintf(str, "%+30.*Lg", a, b_3);
  int res_3_orig = sprintf(str_orig, "%+30.*Lg", a, b_3);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  double b_5 = -0.000000654;
  int res_5 = s21_sprintf(str, "%+-25g", b_5);
  int res_5_orig = sprintf(str_orig, "%+-25g", b_5);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  double b_6 = 320.0;
  int res_6 = s21_sprintf(str, "%+-25g%g", b_5, b_6);
  int res_6_orig = sprintf(str_orig, "%+-25g%g", b_5, b_6);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  double b_7 = -120.0001;
  int res_7 = s21_sprintf(str, "aaa%# 20.3G bbb %+.5f ccc", b_7, b_7);
  int res_7_orig = sprintf(str_orig, "aaa%# 20.3G bbb %+.5f ccc", b_7, b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_10 = 5.0, b_8 = 0.0000000012345, b_9 = 1.0;
  int res_8 = s21_sprintf(str, "%-20G %010.5g %+Fhello", b_8, b_9, b_10);
  int res_8_orig = sprintf(str_orig, "%-20G %010.5g %+Fhello", b_8, b_9, b_10);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  double b_11 = 0.001;
  int res_11 = s21_sprintf(str, "%0.g", b_11);
  int res_11_orig = sprintf(str_orig, "%0.g", b_11);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  double b_12 = 0.00000000001;
  int res_12 = s21_sprintf(str, "%.10g", b_12);
  int res_12_orig = sprintf(str_orig, "%.10g", b_12);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_prc_test) {
  char str[80];
  char str_orig[80];

  int res_1 = s21_sprintf(str, "%%");
  int res_1_orig = sprintf(str_orig, "%%");
  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10%");

  ck_assert_int_eq(res_2, 10);
  ck_assert_str_eq(str, "         %");

  int a_prc = 14;
  int res_3 = s21_sprintf(str, "hhhh%0*%", a_prc);

  ck_assert_int_eq(res_3, 18);
  ck_assert_str_eq(str, "hhhh0000000000000%");

  int width_prc = 30;
  int res_4 = s21_sprintf(str, "%-*%12345", width_prc);

  ck_assert_int_eq(res_4, 35);
  ck_assert_str_eq(str, "%                             12345");

  int res_5 = s21_sprintf(str, "abc%%defg");
  int res_5_orig = sprintf(str_orig, "abc%%defg");

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_test) {
  char str[80];
  char str_origin[80];
  const char *format_str1 = "Hello";
  char c = 'X';
  char d = 'Y';
  int result1 = s21_sprintf(str, format_str1, c);
  int result_origin1 = sprintf(str_origin, format_str1, c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "Hello, %c %c";
  int result2 = s21_sprintf(str, format_str2, c, d);
  int result_origin2 = sprintf(str_origin, format_str2, c, d);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  char *s1 = "world!";
  char *s2 = "Hello world!";
  const char *format_str3 = "Hello, %10s %10.15s";
  int result3 = s21_sprintf(str, format_str3, s1, s2);
  int result_origin3 = sprintf(str_origin, format_str3, s1, s2);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_e_test) {
  char str[80];
  char str_origin[80];
  const char *format_str1 = "% 10.12LE yo";
  long double mantissa1 = 0.0000003044058697058435;
  int result1 = s21_sprintf(str, format_str1, mantissa1);
  int result_origin1 = sprintf(str_origin, format_str1, mantissa1);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  const char *format_str2 = "%-20.7e yo";
  double mantissa2 = -4044050;
  int result2 = s21_sprintf(str, format_str2, mantissa2);
  int result_origin2 = sprintf(str_origin, format_str2, mantissa2);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  const char *format_str3 = "%-.5E yo";
  double mantissa3 = 0.00;
  int result3 = s21_sprintf(str, format_str3, mantissa3);
  int result_origin3 = sprintf(str_origin, format_str3, mantissa3);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);

  const char *format_str4 = "Hello %+020.15E %LE yo";
  double mantissa4 = 1.004554367;
  long double mantissa5 = -432432455454;
  int result4 = s21_sprintf(str, format_str4, mantissa4, mantissa5);
  int result_origin4 = sprintf(str_origin, format_str4, mantissa4, mantissa5);
  ck_assert_int_eq(result4, result_origin4);
  ck_assert_str_eq(str, str_origin);

  const char *format_str5 = "This is infinite: %-20.5e and this is nan: %20e";
  double infinite = 1.0 / 0.0;
  double not_a_number = infinite * 0.0;
  int result5 = s21_sprintf(str, format_str5, infinite, not_a_number);
  int result_origin5 = sprintf(str_origin, format_str5, infinite, not_a_number);
  ck_assert_int_eq(result5, result_origin5);
  ck_assert_str_eq(str, str_origin);

  const char *format_str6 = "% -10.14E yo";
  double mantissa6 = 0.00003044058697058435;
  int result6 = s21_sprintf(str, format_str6, mantissa6);
  int result_origin6 = sprintf(str_origin, format_str6, mantissa6);
  ck_assert_int_eq(result6, result_origin6);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_p_test) {
  char str[80];
  char str_origin[80];
  int a = 10;
  char *format_str1 = "This is the pointer: %p\n";
  int result1 = s21_sprintf(str, format_str1, &a);
  int result_origin1 = sprintf(str_origin, format_str1, &a);

  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(str, str_origin);

  char *pointer = "Test";
  double double_pointer = 84759375969;

  char *format_str2 = "To the left: %-20p!\nTo the right %20p!";

  int result2 = s21_sprintf(str, format_str2, pointer, &double_pointer);
  int result_origin2 =
      sprintf(str_origin, format_str2, pointer, &double_pointer);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_str_eq(str, str_origin);

  int *empty_pointer = NULL;
  char *format_str3 = "This is empty pointer %p\n";
  int result3 = s21_sprintf(str, format_str3, empty_pointer);
  int result_origin3 = sprintf(str_origin, format_str3, empty_pointer);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_str_eq(str, str_origin);
}
END_TEST

START_TEST(s21_sprintf_o_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%o", arr1[0]);
  int res1 = sprintf(str1, "%o", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-12.3lo", (unsigned long)arr1[4]);
  res1 = sprintf(str1, "%-12.3lo", (unsigned long)arr1[4]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%010.5o", arr1[5]);
  ck_assert_str_eq(str, "37777775231");
  ck_assert_int_eq(res, 11);

  res = s21_sprintf(str, "%0#3.7o gterth", arr1[6]);
  ck_assert_str_eq(str, "0022253 gterth");
  ck_assert_int_eq(res, 14);

  res = s21_sprintf(str, "%-.4o gterth", arr1[6]);
  res1 = sprintf(str1, "%-.4o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#.9o gterth", arr1[6]);
  res1 = sprintf(str1, "%-#.9o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %0.o gterth", arr1[6]);
  ck_assert_str_eq(str, "hello 22253 gterth");
  ck_assert_int_eq(res, 18);

  res = s21_sprintf(str, "hello %#o gterth", arr1[6]);
  res1 = sprintf(str1, "hello %#o gterth", arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %*.o gterth", 5, arr1[6]);
  res1 = sprintf(str1, "hello %*.o gterth", 5, arr1[6]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "hello %010.7o gterth", arr1[6]);
  ck_assert_str_eq(str, "hello 0000022253 gterth");
  ck_assert_int_eq(res, 23);

  res = s21_sprintf(str, "%010.7ho", (unsigned short)arr1[6]);
  ck_assert_str_eq(str, "0000022253");
  ck_assert_int_eq(res, 10);
}
END_TEST

START_TEST(s21_sprintf_x_X_test) {
  int arr1[] = {0, -1, 1, 123, 1234, -1383, 9387};
  char str[80];
  char str1[80];
  int res = s21_sprintf(str, "%x", arr1[0]);
  int res1 = sprintf(str1, "%x", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7hx", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%#10.7hx", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3lx", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%-#10.3lx", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%X", arr1[0]);
  res1 = sprintf(str1, "%X", arr1[0]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%#10.7lX", (unsigned long)arr1[3]);
  res1 = sprintf(str1, "%#10.7lX", (unsigned long)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#10.3hX", (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%-#10.3hX", (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  res1 = sprintf(str1, "%-#*.3hX", 10, (unsigned short)arr1[3]);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_c_test) {
  char str[80];
  char str1[80];
  char x = 'c';
  int res = s21_sprintf(str, "%-10c", x);
  int res1 = sprintf(str1, "%-10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%10c", x);
  res1 = sprintf(str1, "%10c", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_s_test) {
  char str[80];
  char str1[80];
  char *x = "blablabla";
  int res = s21_sprintf(str, "%-11.10s", x);
  int res1 = sprintf(str1, "%-11.10s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);

  res = s21_sprintf(str, "%11.8s", x);
  res1 = sprintf(str1, "%11.8s", x);
  ck_assert_uint_eq((unsigned long)*str, (unsigned long)*str1);
  ck_assert_int_eq(res, res1);
}
END_TEST

START_TEST(s21_sprintf_u_test) {
  char str[80];
  char str_orig[80];
  unsigned int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5u", a);
  int res_1_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "%10.5u", a);
  int res_2_orig = sprintf(str_orig, "%10.5u", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5u", a);
  int res_3_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%0u", a);
  int res_4_orig = sprintf(str_orig, "%0u", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%-u", a);
  int res_5_orig = sprintf(str_orig, "%-u", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%u", a);
  int res_6_orig = sprintf(str_orig, "%u", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%5u", a);
  int res_7_orig = sprintf(str_orig, "%5u", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "%05u", a);
  int res_8_orig = sprintf(str_orig, "%05u", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%-5u", a);
  int res_9_orig = sprintf(str_orig, "%-5u", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%.5u", a);
  int res_10_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%.5u", a);
  int res_11_orig = sprintf(str_orig, "%.5u", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%-.5u", a);
  int res_12_orig = sprintf(str_orig, "%-.5u", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "%-10.5u", a);
  int res_13_orig = sprintf(str_orig, "%-10.5u", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%3.5u", a);
  int res_14_orig = sprintf(str_orig, "%3.5u", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%-3.5u", a);
  int res_15_orig = sprintf(str_orig, "%-3.5u", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "%6.2u", a);
  int res_16_orig = sprintf(str_orig, "%6.2u", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%3.2u", a);
  int res_17_orig = sprintf(str_orig, "%3.2u", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%01u", a);
  int res_18_orig = sprintf(str_orig, "%01u", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%hu", (unsigned short)a);
  int res_19_orig = sprintf(str_orig, "%hu", (unsigned short)a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%lu", (unsigned long)a);
  int res_20_orig = sprintf(str_orig, "%lu", (unsigned long)a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test) {
  char str[80];
  char str_orig[80];
  int a = 2345;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%05d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%hd", (unsigned short)a);
  int res_26_orig = sprintf(str_orig, "%hd", (unsigned short)a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%ld", (unsigned long)a);
  int res_27_orig = sprintf(str_orig, "%ld", (unsigned long)a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_2) {
  char str[80];
  char str_orig[80];
  int a = -23454546;

  int res_1 = s21_sprintf(str, "%10.*d", 5, a);
  int res_1_orig = sprintf(str_orig, "%10.*d", 5, a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%0*d", 5, a);
  int res_10_orig = sprintf(str_orig, "%0*d", 5, a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_3) {
  char str[80];
  char str_orig[80];
  int a = 234;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+6.2d", a);
  int res_26_orig = sprintf(str_orig, "%+6.2d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);

  int res_27 = s21_sprintf(str, "%+6.3d", a);
  int res_27_orig = sprintf(str_orig, "%+6.3d", a);

  ck_assert_int_eq(res_27, res_27_orig);
  ck_assert_str_eq(str, str_orig);

  int res_28 = s21_sprintf(str, "%+6.4d", a);
  int res_28_orig = sprintf(str_orig, "%+6.4d", a);

  ck_assert_int_eq(res_28, res_28_orig);
  ck_assert_str_eq(str, str_orig);

  int res_29 = s21_sprintf(str, "%-6.2d", -a);
  int res_29_orig = sprintf(str_orig, "%-6.2d", -a);

  ck_assert_int_eq(res_29, res_29_orig);
  ck_assert_str_eq(str, str_orig);

  int res_30 = s21_sprintf(str, "%+05d", a);
  int res_30_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_30, res_30_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_4) {
  char str[80];
  char str_orig[80];
  int a = -23;

  int res_1 = s21_sprintf(str, "%10.5d", a);
  int res_1_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_5) {
  char str[80];
  char str_orig[80];
  int a = -2344;

  int res_2 = s21_sprintf(str, "% 10.5d", a);
  int res_2_orig = sprintf(str_orig, "% 10.5d", a);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%3.5d", a);
  int res_3_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%d", a);
  int res_4_orig = sprintf(str_orig, "%d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%0d", a);
  int res_5_orig = sprintf(str_orig, "%0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-d", a);
  int res_6_orig = sprintf(str_orig, "%-d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_8 = s21_sprintf(str, "% d", a);
  int res_8_orig = sprintf(str_orig, "% d", a);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%5d", a);
  int res_9_orig = sprintf(str_orig, "%5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_10 = s21_sprintf(str, "%05d", a);
  int res_10_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-5d", a);
  int res_11_orig = sprintf(str_orig, "%-5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_13 = s21_sprintf(str, "% 5d", a);
  int res_13_orig = sprintf(str_orig, "% 5d", a);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%.5d", a);
  int res_14_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%.5d", a);
  int res_15_orig = sprintf(str_orig, "%.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_17 = s21_sprintf(str, "%+.5d", a);
  int res_17_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_17, res_17_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-.5d", a);
  int res_18_orig = sprintf(str_orig, "%-.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_19 = s21_sprintf(str, "%10.5d", a);
  int res_19_orig = sprintf(str_orig, "%10.5d", a);

  ck_assert_int_eq(res_19, res_19_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%3.5d", a);
  int res_22_orig = sprintf(str_orig, "%3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_24 = s21_sprintf(str, "%+3.5d", a);
  int res_24_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_24, res_24_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_6) {
  char str[80];
  char str_orig[80];
  int a = 23;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%+0d", a);
  int res_5_orig = sprintf(str_orig, "%+0d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_6 = s21_sprintf(str, "%-+d", a);
  int res_6_orig = sprintf(str_orig, "%-+d", a);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_11 = s21_sprintf(str, "%-+5d", a);
  int res_11_orig = sprintf(str_orig, "%-+5d", a);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_16 = s21_sprintf(str, "% .5d", a);
  int res_16_orig = sprintf(str_orig, "% .5d", a);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);

  int res_18 = s21_sprintf(str, "%-+.5d", a);
  int res_18_orig = sprintf(str_orig, "%-+.5d", a);

  ck_assert_int_eq(res_18, res_18_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_21 = s21_sprintf(str, "%-+10.5d", a);
  int res_21_orig = sprintf(str_orig, "%-+10.5d", a);

  ck_assert_int_eq(res_21, res_21_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_23 = s21_sprintf(str, "% 3.5d", a);
  int res_23_orig = sprintf(str_orig, "% 3.5d", a);

  ck_assert_int_eq(res_23, res_23_orig);
  ck_assert_str_eq(str, str_orig);

  int res_25 = s21_sprintf(str, "%-+3.5d", a);
  int res_25_orig = sprintf(str_orig, "%-+3.5d", a);

  ck_assert_int_eq(res_25, res_25_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_d_test_0) {
  char str[80];
  char str_orig[80];
  int a = 0;

  int res_1 = s21_sprintf(str, "%+10.5d", a);
  int res_1_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  int res_3 = s21_sprintf(str, "%+3.5d", a);
  int res_3_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  int res_4 = s21_sprintf(str, "%+d", a);
  int res_4_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  int res_5 = s21_sprintf(str, "%05d", a);
  int res_5_orig = sprintf(str_orig, "%05d", a);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  int res_7 = s21_sprintf(str, "%+d", a);
  int res_7_orig = sprintf(str_orig, "%+d", a);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  int res_9 = s21_sprintf(str, "%+5d", a);
  int res_9_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  int res_12 = s21_sprintf(str, "%+5d", a);
  int res_12_orig = sprintf(str_orig, "%+5d", a);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  int res_14 = s21_sprintf(str, "%+.5d", a);
  int res_14_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  int res_15 = s21_sprintf(str, "%+.5d", a);
  int res_15_orig = sprintf(str_orig, "%+.5d", a);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  int res_20 = s21_sprintf(str, "%+10.5d", a);
  int res_20_orig = sprintf(str_orig, "%+10.5d", a);

  ck_assert_int_eq(res_20, res_20_orig);
  ck_assert_str_eq(str, str_orig);

  int res_22 = s21_sprintf(str, "%+3.5d", a);
  int res_22_orig = sprintf(str_orig, "%+3.5d", a);

  ck_assert_int_eq(res_22, res_22_orig);
  ck_assert_str_eq(str, str_orig);

  int res_26 = s21_sprintf(str, "%+05d", a);
  int res_26_orig = sprintf(str_orig, "%+05d", a);

  ck_assert_int_eq(res_26, res_26_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(test_to_lower_1) {
  char str[] = "HeLlO, SchOOl";
  char expected[] = "hello, school";
  char result[sizeof(str)];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_lower_2) {
  char str[] = "AbC$^dEfGhIjKlM";
  char expected[] = "abc$^defghijklm";
  char result[sizeof(str)];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_lower_3) {
  const char *str = NULL;
  const char *expected = NULL;
  char result[6];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_lower_4) {
  char str[] = "Ra&NdOmStRi*ng";
  char expected[] = "ra&ndomstri*ng";
  char result[sizeof(str)];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_lower_5) {
  char str[] = "12*3AbC";
  char expected[] = "12*3abc";
  char result[sizeof(str)];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_lower_6) {
  char str[] = "T^eStInG";
  char expected[] = "t^esting";
  char result[sizeof(str)];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_lower_7) {
  char str[] = "QwE@rTy123";
  char expected[] = "qwe@rty123";
  char result[sizeof(str)];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_lower_8) {
  char str[] = "QWE RTY^&*=-+21";
  char expected[] = "qwe rty^&*=-+21";
  char result[sizeof(str)];
  s21_to_lower(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

// to_upper tests
// ----------------------------------------------------------------------------

START_TEST(test_to_upper_1) {
  const char *str = "hello, world!";
  const char *expected = "HELLO, WORLD!";
  char result[strlen(str) + 1];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_upper_2) {
  const char *str = "hello";
  const char *expected = "HELLO";
  char result[6];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_upper_3) {
  char str[] = "is powerful";
  char expected[] = "IS POWERFUL";
  char result[strlen(str) + 1];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_upper_4) {
  char str[] = "welcome to the future";
  char expected[] = "WELCOME TO THE FUTURE";
  char result[strlen(str) + 1];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_upper_5) {
  char str[] = "char arrays manipulation";
  char expected[] = "CHAR ARRAYS MANIPULATION";
  char result[strlen(str) + 1];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_upper_6) {
  char str[] = "123 numbers 456";
  char expected[] = "123 NUMBERS 456";
  char result[strlen(str) + 1];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_upper_7) {
  char str[] = "!@# special ^&* characters";
  char expected[] = "!@# SPECIAL ^&* CHARACTERS";
  char result[strlen(str) + 1];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_to_upper_8) {
  char str[] = "mixed CaSe LeTtErS";
  char expected[] = "MIXED CASE LETTERS";
  char result[strlen(str) + 1];
  s21_to_upper(str, result);
  ck_assert_str_eq(result, expected);
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
  unsigned long index = 101;
  const char expected[] = "";
  char result[101] = "";
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_str_eq(result, expected);
}
END_TEST

START_TEST(test_insert_4) {
  const char *src = NULL;
  const char str[] = "123";
  unsigned long index = 1;
  const char *expected = NULL;
  char result[100] = "";
  s21_insert(result, src, str, (s21_size_t)index);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_insert_5) {
  const char src[] = "123";
  const char *str = NULL;
  unsigned long index = 1;
  const char expected[] = "123";
  char result[100] = "";
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

// trim tests
// ----------------------------------------------------------------------------

START_TEST(test_trim_1) {
  char str[] = "    qwerty Qwerty qwerty    ";
  const char *trim_chars = "    ";
  const char *expected = "qwerty Qwerty qwerty";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_2) {
  char str[] = "     Hello, world!     ";
  const char *trim_chars = "    ";
  const char *expected = "Hello, world!";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_3) {
  char str[] = "  Hello, world!  ";
  const char *trim_chars = NULL;
  const char *expected = "  Hello, world!  ";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_4) {
  char *str = NULL;
  const char *trim_chars = " asd";
  const char *expected = NULL;
  ck_assert_ptr_eq(s21_trim(str, trim_chars), expected);
}
END_TEST

START_TEST(test_trim_5) {
  char str[] = "  Hello, world!  ";
  const char trim_chars[] = "123";
  const char *expected = "  Hello, world!  ";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_6) {
  char str[] = "+!!++Abo+ba++00";
  char trim_chars[] = "+!!0-";
  char expected[] = "Abo+ba";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_7) {
  char str[] = "&* !!sc21 * **";
  char trim_chars[] = "&!* ";
  char expected[] = "sc21";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_8) {
  char str[] = "qwerty";
  char trim_chars[] = "qwerty";
  char *expected = "";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_9) {
  char str[] = "\tqwerty\t";
  char trim_chars[] = "\t";
  char *expected = "qwerty";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_10) {
  char str[] = "\nqwerty\n";
  char trim_chars[] = "\n";
  char *expected = "qwerty";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_11) {
  char str[] = "  \t\nqwerty \n \t";
  char trim_chars[] = "\t \n";
  char *expected = "qwerty";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
}
END_TEST

START_TEST(test_trim_12) {
  char str[] = "  \t\nqwerty \n \t";
  const char *trim_chars = NULL;
  const char *expected = "qwerty";
  s21_trim(str, trim_chars);
  ck_assert_str_eq(str, expected);
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
  // 1
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
  // 2
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

  TCase *tc_strerror = tcase_create("s21_strerror");
  tcase_add_test(tc_strerror, test_strerror_normal);
  tcase_add_test(tc_strerror, test_strerror_normal2);
  tcase_add_test(tc_strerror, test_strerror_normal3);
  suite_add_tcase(suite, tc_strerror);
  // 3
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

  // Suite *s1 = suite_create("s21_string");
  TCase *tc_sprintf = tcase_create("s21_sprintf");
  // SRunner *sr = srunner_create(s1);
  //  int nf;
  //  4
  //Здесь ошибка тест кейс не проходит
  tcase_add_test(tc_sprintf, s21_sprintf_o_test);
  tcase_add_test(tc_sprintf, s21_sprintf_f_test);
  tcase_add_test(tc_sprintf, s21_sprintf_g_test);
  tcase_add_test(tc_sprintf, s21_sprintf_prc_test);
  tcase_add_test(tc_sprintf, s21_sprintf_test);
  tcase_add_test(tc_sprintf, s21_sprintf_e_test);
  tcase_add_test(tc_sprintf, s21_sprintf_p_test);
  tcase_add_test(tc_sprintf, s21_sprintf_o_test);
  tcase_add_test(tc_sprintf, s21_sprintf_x_X_test);
  tcase_add_test(tc_sprintf, s21_sprintf_c_test);
  tcase_add_test(tc_sprintf, s21_sprintf_s_test);
  tcase_add_test(tc_sprintf, s21_sprintf_u_test);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test_2);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test_3);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test_4);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test_5);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test_6);
  tcase_add_test(tc_sprintf, s21_sprintf_d_test_0);
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
  //Здесь ошибка тест кейс не проходит

  TCase *tc_insert = tcase_create("s21_insert");
  tcase_add_test(tc_insert, test_insert_1);
  tcase_add_test(tc_insert, test_insert_2);
  tcase_add_test(tc_insert, test_insert_3);
  tcase_add_test(tc_insert, test_insert_4);
  tcase_add_test(tc_insert, test_insert_5);
  tcase_add_test(tc_insert, test_insert_6);
  suite_add_tcase(suite, tc_insert);

  //Здесь ошибка тест кейс не проходит
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
  srunner_free(suite_runner);

  return EXIT_SUCCESS;
}