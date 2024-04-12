#include "../s21_tests_runner.h"

START_TEST(s21_from_float_to_decimal_00) {
  s21_from_float_to_decimal(10, NULL);
}
END_TEST

START_TEST(s21_from_float_to_decimal_01) {
  long double number = NAN;
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(number, &test_decimal),
                   CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_02) {
  long double number = INFINITY;
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(number, &test_decimal),
                   CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_03) {
  long double number = -INFINITY;
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(number, &test_decimal),
                   CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_04) {
  long double number = DCML_MAX * 2;
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(number, &test_decimal),
                   CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_05) {
  long double number = -(DCML_MAX * 2);
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(number, &test_decimal),
                   CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_06) {
  long double number = DCML_MIN / 10;
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(number, &test_decimal),
                   CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_07) {
  long double number = -(DCML_MIN / 10);
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(number, &test_decimal),
                   CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_08) {
  float number = 0;
  memset(&number, 0, sizeof(number));

  s21_decimal test_decimal = {};

  s21_from_float_to_decimal(number, &test_decimal);

  ck_assert_int_eq(memcmp(&test_decimal.bits[0], &number, sizeof(number)), 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_09) {
  float number = 123456.0f;
  DCML_BITS_TYPE result = 123456;

  s21_decimal test_decimal = {};

  s21_from_float_to_decimal(number, &test_decimal);

  ck_assert_int_eq((s21_is_positive(&test_decimal) ? test_decimal.bits[0]
                                                   : -test_decimal.bits[0]),
                   result);
}
END_TEST

START_TEST(s21_from_float_to_decimal_10) {
  float number = -123456.0f;
  DCML_BITS_TYPE result = -123456;

  s21_decimal test_decimal = {};

  s21_from_float_to_decimal(number, &test_decimal);

  ck_assert_int_eq((s21_is_positive(&test_decimal) ? test_decimal.bits[0]
                                                   : -test_decimal.bits[0]),
                   result);
}
END_TEST

Suite *s21_from_float_to_decimal_suite() {
  TCase *tcase = tcase_create("s21_from_float_to_decimal_tcase");
  Suite *suite = suite_create("s21_from_float_to_decimal");

  tcase_add_test(tcase, s21_from_float_to_decimal_00);
  tcase_add_test(tcase, s21_from_float_to_decimal_01);
  tcase_add_test(tcase, s21_from_float_to_decimal_02);
  tcase_add_test(tcase, s21_from_float_to_decimal_03);
  tcase_add_test(tcase, s21_from_float_to_decimal_04);
  tcase_add_test(tcase, s21_from_float_to_decimal_05);
  tcase_add_test(tcase, s21_from_float_to_decimal_06);
  tcase_add_test(tcase, s21_from_float_to_decimal_07);
  tcase_add_test(tcase, s21_from_float_to_decimal_08);
  tcase_add_test(tcase, s21_from_float_to_decimal_09);
  tcase_add_test(tcase, s21_from_float_to_decimal_10);

  suite_add_tcase(suite, tcase);
  return suite;
}
