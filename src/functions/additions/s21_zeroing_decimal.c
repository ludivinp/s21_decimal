#include "../../s21_decimal.h"

s21_decimal* s21_zeroing_decimal(s21_decimal* value) {
  memset(value->bits, 0, DCML_BITS_COUNT * sizeof(DCML_BITS_TYPE));

  // s21_set_sign(value, 0);
  // s21_set_exp(value, 0);
  // s21_zeroing_bits(value->bits, DCML_MANT_BIT_INDEX, DCML_MANT_BIT_SIZE);

  return value;
}