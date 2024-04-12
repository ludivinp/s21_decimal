#include "../../s21_decimal.h"

int s21_is_positive(s21_decimal* value) {
  return !s21_get_bit(value->bits, DCML_SIGN_BIT_INDEX);
}