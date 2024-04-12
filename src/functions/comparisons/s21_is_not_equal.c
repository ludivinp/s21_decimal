#include "../../s21_decimal.h"

/* Return 0 if false.
   Return 1 otherwise.
   Note that bit representation differentiates negative and positive zero.
   These values are treated as being equal. */
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return !s21_is_equal(value_1, value_2);
}