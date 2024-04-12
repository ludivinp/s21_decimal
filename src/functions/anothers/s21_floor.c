#include "../../s21_bit_functions.h"
#include "../../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int value_exp = s21_get_exp(&value);

  if (result == NULL) {
    return ANOTHER_CALC_ERROR;
  } else if (value_exp != 0) {
    info_for_bit_calc info_value = {.value = &value.bits,
                                    .bits_count = DCML_MANT_BIT_SIZE,
                                    .start_bit_index = 0,
                                    .sign = 0};

    uint8_t ten = 10;
    info_for_bit_calc info_ten = {
        .value = &ten, .bits_count = 8, .start_bit_index = 0, .sign = 0};

    while (value_exp-- != 0) {
      s21_bit_div(&info_value, &info_ten, &info_value);
    }

    if (s21_is_positive(&value) == 0) {
      uint8_t one = 1;
      info_for_bit_calc info_one = {
          .value = &one, .bits_count = 8, .start_bit_index = 0, .sign = 0};

      s21_bit_add(info_value, info_one, &info_value);
    }
  }

  memcpy(result->bits, value.bits, DCML_MANT_BIT_SIZE / 8);
  s21_set_bit(result->bits, DCML_SIGN_BIT_INDEX,
              s21_get_bit(value.bits, DCML_SIGN_BIT_INDEX));

  return ANOTHER_OK;
}
