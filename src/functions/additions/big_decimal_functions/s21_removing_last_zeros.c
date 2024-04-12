#include "../../../s21_decimal.h"

void s21_removing_last_zeros(s21_big_decimal *value) {
  if (value->exponent) {
    char second_number = 10;

    info_for_bit_calc value_info = {.value = value->mantissa,
                                    .start_bit_index = 0,
                                    .bits_count = sizeof(value->mantissa) * 8,
                                    .sign = 0};

    s21_big_decimal temp_value = *value;
    info_for_bit_calc temp_value_info = value_info;
    temp_value_info.value = temp_value.mantissa;

    info_for_bit_calc second_number_info = {
        .value = &second_number,
        .start_bit_index = 0,
        .bits_count = sizeof(second_number) * 8};

    char is_equal = 0;
    while (value->exponent) {
      if (s21_bit_div(&temp_value_info, &second_number_info,
                      &temp_value_info) != BITS_OK ||
          s21_bit_mul(temp_value_info, second_number_info, &temp_value_info) !=
              BITS_OK ||
          s21_bits_comparison(value_info, temp_value_info, &is_equal) !=
              BITS_OK ||
          is_equal) {
        break;
      }

      s21_bit_div(&value_info, &second_number_info, &value_info);
      --(value->exponent);

      temp_value = *value;
      temp_value_info.value = temp_value.mantissa;
    }
  }
}