#include "../../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (!dst) {
    return CONVERTORS_ERROR;
  }

  s21_zeroing_decimal(dst);

  if (src < 0) {
    s21_set_sign(dst, 1);
    src = abs(src);
  }

  info_for_bit_calc src_info = {
      .value = &src, .start_bit_index = 0, .bits_count = sizeof(src) * 8 - 1};
  info_for_bit_calc dst_info = {.value = &dst->bits,
                                .start_bit_index = 0,
                                .bits_count = DCML_MANT_BIT_SIZE};

  s21_get_bit_segment(&src_info, &dst_info);

  return CONVERTORS_OK;
}
