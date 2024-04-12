#include "../../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (!dst || isinf(src) || isnan(src) || fabsf(src) < DCML_MIN ||
      fabsf(src) > DCML_MAX) {
    return CONVERTORS_ERROR;
  }
  s21_zeroing_decimal(dst);  // обнуление/очистка decimal

  double temp_integer_number = truncf(src);  // (1230.0456 = 123)

  int decimal_exponent = 0;
  double temp_fractional_in_integer = 0;
  {  // -- ДРОБНАЯ ЧАСТЬ --
    temp_fractional_in_integer =
        s21_fractional_to_integer(src, DCML_EPSILON_10, &decimal_exponent);

    decimal_exponent += s21_integer_digits_count(temp_fractional_in_integer);
  }

  // Конкатенация целой с дробной частью (123 + 456 = 123456) в temp
  temp_integer_number *=
      powl(10, s21_integer_digits_count(temp_fractional_in_integer));
  temp_integer_number += temp_fractional_in_integer;

  // копирование нашей экспоненты в decimal
  s21_set_exp(dst, decimal_exponent);

  // Округление
  if (s21_integer_digits_count(temp_integer_number) > DCML_EPSILON_10) {
    temp_integer_number /= powl(
        10, s21_integer_digits_count(temp_integer_number) - DCML_EPSILON_10);
  }
  temp_integer_number = round(temp_integer_number);

  {  // копирование мантиссы double в наш decimal
    int temp_exp = 0;
    frexpf(temp_integer_number, &temp_exp);

    info_for_bit_calc dst_info = {.value = dst->bits,
                                  .start_bit_index = DCML_MANT_BIT_INDEX,
                                  .bits_count = DCML_MANT_BIT_SIZE};
    info_for_bit_calc temp_integer_info = {
        .value = &temp_integer_number,
        .start_bit_index =
            (sizeof(temp_integer_number) * 8 - 12) - temp_exp + 1,
        .bits_count = temp_exp - 1};  // 12 = sign + exp size у double

    s21_get_bit_segment(&temp_integer_info, &dst_info);
    s21_set_bit(dst->bits, temp_exp - 1, 1);  // у всех float
  }
  s21_set_sign(dst, src >= 0 ? false : true);  // знак

  return CONVERTORS_OK;
}
