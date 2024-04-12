#include "../../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_result = ARITHMETIC_OK;

  s21_big_decimal value_1_big = {};
  s21_decimal_to_big_decimal(&value_1, &value_1_big);
  s21_big_decimal value_2_big = {};
  s21_decimal_to_big_decimal(&value_2, &value_2_big);

  s21_big_decimal result_big = {};

  s21_equating_exp(&value_1_big, &value_2_big);

  info_for_bit_calc value_1_big_info = {
      .value = value_1_big.mantissa,
      .start_bit_index = 0,
      .bits_count = sizeof(value_1_big.mantissa) * 8,
      .sign = value_1_big.sign};
  info_for_bit_calc value_2_big_info = {
      .value = value_2_big.mantissa,
      .start_bit_index = 0,
      .bits_count = sizeof(value_2_big.mantissa) * 8,
      .sign = value_2_big.sign};
  info_for_bit_calc result_info = {
      .value = result_big.mantissa,
      .start_bit_index = 0,
      .bits_count = sizeof(result_big.mantissa) * 8,
      .sign = 0};

  if (s21_bit_mul(value_1_big_info, value_2_big_info, &result_info) ==
      BITS_OK) {
    {
      result_big.exponent = value_1_big.exponent + value_2_big.exponent;
      result_big.sign = result_info.sign;
    }

    if (s21_is_big_decimal_inf(result_big) == 1) {
      return_result =
          result_info.sign == 0 ? ARITHMETIC_INF : ARITHMETIC_NEG_INF;
    } else {
      s21_zeroing_decimal(result);
      s21_big_decimal_to_decimal(&result_big, result);
    }
  }

  return return_result;
}