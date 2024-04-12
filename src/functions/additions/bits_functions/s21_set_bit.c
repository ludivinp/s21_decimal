#include "../../../s21_bit_functions.h"

void s21_set_bit(void *src, size_t bit_index, char bit_value) {
  ((unsigned char *)src)[bit_index / 8] &= ~(1 << (bit_index % 8));
  ((unsigned char *)src)[bit_index / 8] |=
      ((bit_value != 0) << (bit_index % 8));
}