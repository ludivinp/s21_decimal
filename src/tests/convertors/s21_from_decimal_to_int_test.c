#include "../s21_tests_runner.h"

static s21_decimal values_decimal[] = {
    {{0x7FFFFFFF, 0x00000000, 0x00000000, 0x80000000}},  // -INT_MAX (31-bit)
    {{0x00403149, 0x00000000, 0x00000000, 0x80020000}},  // -42069.21
    {{0x00000045, 0x00000000, 0x00000000, 0x80020000}},  // -0.69
    {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},  // -0
    {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // +0
    {{0x00000045, 0x00000000, 0x00000000, 0x00020000}},  // +0.69
    {{0x00403149, 0x00000000, 0x00000000, 0x00020000}},  // -42069.21
    {{0x7FFFFFFF, 0x00000000, 0x00000000, 0x00000000}},  // +INT_MAX (31-bit)
};

static int values_int[] = {-0x7FFFFFFF, -42069, 0, 0, 0, 0, 42069, 0x7FFFFFFF};

static s21_decimal big_values_decimal[] = {
    {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x80000000}},  // -UINT_MAX
    {{0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000}},  // +UINT_MAX
};

/*
 * `Decimal` fits into `int`.
 */
START_TEST(s21_from_decimal_to_int_00) {
  int result_int = 0xCCCCCCC;

  ck_assert_int_eq(s21_from_decimal_to_int(values_decimal[_i], &result_int),
                   CONVERTORS_OK);
  ck_assert_int_eq(result_int, values_int[_i]);
}
END_TEST

/*
 * `Decimal` does not fit into `int`.
 */
START_TEST(s21_from_decimal_to_int_01) {
  int result_int = 0xCCCCCCC;

  ck_assert_int_eq(s21_from_decimal_to_int(big_values_decimal[_i], &result_int),
                   CONVERTORS_ERROR);
}
END_TEST

Suite *s21_from_decimal_to_int_suite() {
  TCase *tcase = tcase_create("s21_from_decimal_to_int_tcase");
  Suite *suite = suite_create("s21_from_decimal_to_int");

  tcase_add_loop_test(tcase, s21_from_decimal_to_int_00, 0, 8);
  tcase_add_loop_test(tcase, s21_from_decimal_to_int_01, 0, 2);

  suite_add_tcase(suite, tcase);

  return suite;
}