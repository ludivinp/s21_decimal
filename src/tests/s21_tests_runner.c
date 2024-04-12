#include "s21_tests_runner.h"

int main() {
  run_all_tests();

  return 0;
}

size_t run_all_tests() {
  SRunner *runner = srunner_create(NULL);

  add_all_suites_in_runner(&runner);

  srunner_run_all(runner, CK_NORMAL);

  size_t failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count;
}

void add_all_suites_in_runner(SRunner **runner) {
  // For Additional functions
  srunner_add_suite(*runner, s21_set_sign_suite());
  srunner_add_suite(*runner, s21_integer_digits_count_suite());
  srunner_add_suite(*runner, s21_fractional_to_integer_suite());
  srunner_add_suite(*runner, s21_is_positive_suite());
  srunner_add_suite(*runner, s21_set_exp_suite());
  srunner_add_suite(*runner, s21_get_exp_suite());
  srunner_add_suite(*runner, s21_zeroing_decimal_suite());

  //// Bits functions;

  srunner_add_suite(*runner, s21_bit_add_suite());
  srunner_add_suite(*runner, s21_bit_div_suite());
  srunner_add_suite(*runner, s21_bit_mul_suite());
  srunner_add_suite(*runner, s21_bit_sub_suite());

  srunner_add_suite(*runner, s21_get_bit_suite());
  srunner_add_suite(*runner, s21_set_bit_suite());
  srunner_add_suite(*runner, s21_get_bit_segment_suite());

  srunner_add_suite(*runner, s21_bits_comparison_suite());
  srunner_add_suite(*runner, s21_shift_bits_suite());
  srunner_add_suite(*runner, s21_zeroing_bits_suite());
  srunner_add_suite(*runner, s21_get_number_real_size_suite());

  //// Big decimal functions
  srunner_add_suite(*runner, s21_decimal_to_big_decimal_suite());
  srunner_add_suite(*runner, s21_big_decimal_to_decimal_suite());
  srunner_add_suite(*runner, s21_equating_exp_suite());
  srunner_add_suite(*runner, s21_removing_last_zeros_suite());
  srunner_add_suite(*runner, s21_is_big_decimal_inf_suite());
  srunner_add_suite(*runner, s21_bankers_rounding_suite());
  //

  // For Arithmetic Operators
  srunner_add_suite(*runner, s21_mul_suite());
  srunner_add_suite(*runner, s21_div_suite());

  srunner_add_suite(*runner, s21_add_suite());
  srunner_add_suite(*runner, s21_sub_suite());
  //

  // For Comparison Operators
  srunner_add_suite(*runner, s21_is_equal_suite());
  srunner_add_suite(*runner, s21_is_not_equal_suite());

  srunner_add_suite(*runner, s21_is_greater_suite());
  srunner_add_suite(*runner, s21_is_greater_or_equal_suite());
  srunner_add_suite(*runner, s21_is_less_suite());
  srunner_add_suite(*runner, s21_is_less_or_equal_suite());

  srunner_add_suite(*runner, s21_decimal_comparison_suite());
  //

  // For Convertors and parsers
  srunner_add_suite(*runner, s21_from_float_to_decimal_suite());
  srunner_add_suite(*runner, s21_from_decimal_to_int_suite());
  srunner_add_suite(*runner, s21_from_int_to_decimal_suite());
  srunner_add_suite(*runner, s21_from_decimal_to_float_suite());

  //

  // For Another functions
  srunner_add_suite(*runner, s21_negate_suite());
  srunner_add_suite(*runner, s21_floor_suite());
  srunner_add_suite(*runner, s21_truncate_suite());
  srunner_add_suite(*runner, s21_round_suite());
  //
}