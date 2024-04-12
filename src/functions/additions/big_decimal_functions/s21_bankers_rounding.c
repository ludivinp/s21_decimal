#include <stdbool.h>

#include "../../../s21_bit_functions.h"
#include "../../../s21_decimal.h"

uint8_t GetLastDigit(s21_big_decimal *value) {
  s21_big_decimal value_copy = *value;

  info_for_bit_calc info_value = {.value = value->mantissa,
                                  .start_bit_index = 0,
                                  .bits_count = sizeof(value->mantissa) * 8,
                                  .sign = 0};

  info_for_bit_calc info_value_copy = {
      .value = value_copy.mantissa,
      .start_bit_index = 0,
      .bits_count = sizeof(value_copy.mantissa) * 8,
      .sign = 0};

  uint8_t ten = 10;
  const info_for_bit_calc kInfoTen = {&ten, 0, 0, 8};

  s21_bit_div(&info_value_copy, &kInfoTen, &info_value_copy);
  s21_bit_mul(info_value_copy, kInfoTen, &info_value_copy);
  s21_bit_sub(info_value, info_value_copy, &info_value_copy);

  return *(uint8_t *)info_value_copy.value;
}

void s21_bankers_rounding(s21_big_decimal *value) {
  uint32_t s21_decimal_max_value[DCML_BITS_COUNT - 1] = {0xFFFFFFFF, 0xFFFFFFFF,
                                                         0xFFFFFFFF};
  info_for_bit_calc info_s21_decimal_max_value = {
      .value = &s21_decimal_max_value,
      .sign = 0,
      .bits_count = sizeof(s21_decimal_max_value) * 8,
      .start_bit_index = 0};

  info_for_bit_calc info_value = {.value = &value->mantissa,
                                  .sign = 0,
                                  .bits_count = sizeof(value->mantissa) * 8,
                                  .start_bit_index = 0};

  uint8_t last_digit = 0;

  char compare_value_to_s21_decimal_max_value = 0;
  while ((s21_bits_comparison(info_value, info_s21_decimal_max_value,
                              &compare_value_to_s21_decimal_max_value) ==
              BITS_OK &&
          compare_value_to_s21_decimal_max_value == kGreater) ||
         value->exponent > 28) {
    last_digit = GetLastDigit(value);

    uint8_t ten = 10;
    const info_for_bit_calc kInfoTen = {&ten, 0, 0, 8};

    s21_bit_div(&info_value, &kInfoTen, &info_value);

    --value->exponent;
  }

  uint8_t one = 1;
  const info_for_bit_calc kInfoOne = {&one, 0, 0, 8};

  if (last_digit > 5) {
    s21_bit_add(info_value, kInfoOne, &info_value);
  } else if (last_digit == 5) {
    const bool kRoundUp = (GetLastDigit(value) % 2 == 0) ? false : true;
    if (kRoundUp == true) {
      s21_bit_add(info_value, kInfoOne, &info_value);
    }
  }
}