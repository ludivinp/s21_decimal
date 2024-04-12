#include "../s21_tests_runner.h"

START_TEST(s21_zeroing_decimal_00) {
  s21_decimal test_decimal = {};

  s21_zeroing_decimal(&test_decimal);

  ck_assert_int_eq(1, s21_is_positive(&test_decimal));
}

START_TEST(s21_zeroing_decimal_01) {
  s21_decimal test_decimal = {};

  s21_zeroing_decimal(&test_decimal);

  ck_assert_int_eq(0, s21_get_exp(&test_decimal));
}

START_TEST(s21_zeroing_decimal_02) {
  s21_decimal test_decimal = {};

  s21_zeroing_decimal(&test_decimal);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    ck_assert_int_eq(0,
                     s21_get_bit(test_decimal.bits, DCML_MANT_BIT_INDEX + i));
  }
}

START_TEST(s21_zeroing_decimal_03) {
  s21_decimal test_decimal = {};

  s21_set_sign(&test_decimal, 1);

  s21_zeroing_decimal(&test_decimal);

  ck_assert_int_eq(1, s21_is_positive(&test_decimal));
}

START_TEST(s21_zeroing_decimal_04) {
  s21_decimal test_decimal = {};

  s21_set_exp(&test_decimal, 10);

  s21_zeroing_decimal(&test_decimal);

  ck_assert_int_eq(0, s21_get_exp(&test_decimal));
}

START_TEST(s21_zeroing_decimal_05) {
  s21_decimal test_decimal = {};
  long int test_number = -1;

  info_for_bit_calc test_number_info = {.value = &test_number,
                                        .bits_count = sizeof(test_number),
                                        .sign = 0,
                                        .start_bit_index = 0};

  info_for_bit_calc test__decimal_info = {
      .value = test_decimal.bits,
      .bits_count = DCML_MANT_BIT_SIZE,
      .sign = 0,
      .start_bit_index = DCML_MANT_BIT_INDEX};

  s21_get_bit_segment(&test_number_info, &test__decimal_info);

  s21_zeroing_decimal(&test_decimal);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    ck_assert_int_eq(0,
                     s21_get_bit(test_decimal.bits, DCML_MANT_BIT_INDEX + i));
  }
}

Suite *s21_zeroing_decimal_suite() {
  TCase *tcase = tcase_create("s21_zeroing_decimal_tcase");
  Suite *suite = suite_create("s21_zeroing_decimal");

  tcase_add_test(tcase, s21_zeroing_decimal_00);
  tcase_add_test(tcase, s21_zeroing_decimal_01);
  tcase_add_test(tcase, s21_zeroing_decimal_02);
  tcase_add_test(tcase, s21_zeroing_decimal_03);
  tcase_add_test(tcase, s21_zeroing_decimal_04);
  tcase_add_test(tcase, s21_zeroing_decimal_05);

  suite_add_tcase(suite, tcase);
  return suite;
}
