#include "../s21_tests_runner.h"

START_TEST(s21_is_positive_00) {
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_is_positive(&test_decimal), 1);
}
END_TEST

START_TEST(s21_is_positive_01) {
  s21_decimal test_decimal = {};

  *((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
    (DCML_SIGN_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8)) =
      (char)(CHAR_MAX + 1);

  ck_assert_int_eq(s21_is_positive(&test_decimal), 0);
}
END_TEST

START_TEST(s21_is_positive_02) {
  s21_decimal test_decimal = {};

  memset(&test_decimal.bits, -1, sizeof(test_decimal));

  *((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1]) +
    (DCML_SIGN_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) / 8)) = CHAR_MAX;

  ck_assert_int_eq(s21_is_positive(&test_decimal), 1);
}
END_TEST

Suite *s21_is_positive_suite() {
  TCase *tcase = tcase_create("s21_is_positive_tcase");
  Suite *suite = suite_create("s21_is_positive");

  tcase_add_test(tcase, s21_is_positive_00);
  tcase_add_test(tcase, s21_is_positive_01);
  tcase_add_test(tcase, s21_is_positive_02);

  suite_add_tcase(suite, tcase);
  return suite;
}
