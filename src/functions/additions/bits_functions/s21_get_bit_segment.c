#include "../../../s21_bit_functions.h"

char s21_get_bit_segment(const info_for_bit_calc *value,
                         info_for_bit_calc *result_bit_segment) {
  char return_result = BITS_OK;

  if (!value->bits_count && !result_bit_segment->bits_count) {
    return_result = BITS_ZERO_SIZE;

  } else {
    size_t segment_bits_count =
        value->bits_count > result_bit_segment->bits_count
            ? result_bit_segment->bits_count
            : value->bits_count;

    if (value->value > result_bit_segment->value) {
      for (size_t i = segment_bits_count; i > 0; --i) {
        s21_set_bit(result_bit_segment->value,
                    result_bit_segment->start_bit_index + i - 1,
                    s21_get_bit(value->value, value->start_bit_index + i - 1));
      }

    } else {
      for (size_t i = 0; i < segment_bits_count; ++i) {
        s21_set_bit(result_bit_segment->value,
                    result_bit_segment->start_bit_index + i,
                    s21_get_bit(value->value, value->start_bit_index + i));
      }
    }
  }

  return return_result;
}