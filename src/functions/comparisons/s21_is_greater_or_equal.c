#include "../../s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  char result = s21_decimal_comparison(value_1, value_2);

  return result == 1 || result == 0 ? COMPARISON_TRUE : COMPARISON_FALSE;
}