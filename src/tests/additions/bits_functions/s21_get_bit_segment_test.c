#include "../../s21_tests_runner.h"

START_TEST(s21_get_bit_segment_00) {
  char test = (char)powl(2, _i);
  char result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = sizeof(test) * 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(result, test);
}

START_TEST(s21_get_bit_segment_01) {
  char test = -1;
  char result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = sizeof(test) * 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(result, test);
}

START_TEST(s21_get_bit_segment_02) {
  long long int test = (long long int)powl(2, _i * 8);
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = sizeof(test) * 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(result, test);
}

START_TEST(s21_get_bit_segment_03) {
  long long int test = -1;
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = sizeof(test) * 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(result, test);
}

START_TEST(s21_get_bit_segment_04) {
  long long int test = 0;
  long long int result = -1;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = sizeof(test) * 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(result, test);
}

START_TEST(s21_get_bit_segment_05) {
  size_t size = 5;
  long long int test = (long long int)powf(2, (float)size) - 1;
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = sizeof(test) * 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(result, test);
}

START_TEST(s21_get_bit_segment_06) {
  size_t size = 1;
  long long int test = (long long int)powf(2, (float)size) - 1;
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = sizeof(test) * 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(result, test);
}

START_TEST(s21_get_bit_segment_07) {
  long long int test = -1;
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = 0};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = 0};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_ne(result, test);
}

START_TEST(s21_get_bit_segment_08) {
  long long int test = -1;
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 0, .bits_count = 1};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(1, result);
}

START_TEST(s21_get_bit_segment_09) {
  long long int test = 12345678900;
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 8, .bits_count = 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(((unsigned char *)&test)[1], result);
}

START_TEST(s21_get_bit_segment_10) {
  long long int test = 12345678900;
  long long int result = 0;

  info_for_bit_calc test_info = {
      .value = &test, .start_bit_index = 24, .bits_count = 8};
  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&test_info, &result_info);

  ck_assert_int_eq(((unsigned char *)&test)[3], result);
}

Suite *s21_get_bit_segment_suite() {
  TCase *tcase = tcase_create("s21_get_bit_segment_tcase");
  Suite *suite = suite_create("s21_get_bit_segment");

  tcase_add_loop_test(tcase, s21_get_bit_segment_00, 0, 8);
  tcase_add_test(tcase, s21_get_bit_segment_01);
  tcase_add_loop_test(tcase, s21_get_bit_segment_02, 0, 8);
  tcase_add_test(tcase, s21_get_bit_segment_03);
  tcase_add_test(tcase, s21_get_bit_segment_04);
  tcase_add_test(tcase, s21_get_bit_segment_05);
  tcase_add_test(tcase, s21_get_bit_segment_06);
  tcase_add_test(tcase, s21_get_bit_segment_07);
  tcase_add_test(tcase, s21_get_bit_segment_08);
  tcase_add_test(tcase, s21_get_bit_segment_09);
  tcase_add_test(tcase, s21_get_bit_segment_10);

  suite_add_tcase(suite, tcase);
  return suite;
}
