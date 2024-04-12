#include "../../s21_tests_runner.h"

/*
 * 79,228,162,514,264,337,593,543,950,334.1
 * rounds to
 * 79,228,162,514,264,337,593,543,950,334
 *
 * 79,228,162,514,264,337,593,543,950,334.5
 * rounds to
 * 79,228,162,514,264,337,593,543,950,334
 *
 * 79,228,162,514,264,337,593,543,950,334.9
 * rounds to
 * 79,228,162,514,264,337,593,543,950,335
 *
 * 79,228,162,514,264,337,593,543,950,333.5
 * rounds to
 * 79,228,162,514,264,337,593,543,950,334
 */

static s21_big_decimal initial_values[] = {
    {.mantissa = {0xffffffed, 0xffffffff, 0xffffffff, 0x9, 0x0, 0x0, 0x0, 0x0},
     .exponent = 1},
    {.mantissa = {0xfffffff1, 0xffffffff, 0xffffffff, 0x9, 0x0, 0x0, 0x0, 0x0},
     .exponent = 1},
    {.mantissa = {0xfffffff5, 0xffffffff, 0xffffffff, 0x9, 0x0, 0x0, 0x0, 0x0},
     .exponent = 1},
    {.mantissa = {0xffffffe7, 0xffffffff, 0xffffffff, 0x9, 0x0, 0x0, 0x0, 0x0},
     .exponent = 1},
};

static s21_big_decimal result_values[] = {
    {.mantissa = {0xfffffffe, 0xffffffff, 0xffffffff, 0x0, 0x0, 0x0, 0x0, 0x0},
     .exponent = 0},
    {.mantissa = {0xfffffffe, 0xffffffff, 0xffffffff, 0x0, 0x0, 0x0, 0x0, 0x0},
     .exponent = 0},
    {.mantissa = {0xffffffff, 0xffffffff, 0xffffffff, 0x0, 0x0, 0x0, 0x0, 0x0},
     .exponent = 0},
    {.mantissa = {0xfffffffe, 0xffffffff, 0xffffffff, 0x0, 0x0, 0x0, 0x0, 0x0},
     .exponent = 0}};

START_TEST(s21_bankers_rounding_00) {
  s21_bankers_rounding(&initial_values[_i]);

  ck_assert_int_eq(initial_values[_i].mantissa[0],
                   result_values[_i].mantissa[0]);
  ck_assert_int_eq(initial_values[_i].mantissa[1],
                   result_values[_i].mantissa[1]);
  ck_assert_int_eq(initial_values[_i].mantissa[2],
                   result_values[_i].mantissa[2]);
  ck_assert_int_eq(initial_values[_i].mantissa[3],
                   result_values[_i].mantissa[3]);
  ck_assert_int_eq(initial_values[_i].mantissa[4],
                   result_values[_i].mantissa[4]);
  ck_assert_int_eq(initial_values[_i].mantissa[5],
                   result_values[_i].mantissa[5]);
  ck_assert_int_eq(initial_values[_i].mantissa[6],
                   result_values[_i].mantissa[6]);
  ck_assert_int_eq(initial_values[_i].mantissa[7],
                   result_values[_i].mantissa[7]);

  ck_assert_int_eq(initial_values[_i].exponent, result_values[_i].exponent);
}
END_TEST

Suite *s21_bankers_rounding_suite() {
  TCase *tcase = tcase_create("s21_bankers_rounding_tcase");
  Suite *suite = suite_create("s21_bankers_rounding");

  tcase_add_loop_test(tcase, s21_bankers_rounding_00, 0, 4);

  suite_add_tcase(suite, tcase);
  return suite;
}
