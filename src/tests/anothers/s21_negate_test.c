#include "../s21_tests_runner.h"

START_TEST(s21_negate_00) {
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_negate(test_decimal, NULL), CONVERTORS_ERROR);
}
END_TEST

START_TEST(s21_negate_01) {
  s21_decimal test_decimal = {};

  ck_assert_int_eq(s21_negate(test_decimal, &test_decimal), CONVERTORS_OK);
}
END_TEST

START_TEST(s21_negate_02) {
  s21_decimal test_decimal = {};

  s21_negate(test_decimal, &test_decimal);
  ck_assert_int_eq(s21_is_positive(&test_decimal), 0);
}
END_TEST

START_TEST(s21_negate_03) {
  s21_decimal test_decimal = {};

  s21_negate(test_decimal, &test_decimal);
  ck_assert_int_eq(s21_is_positive(&test_decimal), 0);

  s21_negate(test_decimal, &test_decimal);
  ck_assert_int_eq(s21_is_positive(&test_decimal), 1);
}
END_TEST

START_TEST(s21_negate_04) {
  s21_decimal test_decimal = {};

  s21_set_sign(&test_decimal, 1);

  s21_negate(test_decimal, &test_decimal);

  ck_assert_int_eq(*((char *)(&test_decimal.bits[DCML_BITS_COUNT - 1])), 0);
}
END_TEST

START_TEST(s21_negate_05) {
  s21_decimal test_decimal = {};

  memset(&test_decimal.bits, -1, sizeof(test_decimal));
  {
    s21_negate(test_decimal, &test_decimal);

    for (unsigned long int i = 0; i < sizeof(test_decimal) - 1; ++i) {
      ck_assert_int_eq(*((char *)(&test_decimal.bits) + i), -1);
    }
    ck_assert_int_eq(*((char *)(&test_decimal.bits) + sizeof(test_decimal) - 1),
                     127);
  }

  {
    s21_negate(test_decimal, &test_decimal);

    for (unsigned long int i = 0; i < sizeof(test_decimal); ++i) {
      ck_assert_int_eq(*((char *)(&test_decimal.bits) + i), -1);
    }
  }
}
END_TEST

Suite *s21_negate_suite() {
  TCase *tcase = tcase_create("s21_negate_tcase");
  Suite *suite = suite_create("s21_negate");

  tcase_add_test(tcase, s21_negate_00);
  tcase_add_test(tcase, s21_negate_01);
  tcase_add_test(tcase, s21_negate_02);
  tcase_add_test(tcase, s21_negate_03);
  tcase_add_test(tcase, s21_negate_04);
  tcase_add_test(tcase, s21_negate_05);

  suite_add_tcase(suite, tcase);
  return suite;
}
