#include "../../s21_tests_runner.h"

START_TEST(s21_bit_mul_00) {
  char number_1 = 0;
  char number_2 = 0;
  char result = 0;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(number_1 * number_2, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_01) {
  char number_1 = 0;
  char number_2 = 0;
  char result = -123;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 1,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(number_1 * number_2, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_02) {
  char number_1 = (char)powf(2, (float)_i);
  char number_2 = (char)powf(2, (float)_i);
  int32_t result = 0;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(number_1 * number_2, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_03) {
  char number_1 = (char)powf(2, (float)_i);
  char number_2 = (char)powf(2, (float)_i);
  int32_t result = 0;

  info_for_bit_calc number_1_info = {.sign = 1,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(-(number_1 * number_2), result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_04) {
  char number_1 = (char)powf(2, (float)_i);
  char number_2 = (char)powf(2, (float)_i);
  int32_t result = 0;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 1,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(-(number_1 * number_2), result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_05) {
  char number_1 = (char)powf(2, (float)_i);
  char number_2 = (char)powf(2, (float)_i);
  int32_t result = 0;

  info_for_bit_calc number_1_info = {.sign = 1,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 1,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(number_1 * number_2, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_06) {
  char number_1 = 8;
  char number_2 = 8;
  char result = 0;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 2,
                                     .bits_count = sizeof(number_1) * 8 - 2,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 2,
                                     .bits_count = sizeof(number_2) * 8 - 2,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(4, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_07) {
  char number_1 = 8;
  char number_2 = 8;
  char result = 0;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 2,
                                     .bits_count = sizeof(number_2) * 8 - 2,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(16, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_08) {
  char number_1 = 8;
  char number_2 = 8;
  char result = 0;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 2,
                                     .bits_count = sizeof(number_1) * 8 - 2,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(16, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_09) {
  char number_1 = 7;
  char number_2 = 7;
  char result = 0;

  info_for_bit_calc number_1_info = {
      .sign = 0, .start_bit_index = 0, .bits_count = 1, .value = &number_1};
  info_for_bit_calc number_2_info = {
      .sign = 0, .start_bit_index = 0, .bits_count = 1, .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(1, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_10) {
  char number_1 = 7;
  char number_2 = 7;
  char result = 0;

  info_for_bit_calc number_1_info = {
      .sign = 0, .start_bit_index = 0, .bits_count = 2, .value = &number_1};
  info_for_bit_calc number_2_info = {
      .sign = 0, .start_bit_index = 0, .bits_count = 2, .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(9, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_11) {
  unsigned char number_1 = UCHAR_MAX;
  unsigned char number_2 = UCHAR_MAX;
  char result = 0;

  info_for_bit_calc number_1_info = {
      .sign = 1, .start_bit_index = 7, .bits_count = 1, .value = &number_1};
  info_for_bit_calc number_2_info = {
      .sign = 0, .start_bit_index = 5, .bits_count = 3, .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OK);

  ck_assert_int_eq(-7, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_12) {
  unsigned char number_1 = UCHAR_MAX;
  unsigned char number_2 = UCHAR_MAX;

  char result = 0;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};
  info_for_bit_calc result_info = {.sign = 0,
                                   .start_bit_index = 0,
                                   .bits_count = sizeof(result) * 8,
                                   .value = &result};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &result_info),
                   BITS_OVERFLOW);

  ck_assert_int_eq(0, result_info.sign ? -result : result);
}
END_TEST

START_TEST(s21_bit_mul_13) {
  char number_1 = 5;
  char number_2 = 7;
  char number_temp = number_1;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &number_1_info),
                   BITS_OK);

  ck_assert_int_eq(number_2 * number_temp,
                   number_1_info.sign ? -number_1 : number_1);
}
END_TEST

START_TEST(s21_bit_mul_14) {
  char number_1 = 5;
  char number_2 = 7;
  char number_temp = number_2;

  info_for_bit_calc number_1_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_1) * 8,
                                     .value = &number_1};
  info_for_bit_calc number_2_info = {.sign = 0,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(number_2) * 8,
                                     .value = &number_2};

  ck_assert_int_eq(s21_bit_mul(number_1_info, number_2_info, &number_2_info),
                   BITS_OK);

  ck_assert_int_eq(number_1 * number_temp,
                   number_2_info.sign ? -number_2 : number_2);
}
END_TEST

Suite *s21_bit_mul_suite() {
  TCase *tcase = tcase_create("s21_bit_mul_tcase");
  Suite *suite = suite_create("s21_bit_mul");

  tcase_add_test(tcase, s21_bit_mul_00);
  tcase_add_test(tcase, s21_bit_mul_01);

  tcase_add_loop_test(tcase, s21_bit_mul_02, 0, 7);
  tcase_add_loop_test(tcase, s21_bit_mul_03, 0, 7);
  tcase_add_loop_test(tcase, s21_bit_mul_04, 0, 7);
  tcase_add_loop_test(tcase, s21_bit_mul_05, 0, 7);

  tcase_add_test(tcase, s21_bit_mul_06);
  tcase_add_test(tcase, s21_bit_mul_07);
  tcase_add_test(tcase, s21_bit_mul_08);

  tcase_add_test(tcase, s21_bit_mul_09);
  tcase_add_test(tcase, s21_bit_mul_10);

  tcase_add_test(tcase, s21_bit_mul_11);
  tcase_add_test(tcase, s21_bit_mul_12);

  tcase_add_test(tcase, s21_bit_mul_13);
  tcase_add_test(tcase, s21_bit_mul_14);

  suite_add_tcase(suite, tcase);
  return suite;
}
