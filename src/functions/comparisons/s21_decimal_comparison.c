#include "../../s21_decimal.h"

// equal = 0, less = -1, greater = 1
char s21_decimal_comparison(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal value_1_big = {};
  s21_decimal_to_big_decimal(&value_1, &value_1_big);

  s21_big_decimal value_2_big = {};
  s21_decimal_to_big_decimal(&value_2, &value_2_big);

  s21_equating_exp(&value_1_big, &value_2_big);

  info_for_bit_calc value_1_big_info = {
      .sign = value_1_big.sign,
      .start_bit_index = 0,
      .bits_count = sizeof(value_1_big.mantissa) * 8,
      .value = &value_1_big.mantissa};
  info_for_bit_calc value_2_big_info = {
      .sign = value_2_big.sign,
      .start_bit_index = 0,
      .bits_count = sizeof(value_2_big.mantissa) * 8,
      .value = &value_2_big.mantissa};

  char return_result = 0;
  s21_bits_comparison(value_1_big_info, value_2_big_info, &return_result);

  return return_result;
}