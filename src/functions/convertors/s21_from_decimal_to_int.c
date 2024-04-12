#include "../../s21_decimal.h"

/*
 * Return 0 is conversion is successful.
 * Return 1 otherwise.
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = CONVERTORS_OK;

  const size_t kIntByteCount = sizeof(*dst);

  uint8_t int_max_value[kIntByteCount];
  memset(int_max_value, 0xFF, kIntByteCount);

  info_for_bit_calc info_int_max_value = {.value = &int_max_value,
                                          .sign = 0,
                                          .bits_count = kIntByteCount * 8 - 1,
                                          .start_bit_index = 0};

  info_for_bit_calc info_src = {.value = &src.bits,
                                .sign = 0,
                                .bits_count = DCML_MANT_BIT_SIZE,
                                .start_bit_index = 0};

  uint8_t ten = 10;
  const info_for_bit_calc kInfoTen = {
      .value = &ten, .sign = 0, .bits_count = 8, .start_bit_index = 0};

  int decimal_exp = s21_get_exp(&src);

  while (decimal_exp-- != 0) {
    s21_bit_div(&info_src, &kInfoTen, &info_src);
  }

  char compare_src_to_int_max_value;
  if (s21_bits_comparison(info_src, info_int_max_value,
                          &compare_src_to_int_max_value) == BITS_OK &&
      compare_src_to_int_max_value != kGreater) {
    info_for_bit_calc info_dst = {.value = dst,
                                  .sign = 0,
                                  .bits_count = kIntByteCount * 8 - 1,
                                  .start_bit_index = 0};

    *dst = 0;
    s21_get_bit_segment(&info_src, &info_dst);

    if (!s21_is_positive(&src)) {
      *dst *= -1;
    }
  } else {
    error = CONVERTORS_ERROR;
  }

  return error;
}