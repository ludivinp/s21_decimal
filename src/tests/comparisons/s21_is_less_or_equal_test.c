#include "../s21_tests_runner.h"

START_TEST(s21_is_less_or_equal_00) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  ck_assert_int_eq(s21_is_less_or_equal(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_01) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.4567f, &test_decimal_1);

  s21_from_float_to_decimal(123.4567f, &test_decimal_2);

  ck_assert_int_eq(s21_is_less_or_equal(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_02) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.4561f, &test_decimal_1);

  s21_from_float_to_decimal(123.4560f, &test_decimal_2);

  ck_assert_int_eq(s21_is_less_or_equal(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_03) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.4560f, &test_decimal_1);

  s21_from_float_to_decimal(123.4561f, &test_decimal_2);

  ck_assert_int_eq(s21_is_less_or_equal(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_04) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0.12345f, &test_decimal_1);

  s21_from_float_to_decimal(0.12345f, &test_decimal_2);

  ck_assert_int_eq(s21_is_less_or_equal(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_05) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0.12340f, &test_decimal_1);

  s21_from_float_to_decimal(0.12345f, &test_decimal_2);

  ck_assert_int_eq(s21_is_less_or_equal(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_06) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0.12345f, &test_decimal_1);

  s21_from_float_to_decimal(0.12340f, &test_decimal_2);

  ck_assert_int_eq(s21_is_less_or_equal(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

Suite *s21_is_less_or_equal_suite() {
  TCase *tcase = tcase_create("s21_is_less_or_equal_tcase");
  Suite *suite = suite_create("s21_is_less_or_equal");

  tcase_add_test(tcase, s21_is_less_or_equal_00);
  tcase_add_test(tcase, s21_is_less_or_equal_01);
  tcase_add_test(tcase, s21_is_less_or_equal_02);
  tcase_add_test(tcase, s21_is_less_or_equal_03);
  tcase_add_test(tcase, s21_is_less_or_equal_04);
  tcase_add_test(tcase, s21_is_less_or_equal_05);
  tcase_add_test(tcase, s21_is_less_or_equal_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
