#include "../../../s21_decimal.h"

// Выводить ошибки?
char s21_is_big_decimal_inf(s21_big_decimal value_1) {
  info_for_bit_calc value_1_info = {.value = value_1.mantissa,
                                    .start_bit_index = 0,
                                    .bits_count = sizeof(value_1.mantissa) * 8,
                                    .sign = 0};

  char second_number = 10;
  info_for_bit_calc second_number_info = {
      .value = &second_number,
      .start_bit_index = 0,
      .bits_count = sizeof(second_number) * 8,
      .sign = 0};

  while (value_1.exponent && s21_bit_div(&value_1_info, &second_number_info,
                                         &value_1_info) == BITS_OK) {
    --value_1.exponent;
  }

  return (char)(s21_get_number_real_size(value_1_info) > DCML_MANT_BIT_SIZE
                    ? 1
                    : 0);
}