#include "../../../s21_decimal.h"

// Выводить ошибки?
void s21_equating_exp(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  info_for_bit_calc value_1_info = {.value = value_1->mantissa,
                                    .start_bit_index = 0,
                                    .bits_count = sizeof(value_1->mantissa) * 8,
                                    .sign = 0};
  info_for_bit_calc value_2_info = {.value = value_2->mantissa,
                                    .start_bit_index = 0,
                                    .bits_count = sizeof(value_2->mantissa) * 8,
                                    .sign = 0};

  char second_number = 10;
  info_for_bit_calc second_number_info = {
      .value = &second_number,
      .start_bit_index = 0,
      .bits_count = sizeof(second_number) * 8,
      .sign = 0};

  // увеличиваем минимальную экспоненту
  info_for_bit_calc *temp_info =
      value_1->exponent < value_2->exponent ? &value_1_info : &value_2_info;
  while (value_1->exponent != value_2->exponent) {
    if (s21_bit_mul(*temp_info, second_number_info, temp_info) != BITS_OK) {
      break;
    }

    if (temp_info->value == value_1->mantissa) {
      ++value_1->exponent;
    } else {
      ++value_2->exponent;
    }
  }
}