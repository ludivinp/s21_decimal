#include "../../../s21_bit_functions.h"

char s21_get_bit(const void *src, size_t bit_index) {
  return (((unsigned char *)src)[bit_index / 8] >> (bit_index % 8)) & 1;
}