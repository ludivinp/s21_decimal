#ifndef S21_BIT_FUNCTIONS_H
#define S21_BIT_FUNCTIONS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct {
  void *value;
  char sign;
  size_t start_bit_index;  // 0
  size_t bits_count;  // размерность (мантиссы или любого другого)
} info_for_bit_calc;

typedef enum {
  BITS_OK = 0,
  BITS_ERROR = 1,
  BITS_ZERO_SIZE = 2,
  BITS_OVERFLOW = 3,
  BITS_ARITHMETIC_DIV_BY_ZERO = 4,
  BITS_MEMORY_ALLOCATION_FAILURE = 5
} bits_results;

typedef enum { kLess = -1, kEqual = 0, kGreater = 1 } BitComparisonResult;

//
char s21_get_bit(const void *src, size_t bit_index);
void s21_set_bit(void *src, size_t bit_index, char bit_value);

char s21_get_bit_segment(const info_for_bit_calc *src,
                         info_for_bit_calc *result_bit_segment);

void s21_zeroing_bits(void *src, size_t start_bit_index, size_t bits_count);
//

// НУЖНЫ ТЕСТЫ

size_t s21_get_number_real_size(const info_for_bit_calc value);

char s21_bit_add(info_for_bit_calc value_1, info_for_bit_calc value_2,
                 info_for_bit_calc *result);
char s21_bit_sub(info_for_bit_calc value_1, info_for_bit_calc value_2,
                 info_for_bit_calc *result);

char s21_bit_mul(info_for_bit_calc value_1, info_for_bit_calc value_2,
                 info_for_bit_calc *result);
char s21_bit_div(const info_for_bit_calc *value_1,
                 const info_for_bit_calc *value_2, info_for_bit_calc *integer);

char s21_bits_comparison(const info_for_bit_calc value_1,
                         const info_for_bit_calc value_2, char *result);

char s21_shift_bits(info_for_bit_calc *value_1, size_t number,
                    char shift_right);

#endif