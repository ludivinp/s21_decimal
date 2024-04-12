#include "../s21_tests_runner.h"

START_TEST(s21_from_decimal_to_float_test_0) {
  float test_value = 0;
  s21_decimal true_value = {};
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_decimal_to_float(true_value, &test_value));
  ck_assert_float_eq(test_value, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_01) {
  float test_value = 0;
  s21_decimal true_value = {{7, 0, 0, 0}};
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_decimal_to_float(true_value, &test_value));
  ck_assert_float_eq(test_value, (float)7);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_02) {
  float test_value = 0;
  s21_decimal true_value = {{2, 0, 0, 0}};
  s21_set_sign(&true_value, 1);
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_decimal_to_float(true_value, &test_value));
  ck_assert_float_eq(test_value, -2.0f);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_03) {
  float test_value = 0;
  s21_decimal true_value = {{16384, 0, 0, 0}};
  s21_set_exp(&true_value, 3);
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_decimal_to_float(true_value, &test_value));
  ck_assert_float_eq(test_value, 16.384f);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_04) {
  float test_value = 0;
  s21_decimal true_value = {{12, 0, 0, 0}};
  s21_set_exp(&true_value, 1);
  s21_set_sign(&true_value, 1);
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_decimal_to_float(true_value, &test_value));
  ck_assert_float_eq(test_value, -1.2f);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_05) {
  float test_value = 0;
  s21_decimal true_value = {{16384, 0, 0, 0}};
  s21_set_exp(&true_value, 3);
  s21_set_sign(&true_value, 1);
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_decimal_to_float(true_value, &test_value));
  ck_assert_float_eq(test_value, -16.384);
}
END_TEST

START_TEST(s21_from_decimal_to_float_test_06) {
  float test_value = 54.5f;
  s21_decimal true_value = {{565, 0, 0, 0}};
  s21_set_exp(&true_value, 1);
  ck_assert_int_eq(CONVERTORS_OK,
                   s21_from_decimal_to_float(true_value, &test_value));
  ck_assert_float_eq(test_value, 56.5f);
}
END_TEST

Suite *s21_from_decimal_to_float_suite() {
  TCase *tcase = tcase_create("s21_from_decimal_to_float_tcase");
  Suite *suite = suite_create("s21_from_decimal_to_float");
  tcase_add_test(tcase, s21_from_decimal_to_float_test_0);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_01);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_02);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_03);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_04);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_05);
  tcase_add_test(tcase, s21_from_decimal_to_float_test_06);
  suite_add_tcase(suite, tcase);
  return suite;
}
