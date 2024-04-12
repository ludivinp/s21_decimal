#include "../../../s21_bit_functions.h"

// Оптимизировать так, чтобы сначала сравнивалось побайтово, а потом остатки
// побитово

// equal = 0, less = -1, greater = 1
char s21_bits_comparison(const info_for_bit_calc value_1,
                         const info_for_bit_calc value_2, char *result) {
  char return_result = BITS_OK;

  if (!value_1.bits_count && !value_2.bits_count) {
    return_result = BITS_ZERO_SIZE;

  } else {
    size_t max_real_size = s21_get_number_real_size(value_1);
    {
      size_t max_real_size_temp = s21_get_number_real_size(value_2);
      if (max_real_size < max_real_size_temp) {
        max_real_size = max_real_size_temp;
      }
    }

    *result = 0;
    for (size_t i = max_real_size; *result == 0 && i > 0; --i) {
      *result = (char)((i <= value_1.bits_count
                            ? s21_get_bit(value_1.value,
                                          value_1.start_bit_index + i - 1)
                            : 0) -
                       (i <= value_2.bits_count
                            ? s21_get_bit(value_2.value,
                                          value_2.start_bit_index + i - 1)
                            : 0));
    }

    if (max_real_size) {
      if (*result != 0) {
        if (value_1.sign && value_2.sign) {
          *result = -(*result);
        } else if (value_1.sign != value_2.sign) {
          *result = value_1.sign ? -1 : 1;
        }
      } else {
        *result = (char)(!value_1.sign - !value_2.sign);
      }
    }
  }

  return return_result;
}
