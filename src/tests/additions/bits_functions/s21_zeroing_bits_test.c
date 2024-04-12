#include "../../s21_tests_runner.h"

START_TEST(s21_zeroing_bits_00) {
  unsigned int test_number = 0;

  s21_zeroing_bits(&test_number, 0, sizeof(test_number) * 8);

  ck_assert_int_eq(test_number, 0);
}
END_TEST

START_TEST(s21_zeroing_bits_01) {
  unsigned int test_number = -1;

  s21_zeroing_bits(&test_number, 0, sizeof(test_number) * 8);

  ck_assert_int_eq(test_number, 0);
}
END_TEST

START_TEST(s21_zeroing_bits_02) {
  unsigned int test_number = 2;

  s21_zeroing_bits(&test_number, 1, 1);

  ck_assert_int_eq(test_number, 0);
}
END_TEST

START_TEST(s21_zeroing_bits_03) {
  unsigned int test_number = -1;

  s21_zeroing_bits(&test_number, sizeof(test_number) * 8 - 1, 1);

  ck_assert_int_eq(test_number, INT_MAX);
}
END_TEST

Suite *s21_zeroing_bits_suite() {
  TCase *tcase = tcase_create("s21_zeroing_bits_tcase");
  Suite *suite = suite_create("s21_zeroing_bits");

  tcase_add_test(tcase, s21_zeroing_bits_00);
  tcase_add_test(tcase, s21_zeroing_bits_01);
  tcase_add_test(tcase, s21_zeroing_bits_02);
  tcase_add_test(tcase, s21_zeroing_bits_03);

  suite_add_tcase(suite, tcase);
  return suite;
}
