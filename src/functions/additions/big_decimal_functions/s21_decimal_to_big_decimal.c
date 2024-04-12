#include "../../../s21_decimal.h"

void s21_decimal_to_big_decimal(s21_decimal *src_decimal,
                                s21_big_decimal *dst_big_decimal) {
  memset(dst_big_decimal, 0, sizeof(*dst_big_decimal));

  dst_big_decimal->sign = (char)!s21_is_positive(src_decimal);

  dst_big_decimal->exponent = s21_get_exp(src_decimal);

  {
    info_for_bit_calc src_decimal_info = {
        .value = src_decimal->bits,
        .bits_count = DCML_MANT_BIT_SIZE,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .sign = 0};
    info_for_bit_calc dst_big_decimal_info = {
        .value = dst_big_decimal->mantissa,
        .bits_count = sizeof(dst_big_decimal->mantissa) * 8,
        .start_bit_index = 0,
        .sign = 0};

    s21_get_bit_segment(&src_decimal_info, &dst_big_decimal_info);
  }
}