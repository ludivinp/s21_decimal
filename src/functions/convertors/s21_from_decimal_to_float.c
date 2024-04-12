#include <math.h>

#include "../../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int return_value = CONVERTORS_OK;

  if (dst != NULL) {
    uint8_t float_max[23 / 8 + 1];
    memset(float_max, 0xFF, 23 / 8 + 1);
    info_for_bit_calc info_float_max = {
        .value = float_max, .bits_count = 23, .start_bit_index = 0, .sign = 0};

    int src_int;
    const int kOverflow = s21_from_decimal_to_int(src, &src_int);
    info_for_bit_calc info_src_int = {.value = &src_int,
                                      .bits_count = sizeof(src_int) * 8 - 1,
                                      .start_bit_index = 0,
                                      .sign = 0};
    if (src_int < 0) {
      src_int *= -1;
    }

    char compare_src_int_to_float_max;
    if (kOverflow == 1 ||
        (s21_bits_comparison(info_src_int, info_float_max,
                             &compare_src_int_to_float_max) == BITS_OK &&
         compare_src_int_to_float_max == kGreater)) {
      return_value = CONVERTORS_ERROR;
    } else {
      long double result = 0;

      for (size_t i = 0; i < DCML_MANT_BIT_SIZE; ++i) {
        if (s21_get_bit(src.bits, i) != 0) {
          result += powl(2, (long double)i);
        }
      }

      size_t src_exp = s21_get_exp(&src);

      while (src_exp-- != 0) {
        result /= 10;
      }

      if (!s21_is_positive(&src)) {
        result *= -1;
      }

      *dst = (float)result;
    }
  } else {
    return_value = CONVERTORS_ERROR;
  }

  return return_value;
}
