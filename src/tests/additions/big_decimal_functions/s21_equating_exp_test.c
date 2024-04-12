#include "../../s21_tests_runner.h"

START_TEST(s21_equating_exp_00) {
  s21_big_decimal test_big_decimal_1 = {};
  s21_big_decimal test_big_decimal_2 = {};

  s21_equating_exp(&test_big_decimal_1, &test_big_decimal_2);

  ck_assert_int_eq(test_big_decimal_1.sign, test_big_decimal_2.sign);
  ck_assert_int_eq(test_big_decimal_1.exponent, test_big_decimal_2.exponent);
  ck_assert_int_eq(
      memcmp(&test_big_decimal_1.mantissa, &test_big_decimal_2.mantissa,
             sizeof(test_big_decimal_1.mantissa)),
      0);
}
END_TEST

START_TEST(s21_equating_exp_01) {
  s21_big_decimal test_big_decimal_1 = {
      .exponent = 0, .mantissa[0] = 1234, .sign = (char)(_i % 2)};
  s21_big_decimal test_big_decimal_2 = {
      .exponent = 4, .mantissa[0] = 12340000, .sign = (char)(_i % 2)};

  s21_equating_exp(&test_big_decimal_1, &test_big_decimal_2);

  ck_assert_int_eq(test_big_decimal_1.sign, test_big_decimal_2.sign);
  ck_assert_int_eq(test_big_decimal_1.exponent, test_big_decimal_2.exponent);
  ck_assert_int_eq(
      memcmp(&test_big_decimal_1.mantissa, &test_big_decimal_2.mantissa,
             sizeof(test_big_decimal_1.mantissa)),
      0);
}
END_TEST

START_TEST(s21_equating_exp_02) {
  s21_big_decimal test_big_decimal_1 = {
      .exponent = 0, .mantissa[0] = 10, .sign = (char)(_i % 2)};
  s21_big_decimal test_big_decimal_2 = {
      .exponent = 1, .mantissa[0] = 100, .sign = (char)(_i % 2)};

  s21_equating_exp(&test_big_decimal_1, &test_big_decimal_2);

  ck_assert_int_eq(test_big_decimal_1.sign, test_big_decimal_2.sign);
  ck_assert_int_eq(test_big_decimal_1.exponent, test_big_decimal_2.exponent);
  ck_assert_int_eq(
      memcmp(&test_big_decimal_1.mantissa, &test_big_decimal_2.mantissa,
             sizeof(test_big_decimal_1.mantissa)),
      0);
}
END_TEST

START_TEST(s21_equating_exp_03) {
  s21_big_decimal test_big_decimal_1 = {
      .exponent = _i,
      .mantissa[0] = (DCML_BITS_TYPE)(rint(pow(10, _i))),
      .sign = (char)(_i % 2)};
  s21_big_decimal test_big_decimal_2 = {
      .exponent = _i,
      .mantissa[0] = (DCML_BITS_TYPE)(rint(pow(10, _i))),
      .sign = (char)(_i % 2)};

  s21_equating_exp(&test_big_decimal_1, &test_big_decimal_2);

  ck_assert_int_eq(test_big_decimal_1.sign, test_big_decimal_2.sign);
  ck_assert_int_eq(test_big_decimal_1.exponent, test_big_decimal_2.exponent);
  ck_assert_int_eq(
      memcmp(&test_big_decimal_1.mantissa, &test_big_decimal_2.mantissa,
             sizeof(test_big_decimal_1.mantissa)),
      0);
}
END_TEST

START_TEST(s21_equating_exp_04) {
  s21_big_decimal test_big_decimal_1 = {
      .exponent = _i,
      .mantissa[0] = (DCML_BITS_TYPE)(rint(pow(2, _i))),
      .sign = (char)(_i % 2)};
  s21_big_decimal test_big_decimal_2 = {
      .exponent = _i / 2,
      .mantissa[0] = (DCML_BITS_TYPE)(rint(pow(2, _i))),
      .sign = (char)(_i % 2)};

  s21_equating_exp(&test_big_decimal_1, &test_big_decimal_2);

  ck_assert_int_eq(test_big_decimal_1.sign, test_big_decimal_2.sign);
  ck_assert_int_eq(test_big_decimal_1.exponent, test_big_decimal_2.exponent);
  ck_assert_int_ne(
      memcmp(&test_big_decimal_1.mantissa, &test_big_decimal_2.mantissa,
             sizeof(test_big_decimal_1.mantissa)),
      0);
}
END_TEST

START_TEST(s21_equating_exp_05) {
  s21_big_decimal test_big_decimal_1 = {
      .exponent = _i / 2,
      .mantissa[0] = (DCML_BITS_TYPE)(rint(pow(2, _i))),
      .sign = (char)(_i % 2)};
  s21_big_decimal test_big_decimal_2 = {
      .exponent = _i,
      .mantissa[0] = (DCML_BITS_TYPE)(rint(pow(2, _i))),
      .sign = (char)(_i % 2)};

  s21_equating_exp(&test_big_decimal_1, &test_big_decimal_2);

  ck_assert_int_eq(test_big_decimal_1.sign, test_big_decimal_2.sign);
  ck_assert_int_eq(test_big_decimal_1.exponent, test_big_decimal_2.exponent);
  ck_assert_int_ne(
      memcmp(&test_big_decimal_1.mantissa, &test_big_decimal_2.mantissa,
             sizeof(test_big_decimal_1.mantissa)),
      0);
}
END_TEST

Suite *s21_equating_exp_suite() {
  TCase *tcase = tcase_create("s21_equating_exp_tcase");
  Suite *suite = suite_create("s21_equating_exp");

  tcase_add_test(tcase, s21_equating_exp_00);
  tcase_add_test(tcase, s21_equating_exp_01);
  tcase_add_test(tcase, s21_equating_exp_02);
  tcase_add_loop_test(tcase, s21_equating_exp_03, 0, 8);
  tcase_add_loop_test(tcase, s21_equating_exp_04, 1, 8);
  tcase_add_loop_test(tcase, s21_equating_exp_05, 1, 8);

  suite_add_tcase(suite, tcase);
  return suite;
}
