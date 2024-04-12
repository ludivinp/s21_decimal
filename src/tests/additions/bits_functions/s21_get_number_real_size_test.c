#include "../../s21_tests_runner.h"

START_TEST(s21_get_number_real_size_00) {
  int test_number = 0;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  ck_assert_int_eq(s21_get_number_real_size(test_number_info), 0);
}
END_TEST

START_TEST(s21_get_number_real_size_01) {
  int test_number = 1;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  ck_assert_int_eq(s21_get_number_real_size(test_number_info), 1);
}
END_TEST

START_TEST(s21_get_number_real_size_02) {
  int test_number = (int)pow(2, 5) - 1;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  ck_assert_int_eq(s21_get_number_real_size(test_number_info), 5);
}
END_TEST

START_TEST(s21_get_number_real_size_03) {
  int test_number = -1;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  ck_assert_int_eq(s21_get_number_real_size(test_number_info),
                   sizeof(test_number) * 8);
}
END_TEST

START_TEST(s21_get_number_real_size_04) {
  char test_number = -1;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  ck_assert_int_eq(s21_get_number_real_size(test_number_info),
                   sizeof(test_number) * 8);
}
END_TEST

START_TEST(s21_get_number_real_size_05) {
  long long int test_number = -1;

  info_for_bit_calc test_number_info = {.sign = 0,
                                        .start_bit_index = 0,
                                        .bits_count = sizeof(test_number) * 8,
                                        .value = &test_number};

  ck_assert_int_eq(s21_get_number_real_size(test_number_info),
                   sizeof(test_number) * 8);
}
END_TEST

START_TEST(s21_get_number_real_size_06) {
  long long int test_number = -1;

  info_for_bit_calc test_number_info = {
      .sign = 0, .start_bit_index = 1, .bits_count = 2, .value = &test_number};

  ck_assert_int_eq(s21_get_number_real_size(test_number_info), 2);
}
END_TEST

Suite *s21_get_number_real_size_suite() {
  TCase *tcase = tcase_create("s21_get_number_real_size_tcase");
  Suite *suite = suite_create("s21_get_number_real_size");

  tcase_add_test(tcase, s21_get_number_real_size_00);
  tcase_add_test(tcase, s21_get_number_real_size_01);
  tcase_add_test(tcase, s21_get_number_real_size_02);
  tcase_add_test(tcase, s21_get_number_real_size_03);
  tcase_add_test(tcase, s21_get_number_real_size_04);
  tcase_add_test(tcase, s21_get_number_real_size_05);
  tcase_add_test(tcase, s21_get_number_real_size_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
