#include "../../s21_decimal.h"

void s21_set_exp(s21_decimal* value, uint32_t new_exponent) {
  // s21_get_bit_segment(&new_exponent, 0,
  //                     ((unsigned char *)(&value->bits[DCML_BITS_COUNT - 1]) +
  //                      (DCML_EXP_BIT_INDEX % (sizeof(DCML_BITS_TYPE) * 8) /
  //                      8)),
  //                     DCML_EXP_BIT_SIZE > (sizeof(new_exponent) * 8)
  //                         ? (sizeof(new_exponent) * 8)
  //                         : DCML_EXP_BIT_SIZE);

  info_for_bit_calc value_info = {.value = value,
                                  .start_bit_index = DCML_EXP_BIT_INDEX,
                                  .bits_count = DCML_EXP_BIT_SIZE,
                                  .sign = 0};

  info_for_bit_calc exponent_info = {.value = &new_exponent,
                                     .start_bit_index = 0,
                                     .bits_count = sizeof(new_exponent) * 8,
                                     .sign = 0};

  s21_get_bit_segment(&exponent_info, &value_info);
}