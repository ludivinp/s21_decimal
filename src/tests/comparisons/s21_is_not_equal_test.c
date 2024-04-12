#include "../s21_tests_runner.h"

START_TEST(s21_is_not_equal_00) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  value_1.bits[0] = 1024;
  value_2.bits[0] = 1024;

  ck_assert_int_eq(s21_is_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_01) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  value_1.bits[0] = 1024;
  value_2.bits[0] = 1023;

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_02) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_03) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  // Set sign.
  value_1.bits[3] = ((DCML_BITS_TYPE)1 << 31);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_04) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  value_1.bits[0] = 0;
  value_2.bits[0] = 0;

  // Set scale factor.
  value_1.bits[3] = (1 << 16);

  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

Suite *s21_is_not_equal_suite() {
  TCase *tcase = tcase_create("s21_is_not_equal_tcase");
  Suite *suite = suite_create("s21_is_not_equal");

  tcase_add_test(tcase, s21_is_not_equal_00);
  tcase_add_test(tcase, s21_is_not_equal_01);
  tcase_add_test(tcase, s21_is_not_equal_02);
  tcase_add_test(tcase, s21_is_not_equal_03);
  tcase_add_test(tcase, s21_is_not_equal_04);

  suite_add_tcase(suite, tcase);
  return suite;
}