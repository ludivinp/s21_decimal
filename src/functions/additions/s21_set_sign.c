#include "../../s21_decimal.h"

void s21_set_sign(s21_decimal *value, const char minus) {
  s21_set_bit(value, DCML_SIGN_BIT_INDEX, minus);
}