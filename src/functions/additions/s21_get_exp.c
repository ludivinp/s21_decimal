#include "../../s21_decimal.h"

int32_t s21_get_exp(const s21_decimal *const value) {
  int32_t result = 0;

  info_for_bit_calc value_info = {.value = (void *)value,
                                  .start_bit_index = DCML_EXP_BIT_INDEX,
                                  .bits_count = DCML_EXP_BIT_SIZE,
                                  .sign = 0};

  info_for_bit_calc result_info = {
      .value = &result, .start_bit_index = 0, .bits_count = sizeof(result) * 8};

  s21_get_bit_segment(&value_info, &result_info);

  return result;
}