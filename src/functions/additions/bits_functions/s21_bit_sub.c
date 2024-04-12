#include "../../../s21_bit_functions.h"

////
// Два положительных = меняем знак второго числа на противоположный
// 10 - 5  =  5  = 10 + -5
// 5  - 10 = -5  = 5  + -10
// Два отрицательных = меняем знак второго числа на противоположный
// -10 - -5  =  -5  = -10 + 5
// -5  - -10 =   5  = -5  + 10

// Разные + и - = Делаем оба числа положительными
// 10 - -5  =  15  = 10 + 5
// 5  - -10 =  15  = 5  + 10

// Разные - и + = Делаем оба числа отрицательными
// -10 - 5  =  -15  = -10 + -5
// -5  - 10 =  -15  = -5  + -10
////

char s21_bit_sub(info_for_bit_calc value_1, info_for_bit_calc value_2,
                 info_for_bit_calc *result) {
  char return_result = BITS_OK;

  if (!value_1.bits_count && !value_2.bits_count && !result->bits_count) {
    return_result = BITS_ZERO_SIZE;
  } else {
    if (value_1.sign == value_2.sign) {
      value_2.sign = (char)!value_2.sign;
    } else {
      value_2.sign = value_1.sign;
    }

    return_result = s21_bit_add(value_1, value_2, result);
  }

  return return_result;
}
