#include "../../s21_tests_runner.h"

START_TEST(s21_removing_last_zeros_00) {
  s21_big_decimal test_big_decimal_1 = {};
  s21_big_decimal test_big_decimal_2 = test_big_decimal_1;

  s21_removing_last_zeros(&test_big_decimal_1);

  ck_assert_int_eq(test_big_decimal_1.sign, test_big_decimal_2.sign);
  ck_assert_int_eq(test_big_decimal_1.exponent, test_big_decimal_2.exponent);
  ck_assert_int_eq(
      memcmp(&test_big_decimal_1.mantissa, &test_big_decimal_2.mantissa,
             sizeof(test_big_decimal_1.mantissa)),
      0);
}
END_TEST

START_TEST(s21_removing_last_zeros_01) {
  s21_big_decimal test_big_decimal_1 = {
      .exponent = _i,
      .mantissa[0] = (DCML_BITS_TYPE)(rint(pow(10, _i))),
      .sign = (char)(_i % 2)};

  s21_removing_last_zeros(&test_big_decimal_1);

  ck_assert_int_eq(test_big_decimal_1.exponent, 0);
  ck_assert_int_eq(test_big_decimal_1.mantissa[0], 1);
}
END_TEST

START_TEST(s21_removing_last_zeros_02) {
  s21_big_decimal test_big_decimal_1 = {
      .exponent = _i, .mantissa[0] = 12345, .sign = (char)(_i % 2)};

  s21_removing_last_zeros(&test_big_decimal_1);

  ck_assert_int_eq(test_big_decimal_1.exponent, 0);
  ck_assert_int_eq(test_big_decimal_1.mantissa[0], 12345);
}
END_TEST

Suite *s21_removing_last_zeros_suite() {
  TCase *tcase = tcase_create("s21_removing_last_zeros_tcase");
  Suite *suite = suite_create("s21_removing_last_zeros");

  tcase_add_test(tcase, s21_removing_last_zeros_00);
  tcase_add_loop_test(tcase, s21_removing_last_zeros_01, 0, 8);
  tcase_add_test(tcase, s21_removing_last_zeros_02);

  suite_add_tcase(suite, tcase);
  return suite;
}
