#include "../../s21_decimal.h"

/* Return 0 if false.
   Return 1 otherwise.
   Note that bit representation differentiates negative and positive zero.
   These values are treated as being equal. */
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;

  // We explicitly check if both values are `0` because `0` values may still
  // contain scale factors and sign which do not matter in such case.
  const bool kBothValuesAreZero =
      value_1.bits[0] == 0 && value_1.bits[1] == 0 && value_1.bits[2] == 0 &&
      value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0;

  if (true == kBothValuesAreZero) {
    result = 1;
  } else {
    const bool kValuesAreEqual = value_1.bits[0] == value_2.bits[0] &&
                                 value_1.bits[1] == value_2.bits[1] &&
                                 value_1.bits[2] == value_2.bits[2] &&
                                 value_1.bits[3] == value_2.bits[3];
    if (true == kValuesAreEqual) {
      result = 1;
    }
  }

  return result;
}