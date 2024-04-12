#include "../s21_tests_runner.h"

START_TEST(s21_set_sign_00) {
  s21_decimal test_decimal = {};

  s21_set_sign(&test_decimal, 0);
  ck_assert_int_eq(test_decimal.bits[DCML_BITS_COUNT - 1], 0);
}
END_TEST

START_TEST(s21_set_sign_01) {
  s21_decimal test_decimal = {};

  s21_set_sign(&test_decimal, 1);

  ck_assert_int_eq(
      *((unsigned char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
        (DCML_SIGN_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8)),
      CHAR_MAX + 1);
}
END_TEST

START_TEST(s21_set_sign_02) {
  s21_decimal test_decimal = {};

  *((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
    (DCML_SIGN_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8)) = CHAR_MAX;

  s21_set_sign(&test_decimal, 0);
  ck_assert_int_eq(
      *((unsigned char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
        (DCML_SIGN_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8)),
      CHAR_MAX);
}
END_TEST

START_TEST(s21_set_sign_03) {
  s21_decimal test_decimal = {};

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_sign(&test_decimal, 1);

  for (unsigned long int i = 0; i < sizeof(test_decimal); ++i) {
    ck_assert_int_eq(*((char *)(&test_decimal.bits) + i), -1);
  }
}
END_TEST

START_TEST(s21_set_sign_04) {
  s21_decimal test_decimal = {};

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  s21_set_sign(&test_decimal, 0);

  for (unsigned long int i = 0; i < sizeof(test_decimal) - 1; ++i) {
    ck_assert_int_eq(*((char *)(&test_decimal.bits) + i), -1);
  }

  ck_assert_int_eq(*((char *)(&test_decimal.bits) + sizeof(test_decimal) - 1),
                   127);
}
END_TEST

Suite *s21_set_sign_suite() {
  TCase *tcase = tcase_create("s21_set_sign_tcase");
  Suite *suite = suite_create("s21_set_sign");

  tcase_add_test(tcase, s21_set_sign_00);
  tcase_add_test(tcase, s21_set_sign_01);
  tcase_add_test(tcase, s21_set_sign_02);
  tcase_add_test(tcase, s21_set_sign_03);
  tcase_add_test(tcase, s21_set_sign_04);

  suite_add_tcase(suite, tcase);
  return suite;
}
