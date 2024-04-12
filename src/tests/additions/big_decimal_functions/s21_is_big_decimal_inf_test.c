#include "../../s21_tests_runner.h"
START_TEST(s21_is_big_decimal_inf_00) {
  s21_big_decimal test_big_decimal_1 = {};

  ck_assert_int_eq(s21_is_big_decimal_inf(test_big_decimal_1), 0);
}
END_TEST

START_TEST(s21_is_big_decimal_inf_01) {
  s21_big_decimal test_big_decimal_1 = {};

  memset(test_big_decimal_1.mantissa, 1, 1);

  ck_assert_int_eq(s21_is_big_decimal_inf(test_big_decimal_1), 0);
}
END_TEST

START_TEST(s21_is_big_decimal_inf_02) {
  s21_big_decimal test_big_decimal_1 = {};

  memset(test_big_decimal_1.mantissa, 1, sizeof(test_big_decimal_1.mantissa));

  ck_assert_int_eq(s21_is_big_decimal_inf(test_big_decimal_1), 1);
}
END_TEST

START_TEST(s21_is_big_decimal_inf_03) {
  s21_big_decimal test_big_decimal_1 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE / 2; i++) {
    s21_set_bit(test_big_decimal_1.mantissa, i, 1);
  }

  ck_assert_int_eq(s21_is_big_decimal_inf(test_big_decimal_1), 0);
}
END_TEST

START_TEST(s21_is_big_decimal_inf_04) {
  s21_big_decimal test_big_decimal_1 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE - 1; i++) {
    s21_set_bit(test_big_decimal_1.mantissa, i, 1);
  }

  ck_assert_int_eq(s21_is_big_decimal_inf(test_big_decimal_1), 0);
}
END_TEST

START_TEST(s21_is_big_decimal_inf_05) {
  s21_big_decimal test_big_decimal_1 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(test_big_decimal_1.mantissa, i, 1);
  }

  ck_assert_int_eq(s21_is_big_decimal_inf(test_big_decimal_1), 0);
}
END_TEST

START_TEST(s21_is_big_decimal_inf_06) {
  s21_big_decimal test_big_decimal_1 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE + 1; i++) {
    s21_set_bit(test_big_decimal_1.mantissa, i, 1);
  }

  ck_assert_int_eq(s21_is_big_decimal_inf(test_big_decimal_1), 1);
}
END_TEST

Suite *s21_is_big_decimal_inf_suite() {
  TCase *tcase = tcase_create("s21_is_big_decimal_inf_tcase");
  Suite *suite = suite_create("s21_is_big_decimal_inf");

  tcase_add_test(tcase, s21_is_big_decimal_inf_00);
  tcase_add_test(tcase, s21_is_big_decimal_inf_01);
  tcase_add_test(tcase, s21_is_big_decimal_inf_02);
  tcase_add_test(tcase, s21_is_big_decimal_inf_03);
  tcase_add_test(tcase, s21_is_big_decimal_inf_04);
  tcase_add_test(tcase, s21_is_big_decimal_inf_05);
  tcase_add_test(tcase, s21_is_big_decimal_inf_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
