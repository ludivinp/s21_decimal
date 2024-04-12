#include "../../../s21_decimal.h"

void s21_big_decimal_to_decimal(s21_big_decimal *src_big_decimal,
                                s21_decimal *dst_decimal) {
  s21_removing_last_zeros(src_big_decimal);

  info_for_bit_calc src_big_decimal_info = {
      .value = src_big_decimal->mantissa,
      .bits_count = sizeof(src_big_decimal->mantissa) * 8,
      .start_bit_index = 0,
      .sign = 0};

  if (s21_get_number_real_size(src_big_decimal_info) > DCML_MANT_BIT_SIZE ||
      src_big_decimal->exponent > 28) {
    s21_bankers_rounding(src_big_decimal);
  }

  s21_zeroing_decimal(dst_decimal);

  s21_set_sign(dst_decimal, src_big_decimal->sign);

  s21_set_exp(dst_decimal, src_big_decimal->exponent);

  info_for_bit_calc dst_decimal_info = {.value = dst_decimal->bits,
                                        .bits_count = DCML_MANT_BIT_SIZE,
                                        .start_bit_index = DCML_MANT_BIT_INDEX,
                                        .sign = 0};
  s21_get_bit_segment(&src_big_decimal_info, &dst_decimal_info);
}