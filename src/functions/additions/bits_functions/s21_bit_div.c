#include <stdlib.h>

#include "../../../s21_bit_functions.h"

typedef uint8_t byte_t;

bits_results CreateDividendAndDivisorCopies(const info_for_bit_calc *,
                                            const info_for_bit_calc *,
                                            info_for_bit_calc *,
                                            info_for_bit_calc *);

char s21_bit_div(const info_for_bit_calc *value_1,
                 const info_for_bit_calc *value_2, info_for_bit_calc *integer) {
  char return_value = BITS_OK;

  uint8_t zero = 0;
  const info_for_bit_calc kInfoZero = {&zero, 0, 0, 8};
  char compare_divisor_to_zero = 0;

  uint8_t one = 1;
  const info_for_bit_calc kInfoOne = {&one, 0, 0, 8};
  char compare_divisor_to_one = 0;

  char compare_dividend_to_divisor = 0;

  s21_bits_comparison(*value_2, kInfoZero, &compare_divisor_to_zero);
  s21_bits_comparison(*value_2, kInfoOne, &compare_divisor_to_one);
  s21_bits_comparison(*value_1, *value_2, &compare_dividend_to_divisor);

  if (compare_divisor_to_zero == kEqual) {
    return_value = BITS_ARITHMETIC_DIV_BY_ZERO;
  } else if (compare_divisor_to_one == kEqual) {
    s21_get_bit_segment(value_1, integer);
  } else if (compare_dividend_to_divisor == kEqual) {
    s21_get_bit_segment(&kInfoOne, integer);
  } else if (compare_dividend_to_divisor == kLess) {
    s21_zeroing_bits(integer->value, integer->start_bit_index,
                     integer->bits_count);
  } else {
    info_for_bit_calc info_dividend = {};
    info_for_bit_calc info_divisor = {};
    return_value = CreateDividendAndDivisorCopies(
        value_1, value_2, &info_dividend, &info_divisor);

    if (return_value == BITS_OK) {
      s21_zeroing_bits(integer->value, integer->start_bit_index,
                       integer->bits_count);

      // dividend >= divisor
      while (s21_bits_comparison(info_dividend, *value_2,
                                 &compare_dividend_to_divisor) == BITS_OK &&
             compare_dividend_to_divisor != kLess && return_value == BITS_OK) {
        size_t divisor_shift = s21_get_number_real_size(info_dividend) -
                               s21_get_number_real_size(info_divisor);
        s21_shift_bits(&info_divisor, divisor_shift, 0);

        // dividend < divisor
        if (s21_bits_comparison(info_dividend, info_divisor,
                                &compare_dividend_to_divisor) == BITS_OK &&
            compare_dividend_to_divisor == kLess && divisor_shift != 0) {
          --divisor_shift;
          s21_shift_bits(&info_divisor, 1, 1);
        }

        // dividend >= divisor
        if (s21_bits_comparison(info_dividend, info_divisor,
                                &compare_dividend_to_divisor) == BITS_OK &&
            compare_dividend_to_divisor != kLess) {
          const size_t kShiftedOneBytes = (integer->bits_count / 8) + 1;
          byte_t *shifted_one = calloc(kShiftedOneBytes, 1);

          if (shifted_one != NULL) {
            info_for_bit_calc info_shifted_one = {shifted_one, 0, 0,
                                                  kShiftedOneBytes * 8};

            s21_set_bit(shifted_one, divisor_shift, 1);
            s21_bit_add(*integer, info_shifted_one, integer);
            s21_bit_sub(info_dividend, info_divisor, &info_dividend);

            free(shifted_one);
          } else {
            return_value = BITS_MEMORY_ALLOCATION_FAILURE;
          }
        }

        memset(info_divisor.value, 0, info_divisor.bits_count / 8);
        s21_get_bit_segment(value_2, &info_divisor);
      }

      free(info_dividend.value);
      free(info_divisor.value);
    }
  }

  return return_value;
}

/*
 *  It is required to manipulate dividend and divisor value, so we must create
 *  copies of those values. Note that:
 *  - if `src_dividend` is greater than `src_divisor` then both `dest_dividend`
 *  and `dest_divisor` will have the size of `src_dividend` (and vice versa);
 *  - `start_bit_index` for destination values will be set to 0;
 *  - `s21_bit_div` must free destination values if this function succeeds.
 */
bits_results CreateDividendAndDivisorCopies(
    const info_for_bit_calc *src_dividend, const info_for_bit_calc *src_divisor,
    info_for_bit_calc *dest_dividend, info_for_bit_calc *dest_divisor) {
  bits_results return_value = BITS_OK;

  size_t byte_count;

  if (src_dividend->bits_count >= src_divisor->bits_count) {
    byte_count = (src_dividend->bits_count / 8) +
                 ((src_dividend->bits_count % 8) == 0 ? 0 : 1);
  } else {
    byte_count = (src_divisor->bits_count / 8) +
                 ((src_divisor->bits_count % 8) == 0 ? 0 : 1);
  }

  byte_t *dest_dividend_value = calloc(byte_count, 1);
  byte_t *dest_divisor_value = calloc(byte_count, 1);

  if (dest_dividend_value != NULL && dest_divisor_value != NULL) {
    dest_dividend->value = dest_dividend_value;
    dest_dividend->bits_count = byte_count * 8;
    dest_dividend->sign = src_dividend->sign;
    dest_dividend->start_bit_index = 0;
    memcpy(dest_dividend->value, src_dividend->value,
           (src_dividend->bits_count / 8) +
               ((src_dividend->bits_count % 8) == 0 ? 0 : 1));

    dest_divisor->value = dest_divisor_value;
    dest_divisor->bits_count = byte_count * 8;
    dest_divisor->sign = src_divisor->sign;
    dest_divisor->start_bit_index = 0;
    memcpy(dest_divisor->value, src_divisor->value,
           (src_divisor->bits_count / 8) +
               ((src_divisor->bits_count % 8) == 0 ? 0 : 1));
  } else {
    if (dest_dividend_value != NULL) {
      free(dest_dividend_value);
    } else if (dest_divisor_value != NULL) {
      free(dest_divisor_value);
    }

    return_value = BITS_MEMORY_ALLOCATION_FAILURE;
  }

  return return_value;
}
