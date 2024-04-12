#include "../s21_tests_runner.h"

START_TEST(s21_set_exp_00) {
  s21_decimal test_decimal = {};
  char exponent = 0;

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]))
                       [DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8],
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_01) {
  s21_decimal test_decimal = {};
  char exponent = 1;

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_02) {
  s21_decimal test_decimal = {};
  char exponent = -1;

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_03) {
  s21_decimal test_decimal = {};
  char exponent = 127;

  s21_set_exp(&test_decimal, exponent);

  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_04) {
  s21_decimal test_decimal = {};
  char exponent = -127;

  s21_set_exp(&test_decimal, exponent);

  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_05) {
  s21_decimal test_decimal = {};
  char exponent = 123;

  s21_set_exp(&test_decimal, exponent);

  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_06) {
  s21_decimal test_decimal = {};
  char exponent = 28;

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_07) {
  s21_decimal test_decimal = {};
  char exponent = 0;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_08) {
  s21_decimal test_decimal = {};
  char exponent = 1;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_09) {
  s21_decimal test_decimal = {};
  char exponent = -1;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_10) {
  s21_decimal test_decimal = {};
  char exponent = 7;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
                     DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8),
                   exponent);
}
END_TEST

START_TEST(s21_set_exp_11) {
  s21_decimal test_decimal = {};
  char exponent = 0;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(s21_get_exp(&test_decimal), exponent);
}
END_TEST

START_TEST(s21_set_exp_12) {
  s21_decimal test_decimal = {};
  char exponent = 1;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(s21_get_exp(&test_decimal), exponent);
}
END_TEST

START_TEST(s21_set_exp_13) {
  s21_decimal test_decimal = {};
  unsigned char exponent = -1;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(s21_get_exp(&test_decimal), exponent);
}
END_TEST

START_TEST(s21_set_exp_14) {
  s21_decimal test_decimal = {};
  char exponent = 126;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(s21_get_exp(&test_decimal), exponent);
}
END_TEST

START_TEST(s21_set_exp_15) {
  s21_decimal test_decimal = {};
  unsigned char exponent = -126;

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_exp(&test_decimal, exponent);
  ck_assert_int_eq(s21_get_exp(&test_decimal), exponent);
}
END_TEST

Suite *s21_set_exp_suite() {
  TCase *tcase = tcase_create("s21_set_exp_tcase");
  Suite *suite = suite_create("s21_set_exp");

  tcase_add_test(tcase, s21_set_exp_00);
  tcase_add_test(tcase, s21_set_exp_01);
  tcase_add_test(tcase, s21_set_exp_02);
  tcase_add_test(tcase, s21_set_exp_03);
  tcase_add_test(tcase, s21_set_exp_04);
  tcase_add_test(tcase, s21_set_exp_05);
  tcase_add_test(tcase, s21_set_exp_06);
  tcase_add_test(tcase, s21_set_exp_07);
  tcase_add_test(tcase, s21_set_exp_08);
  tcase_add_test(tcase, s21_set_exp_09);
  tcase_add_test(tcase, s21_set_exp_10);
  tcase_add_test(tcase, s21_set_exp_11);
  tcase_add_test(tcase, s21_set_exp_12);
  tcase_add_test(tcase, s21_set_exp_13);
  tcase_add_test(tcase, s21_set_exp_14);
  tcase_add_test(tcase, s21_set_exp_15);

  suite_add_tcase(suite, tcase);
  return suite;
}
