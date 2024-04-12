#include "../../../s21_bit_functions.h"

char s21_shift_bits(info_for_bit_calc *value_1, size_t offset,
                    char shift_right) {
  char return_result = BITS_OK;

  if (!value_1->bits_count) {
    return_result = BITS_ZERO_SIZE;

  } else if (value_1->bits_count <= offset) {
    for (size_t i = 0; i < value_1->bits_count; ++i) {
      s21_set_bit(value_1->value, value_1->start_bit_index + i, 0);
    }

  } else {
    char next_bit = 0;

    for (size_t i = 0; i < offset; ++i) {
      char current_bit = 0;

      if (shift_right) {
        for (ssize_t j = value_1->bits_count - 1 - i;
             j >= (ssize_t)value_1->start_bit_index; --j) {
          next_bit = s21_get_bit(value_1->value, j);

          s21_set_bit(value_1->value, j, current_bit);

          current_bit = next_bit;
        }

      } else {
        for (size_t j = value_1->start_bit_index + i; j < value_1->bits_count;
             ++j) {
          next_bit = s21_get_bit(value_1->value, j);

          s21_set_bit(value_1->value, j, current_bit);

          current_bit = next_bit;
        }
      }
    }
  }

  return return_result;
}
