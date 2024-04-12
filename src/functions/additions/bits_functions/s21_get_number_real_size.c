#include "../../../s21_bit_functions.h"

size_t s21_get_number_real_size(const info_for_bit_calc value) {
  ssize_t result = -1;

  for (ssize_t i = value.bits_count - 1; i >= 0; --i) {
    if (s21_get_bit(value.value, value.start_bit_index + i)) {
      result = i;
      break;
    }
  }

  return result == -1 ? 0 : result + 1;  // index + 1 = size
}
