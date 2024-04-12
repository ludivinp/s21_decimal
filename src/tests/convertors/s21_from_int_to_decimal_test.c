#include "../s21_tests_runner.h"

START_TEST(s21_from_int_to_decimal_test_0) {
  s21_decimal test_value = {};
  int true_value = INT_MAX;
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_int_to_decimal(true_value, &test_value));
  ck_assert_int_eq(test_value.bits[0], true_value);
  ck_assert_int_eq(test_value.bits[1], 0);
  ck_assert_int_eq(test_value.bits[2], 0);
  ck_assert_int_eq(s21_is_positive(&test_value), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_1) {
  s21_decimal test_value = {};
  int true_value = 0;
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_int_to_decimal(true_value, &test_value));
  ck_assert_int_eq(test_value.bits[0], true_value);
  ck_assert_int_eq(test_value.bits[1], 0);
  ck_assert_int_eq(test_value.bits[2], 0);
  ck_assert_int_eq(s21_is_positive(&test_value), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_2) {
  s21_decimal test_value = {};
  int true_value = 1;
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_int_to_decimal(true_value, &test_value));
  ck_assert_int_eq(test_value.bits[0], true_value);
  ck_assert_int_eq(test_value.bits[1], 0);
  ck_assert_int_eq(test_value.bits[2], 0);
  ck_assert_int_eq(s21_is_positive(&test_value), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_3) {
  s21_decimal test_value = {};
  int true_value = -1;
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_int_to_decimal(true_value, &test_value));
  ck_assert_int_eq(test_value.bits[0], abs(true_value));
  ck_assert_int_eq(test_value.bits[1], 0);
  ck_assert_int_eq(test_value.bits[2], 0);
  ck_assert_int_eq(s21_is_positive(&test_value), 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_4) {
  s21_decimal test_value = {};
  int true_value = -123456;
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_int_to_decimal(true_value, &test_value));
  ck_assert_int_eq(test_value.bits[0], abs(true_value));
  ck_assert_int_eq(test_value.bits[1], 0);
  ck_assert_int_eq(test_value.bits[2], 0);
  ck_assert_int_eq(s21_is_positive(&test_value), 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_5) {
  s21_decimal test_value = {{100, 100, 100, 0}};
  int true_value = -123456;
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_int_to_decimal(true_value, &test_value));
  ck_assert_int_eq(test_value.bits[0], abs(true_value));
  ck_assert_int_eq(test_value.bits[1], 0);
  ck_assert_int_eq(test_value.bits[2], 0);
  ck_assert_int_eq(s21_is_positive(&test_value), 0);
}
END_TEST

START_TEST(s21_from_int_to_decimal_test_6) {
  s21_decimal test_value = {{100, 100, 100, 0}};
  s21_set_exp(&test_value, 2);
  int true_value = 5;
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_int_to_decimal(true_value, &test_value));
  ck_assert_int_eq(test_value.bits[0], true_value);
  ck_assert_int_eq(test_value.bits[1], 0);
  ck_assert_int_eq(test_value.bits[2], 0);
  ck_assert_int_eq(s21_is_positive(&test_value), 1);
}
END_TEST

Suite *s21_from_int_to_decimal_suite() {
  TCase *tcase = tcase_create("s21_from_int_to_decimal_tcase");
  Suite *suite = suite_create("s21_from_int_to_decimal");
  tcase_add_test(tcase, s21_from_int_to_decimal_test_0);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_1);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_2);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_3);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_4);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_5);
  tcase_add_test(tcase, s21_from_int_to_decimal_test_6);
  suite_add_tcase(suite, tcase);
  return suite;
}