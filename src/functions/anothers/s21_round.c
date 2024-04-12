#include "../../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal* result) {
  if (!result) {
    return ANOTHER_CALC_ERROR;
  }
  s21_zeroing_decimal(result);

  s21_decimal remainder = {};
  s21_decimal int_part = {};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal measurement_error = {{5, 0, 0, 0}};
  s21_set_exp(&measurement_error, 1);

  char sign = !s21_is_positive(&value);
  s21_set_sign(&value, 0);

  s21_truncate(value, &int_part);
  s21_sub(value, int_part, &remainder);

  *result = int_part;

  if (s21_is_greater_or_equal(remainder, measurement_error)) {
    s21_add(*result, one, result);
  }

  s21_set_sign(result, sign);

  return ANOTHER_OK;
}
