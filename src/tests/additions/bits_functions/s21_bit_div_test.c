#include "../../s21_tests_runner.h"

static uint64_t array_dividend[] = {
    10, 10,     182,     127217,         212,    21821887,
    0,  121992, 1921919, 12818281122118, 127217, 1};

static uint64_t array_divisor[] = {5,     20010,        101,    83737172,
                                   17,    217218211229, 10,     18281281,
                                   29192, 218218218123, 127217, 1};

static uint32_t array_quotient[] = {2, 0, 1, 0, 12, 0, 0, 0, 65, 58, 1, 1};

START_TEST(s21_bit_div_00) {
  uint64_t dividend = array_dividend[_i];
  uint64_t divisor = array_divisor[_i];
  uint64_t quotient = 0;

  info_for_bit_calc info_dividend = {
      .value = &dividend, .bits_count = 64, .start_bit_index = 0, .sign = 0};
  info_for_bit_calc info_divisor = {
      .value = &divisor, .bits_count = 64, .start_bit_index = 0, .sign = 0};
  info_for_bit_calc info_quotient = {
      .value = &quotient, .bits_count = 64, .start_bit_index = 0, .sign = 0};

  ck_assert_int_eq(s21_bit_div(&info_dividend, &info_divisor, &info_quotient),
                   BITS_OK);
  ck_assert_int_eq(quotient, array_quotient[_i]);
}
END_TEST

START_TEST(s21_bit_div_01) {
  uint8_t dividend = 1;
  uint8_t divisor = 0;
  uint8_t quotient;

  info_for_bit_calc info_dividend = {
      .value = &dividend, .bits_count = 8, .start_bit_index = 0, .sign = 0};
  info_for_bit_calc info_divisor = {
      .value = &divisor, .bits_count = 8, .start_bit_index = 0, .sign = 0};
  info_for_bit_calc info_quotient = {
      .value = &quotient, .bits_count = 8, .start_bit_index = 0, .sign = 0};

  ck_assert_int_eq(s21_bit_div(&info_dividend, &info_divisor, &info_quotient),
                   BITS_ARITHMETIC_DIV_BY_ZERO);
}
END_TEST

START_TEST(s21_bit_div_02) {
  uint8_t dividend = 4;
  uint16_t divisor = 2;
  uint8_t quotient;

  info_for_bit_calc info_dividend = {
      .value = &dividend, .bits_count = 8, .start_bit_index = 0, .sign = 0};
  info_for_bit_calc info_divisor = {
      .value = &divisor, .bits_count = 16, .start_bit_index = 0, .sign = 0};
  info_for_bit_calc info_quotient = {
      .value = &quotient, .bits_count = 8, .start_bit_index = 0, .sign = 0};

  ck_assert_int_eq(s21_bit_div(&info_dividend, &info_divisor, &info_quotient),
                   BITS_OK);
  ck_assert_int_eq(quotient, 2);
}
END_TEST

Suite *s21_bit_div_suite() {
  TCase *tcase = tcase_create("s21_bit_div_tcase");
  Suite *suite = suite_create("s21_bit_div");

  tcase_add_loop_test(tcase, s21_bit_div_00, 0, 12);
  tcase_add_test(tcase, s21_bit_div_01);
  tcase_add_test(tcase, s21_bit_div_02);

  suite_add_tcase(suite, tcase);
  return suite;
}
