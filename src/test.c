#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_memchr) {
  ck_assert(s21_memchr("abc d ef", 'd', 8) == memchr("abc d ef", 'd', 8));
  ck_assert(s21_memchr("abc;defd", 'd', 10) == memchr("abc;defd", 'd', 10));
  ck_assert(s21_memchr("abcdef=", 'b', 1) == memchr("abcdef=", 'b', 1));
  ck_assert(s21_memchr("abcdefd", 't', 7) == memchr("abcdefd", 't', 7));
  ck_assert(s21_memchr("abcvdefdvv", 'v', 1000) == memchr("abcvdefdvv", 'v', 1000));
  ck_assert(s21_memchr("abCdef", 67, 2) == memchr("abCdef", 67, 2));
  ck_assert(s21_memchr("abc d ef", -100, 8) == memchr("abc d ef", -100, 8));
}
END_TEST

START_TEST(test_strchr) {
  ck_assert(s21_strchr("abcdef", 'd') == strchr("abcdef", 'd'));
  ck_assert(s21_strchr("abc def9", '1') == strchr("abc def9", '1'));
  ck_assert(s21_strchr("abcdefdd", 'd') == strchr("abcdefdd", 'd'));
  ck_assert(s21_strchr("abgcdgGefGddg", 71) == strchr("abgcdgGefGddg", 71));
  ck_assert(s21_strchr("abcdef", 32) == strchr("abcdef", 32));
  ck_assert(s21_strchr("abcdef", -21) == strchr("abcdef", -21));
}
END_TEST

START_TEST(test_strpbrk) {
  ck_assert(s21_strpbrk("abcdef", "feb") == strpbrk("abcdef", "feb"));
  ck_assert(s21_strpbrk("abcdef", "stkln") == strpbrk("abcdef", "stkln"));
  ck_assert(s21_strpbrk("abcdefdd", "diy") == strpbrk("abcdefdd", "diy"));
  ck_assert(s21_strpbrk("abcdef", "jrtmnfklop") == strpbrk("abcdef", "jrtmnfklop"));
  ck_assert(s21_strpbrk("awbcvvdev", "jrtmnf kloi,/p") == strpbrk("awbcvvdev", "jrtmnf kloi,/p"));
}
END_TEST

START_TEST(test_strrchr) {
  ck_assert(s21_strrchr("abcdefemc", 'c') == strrchr("abcdefemc", 'c'));
  ck_assert(s21_strrchr("abcdef", 't') == strrchr("abcdef", 't'));
  ck_assert(s21_strrchr("abcdev23fddvvkdslvvv", 'v') ==
            strrchr("abcdev23fddvvkdslvvv", 'v'));
  ck_assert(s21_strrchr("abcdef", 117) == strrchr("abcdef", 117));
  ck_assert(s21_strrchr("abcde .femc", 99) == strrchr("abcde .femc", 99));
  ck_assert(s21_strrchr("abcdefemc", -33) == strrchr("abcdefemc", -33));
}
END_TEST

Suite *string_suite(void) {
  Suite *s;
  TCase *tc_core_memchr;
  TCase *tc_core_strchr;
  TCase *tc_core_strpbrk;
  TCase *tc_core_strrchr;

  s = suite_create("String");
  tc_core_memchr = tcase_create("memchr_core");
  tc_core_strchr = tcase_create("strchr_core");
  tc_core_strpbrk = tcase_create("strpbrk_core");
  tc_core_strrchr = tcase_create("strrchr_core");

  tcase_add_test(tc_core_memchr, test_memchr);
  suite_add_tcase(s, tc_core_memchr);

  tcase_add_test(tc_core_strchr, test_strchr);
  suite_add_tcase(s, tc_core_strchr);

  tcase_add_test(tc_core_strpbrk, test_strpbrk);
  suite_add_tcase(s, tc_core_strpbrk);

  tcase_add_test(tc_core_strrchr, test_strrchr);
  suite_add_tcase(s, tc_core_strrchr);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = string_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (!number_failed) ? EXIT_SUCCESS : EXIT_FAILURE;
}