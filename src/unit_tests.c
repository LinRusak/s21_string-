/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test.check" instead.
 */

#include <check.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "s21_strlen.c"
#include "s21_memchr.c"
#include "s21_memcmp.c"
#include "s21_strncpy.c"
#include "s21_strpbrk.c"
#include "s21_strtok.c"
#include "s21_strspn.c"
#include "s21_strchr.c"
#include "s21_strncmp.c"
#include "s21_strncat.c"
#include "s21_memset.c"
#include "s21_memcpy.c"
#include "s21_strstr.c"
#include "s21_strrchr.c"
#include "s21_to_upper.c" //нужно прописать тесты
#include "s21_to_lower.c" //нужно прописать тесты
#include "s21_insert.c" //нужно прописать тесты
#include "s21_trim.c" //нужно прописать тесты

START_TEST(strlen_test)
{
char test_1[] = "12345";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = "   ";
  char test_5[] = "123\0456";
  char test_6[] = "hhh\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));

}
END_TEST

START_TEST(memchr_test)
{
 char test1[] = "123456";
  char test2 = '4';
  char test3 = '7';
  char test4[] = "hello/\0";
  char test5[] = "h";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 6),
                    (unsigned long)memchr(test1, test2, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 6),
                    (unsigned long)memchr(test1, test3, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 6),
                    (unsigned long)memchr(test4, test6, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 6),
                    (unsigned long)memchr(test4, test8, 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 6),
                    (unsigned long)memchr(test4, test9, 6));

}
END_TEST

START_TEST(memcmp_test)
{
 char test1[] = "Apple Pay Money Day";
  char test2[] = "Apple with worm";
  char test3[] = "\0";
  char test4[] = "gud\0 job";
  char test5[] = "gud\0 job";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 16) < 0, memcmp(test1, test2, 16) < 0);
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0, memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0, memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0, memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0, memcmp(test4, test5, 7) == 0);

}
END_TEST

START_TEST(strncpy_test)
{
 char str1[] = "test of string";
  char dest1[15] = "";

  char str2[] = "test\0";
  char dest2[5] = "";

  char str3[] = "test ";
  char dest3[] = "crushcrush";

  ck_assert_str_eq("test ", s21_strncpy(dest1, str1, 5));
  ck_assert_str_eq("test", s21_strncpy(dest2, str2, 4));
  ck_assert_str_eq(strncpy(dest3, str3, 10), s21_strncpy(dest3, str3, 10));

  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));

}
END_TEST

START_TEST(strbpbrk_test)
{
char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));

  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty), (unsigned long)strpbrk(str, empty));

}
END_TEST

START_TEST(strtok_test)
{
   char str [24]= "test1/test2/test3/test4";
   char sep [10]="/";
   ck_assert_ptr_eq(s21_strtok(str,sep),strtok(str,sep));


}
END_TEST

START_TEST(strncmp_test)
{
char str1[] = "hella 1";
  char str2[] = "hello 3";
  ck_assert_int_eq(s21_strncmp(str1, str2, 5) < 0, strncmp(str1, str2, 5) < 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 3) == 0, strncmp(str1, str2, 3) == 0);

}
END_TEST

START_TEST(strspn_test)
{
  char str1[] = "hella 1";
  char str2[] = "ell";

  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));

}
END_TEST

START_TEST(strcat_test)
{
 char test1[] = "Apple Pay Money Day";
    char test3[10] = "\0";
    ck_assert_uint_eq((unsigned long)s21_strncat(test1, test3,5), (unsigned long)strncat(test1, test3,5));

}
END_TEST

START_TEST(memset_test)
{
unsigned char test1[10] = "1234357890";
  unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '1', 10),
                    (unsigned long)memset(test1, '1', 10));

}
END_TEST

START_TEST(memcpy_test)
{
char test_1[10] = "12345";
  char test_2[] = "  ";
  char test_3[20] = "///  ";
  char test_4[] = "   ///";
  char test_5[30] = "";
  char test_6[] = "4444";
  char test_7[] = "123\0123";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));

}
END_TEST

START_TEST(strstr_test)
{
 char test_1[] = "<<<5>>>";
    char test_2[] = "5";
    char test_3[] = "QwertyQwertyQwerty";
    char test_4[] = "Qwerty";
    char test_5[] = "abc d";
    char test_6[] = " ";
    char test_7[] = "aaaaa123aaa1234aaa";
    char test_8[] = "1234";

    ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
    ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
    ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
    ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
    ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));

}
END_TEST

START_TEST(strchr_test)
{
char lotr[] = "_-=Властелин к0лец=-_";
ck_assert_ptr_eq(s21_strchr(lotr, '0'),strchr(lotr, '0'));



}
END_TEST

START_TEST(strrch_test)
{
char lotr[] = "_-=Властелин к0льц0=-_";
ck_assert_ptr_eq(s21_strrchr(lotr, '0'),strrchr(lotr, '0'));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, strlen_test);
    tcase_add_test(tc1_1, memchr_test);
    tcase_add_test(tc1_1, memcmp_test);
    tcase_add_test(tc1_1, strncpy_test);
    tcase_add_test(tc1_1, strbpbrk_test);
    tcase_add_test(tc1_1, strtok_test);
    tcase_add_test(tc1_1, strncmp_test);
    tcase_add_test(tc1_1, strspn_test);
    tcase_add_test(tc1_1, strcat_test);
    tcase_add_test(tc1_1, memset_test);
    tcase_add_test(tc1_1, memcpy_test);
    tcase_add_test(tc1_1, strstr_test);
    tcase_add_test(tc1_1, strchr_test);
    tcase_add_test(tc1_1, strrch_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
