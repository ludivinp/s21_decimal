#include "../../s21_tests_runner.h"

START_TEST(s21_bits_comparison_00) {
  unsigned int test_number_1 = 0;
  unsigned int test_number_2 = 0;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_01) {
  unsigned int test_number_1 = 0;
  unsigned int test_number_2 = 0;
  char result = 1;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_02) {
  unsigned int test_number_1 = 1;
  unsigned int test_number_2 = 1;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_03) {
  unsigned int test_number_1 = 0;
  unsigned int test_number_2 = 0;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_04) {
  unsigned int test_number_1 = 0;
  unsigned int test_number_2 = 0;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_05) {
  unsigned int test_number_1 = 0;
  unsigned int test_number_2 = 0;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_06) {
  unsigned int test_number_1 = 1;
  unsigned int test_number_2 = 1;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_07) {
  unsigned int test_number_1 = 1;
  unsigned int test_number_2 = 0;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(1, result);
}

START_TEST(s21_bits_comparison_08) {
  unsigned int test_number_1 = 0;
  unsigned int test_number_2 = 1;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(-1, result);
}

START_TEST(s21_bits_comparison_09) {
  unsigned int test_number_1 = 1;
  unsigned int test_number_2 = 0;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(-1, result);
}

START_TEST(s21_bits_comparison_10) {
  unsigned int test_number_1 = 0;
  unsigned int test_number_2 = 1;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(1, result);
}

START_TEST(s21_bits_comparison_11) {
  unsigned int test_number_1 = 1234567;
  unsigned int test_number_2 = 1234567;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(-1, result);
}

START_TEST(s21_bits_comparison_12) {
  unsigned int test_number_1 = 1234567;
  unsigned int test_number_2 = 1234567;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(1, result);
}

START_TEST(s21_bits_comparison_13) {
  unsigned int test_number_1 = 1234567;
  unsigned int test_number_2 = 1234567;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 1,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(0, result);
}

START_TEST(s21_bits_comparison_14) {
  unsigned int test_number_1 = 12345671;
  unsigned int test_number_2 = 12345670;
  char result = 0;

  info_for_bit_calc test_number_1_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_1) * 8,
      .value = &test_number_1};
  info_for_bit_calc test_number_2_info = {
      .sign = 0,
      .start_bit_index = 0,
      .bits_count = sizeof(test_number_2) * 8,
      .value = &test_number_2};

  s21_bits_comparison(test_number_1_info, test_number_2_info, &result);

  ck_assert_int_eq(1, result);
}

Suite *s21_bits_comparison_suite() {
  TCase *tcase = tcase_create("s21_bits_comparison_tcase");
  Suite *suite = suite_create("s21_bits_comparison");

  tcase_add_test(tcase, s21_bits_comparison_00);
  tcase_add_test(tcase, s21_bits_comparison_01);
  tcase_add_test(tcase, s21_bits_comparison_02);
  tcase_add_test(tcase, s21_bits_comparison_03);
  tcase_add_test(tcase, s21_bits_comparison_04);
  tcase_add_test(tcase, s21_bits_comparison_05);
  tcase_add_test(tcase, s21_bits_comparison_06);
  tcase_add_test(tcase, s21_bits_comparison_07);
  tcase_add_test(tcase, s21_bits_comparison_08);
  tcase_add_test(tcase, s21_bits_comparison_09);
  tcase_add_test(tcase, s21_bits_comparison_10);
  tcase_add_test(tcase, s21_bits_comparison_11);
  tcase_add_test(tcase, s21_bits_comparison_12);
  tcase_add_test(tcase, s21_bits_comparison_13);
  tcase_add_test(tcase, s21_bits_comparison_14);

  suite_add_tcase(suite, tcase);
  return suite;
}
