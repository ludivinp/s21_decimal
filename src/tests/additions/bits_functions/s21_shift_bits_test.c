#include "../../s21_tests_runner.h"

START_TEST(s21_shift_bits_00) {
  unsigned int test_number = 1;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  s21_shift_bits(&test_number_info, 0, 0);

  ck_assert_int_eq(1, test_number);
}
END_TEST

START_TEST(s21_shift_bits_01) {
  unsigned char test_number = 1;
  unsigned char result_number = test_number;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  s21_shift_bits(&test_number_info, _i, 0);

  ck_assert_int_eq(result_number << _i, test_number);
}
END_TEST

START_TEST(s21_shift_bits_02) {
  unsigned char test_number = CHAR_MAX + 1;
  unsigned char result_number = test_number;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  s21_shift_bits(&test_number_info, _i, 1);

  ck_assert_int_eq(result_number >> _i, test_number);
}
END_TEST

START_TEST(s21_shift_bits_03) {
  unsigned char test_number = CHAR_MAX + 1;
  unsigned char result_number = test_number;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  s21_shift_bits(&test_number_info, 16, 1);

  ck_assert_int_eq(result_number >> 16, test_number);
}
END_TEST

Suite *s21_shift_bits_suite() {
  TCase *tcase = tcase_create("s21_shift_bits_tcase");
  Suite *suite = suite_create("s21_shift_bits");

  tcase_add_test(tcase, s21_shift_bits_00);
  tcase_add_loop_test(tcase, s21_shift_bits_01, 0, 8);
  tcase_add_loop_test(tcase, s21_shift_bits_02, 0, 8);
  tcase_add_test(tcase, s21_shift_bits_03);

  suite_add_tcase(suite, tcase);
  return suite;
}
