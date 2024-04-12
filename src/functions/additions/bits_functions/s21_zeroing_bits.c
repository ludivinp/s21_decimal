#include "../../../s21_bit_functions.h"

void s21_zeroing_bits(void *src, size_t start_bit_index, size_t bits_count) {
  while (bits_count) {
    s21_set_bit(src, start_bit_index + (--bits_count), 0);
  }
}