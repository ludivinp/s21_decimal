#include "../../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return ANOTHER_CALC_ERROR;
  }

  s21_zeroing_decimal(result);
  int divider = 10;

  info_for_bit_calc test_info = {.value = &value,
                                 .start_bit_index = DCML_MANT_BIT_INDEX,
                                 .bits_count = DCML_MANT_BIT_SIZE};
  info_for_bit_calc test_info2 = {.value = &divider,
                                  .start_bit_index = 0,
                                  .bits_count = sizeof(divider) * 8};
  for (int i = 0; i < s21_get_exp(&value); i++) {
    s21_bit_div(&test_info, &test_info2, &test_info);
  }

  s21_set_exp(&value, 0);
  *result = value;
  return ANOTHER_OK;
}
