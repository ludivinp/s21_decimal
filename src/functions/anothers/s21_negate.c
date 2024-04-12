#include "../../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return CONVERTORS_ERROR;
  }

  s21_set_sign(&value, (char)s21_is_positive(&value));

  *result = value;

  return CONVERTORS_OK;
}
