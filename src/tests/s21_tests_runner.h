#ifndef S21_TESTS_RUNNER_H
#define S21_TESTS_RUNNER_H

#include <check.h>
#include <stdint.h>
#include <stdio.h>

#include "../s21_decimal.h"

////// Suite getters for all func

// For Additional functions
Suite *s21_set_sign_suite();
Suite *s21_integer_digits_count_suite();
Suite *s21_fractional_to_integer_suite();
Suite *s21_is_positive_suite();
Suite *s21_set_exp_suite();
Suite *s21_get_exp_suite();
Suite *s21_zeroing_decimal_suite();

//// Bits functions;
Suite *s21_bit_add_suite();
Suite *s21_bit_div_suite();
Suite *s21_bit_mul_suite();
Suite *s21_bit_sub_suite();

Suite *s21_get_bit_suite();
Suite *s21_set_bit_suite();
Suite *s21_get_bit_segment_suite();

Suite *s21_bits_comparison_suite();
Suite *s21_shift_bits_suite();
Suite *s21_zeroing_bits_suite();
Suite *s21_get_number_real_size_suite();

//// Big decimal functions
Suite *s21_decimal_to_big_decimal_suite();
Suite *s21_big_decimal_to_decimal_suite();
Suite *s21_equating_exp_suite();
Suite *s21_removing_last_zeros_suite();
Suite *s21_is_big_decimal_inf_suite();
Suite *s21_bankers_rounding_suite();
//

// For Arithmetic Operators
Suite *s21_mul_suite();
Suite *s21_div_suite();

Suite *s21_add_suite();
Suite *s21_sub_suite();
//

// For Comparison Operators
Suite *s21_is_equal_suite();
Suite *s21_is_not_equal_suite();

Suite *s21_is_greater_suite();
Suite *s21_is_greater_or_equal_suite();
Suite *s21_is_less_suite();
Suite *s21_is_less_or_equal_suite();

Suite *s21_decimal_comparison_suite();
//

// For Convertors and parsers
Suite *s21_from_float_to_decimal_suite();
Suite *s21_from_decimal_to_int_suite();
Suite *s21_from_int_to_decimal_suite();
Suite *s21_from_decimal_to_float_suite();
//

// For Another functions
Suite *s21_negate_suite();
Suite *s21_floor_suite();
Suite *s21_truncate_suite();
Suite *s21_round_suite();
//

// Run tests
size_t run_all_tests();
void add_all_suites_in_runner(SRunner **runner);
//

#endif