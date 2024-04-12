#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "s21_bit_functions.h"

#define DCML_EPSILON_10 7
#define DCML_EPSILON 1e-7

#define DCML_MAX 79228162514264337593543950335.0L
#define DCML_MIN 1e-28

#define DCML_MANT_BIT_INDEX 0
#define DCML_MANT_BIT_SIZE (sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1) * 8)

#define DCML_EXP_BIT_INDEX \
  (sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1) * 8 + 16)
#define DCML_EXP_BIT_SIZE 8

#define DCML_SIGN_BIT_INDEX (sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT * 8 - 1)

#define DCML_BITS_TYPE uint32_t
#define DCML_BITS_COUNT 4
typedef struct {
  DCML_BITS_TYPE bits[DCML_BITS_COUNT];
} s21_decimal;

// For arithmetic
typedef struct {
  char sign;
  DCML_BITS_TYPE exponent;

  DCML_BITS_TYPE  // Cringe
      mantissa[(((DCML_MANT_BIT_SIZE / 8) + 0) / sizeof(DCML_BITS_TYPE) + 1) *
               2];

} s21_big_decimal;

// Errors
enum arithmetics_results {
  ARITHMETIC_OK = 0,
  ARITHMETIC_INF = 1,
  ARITHMETIC_NEG_INF = 2,
  ARITHMETIC_DIV_BY_ZERO = 3,
};
enum comparison_results {
  COMPARISON_FALSE = 0,
  COMPARISON_TRUE = 1,
};
enum convertors_results {
  CONVERTORS_OK = 0,
  CONVERTORS_ERROR = 1,
};
enum another_results {
  ANOTHER_OK = 0,
  ANOTHER_CALC_ERROR = 1,
};
//

// Arithmetic Operators
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
//

// Comparison Operators
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

char s21_decimal_comparison(s21_decimal value_1, s21_decimal value_2);
//

// Convertors and parsers
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
//

// Another functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
//

// Additional functions
int s21_integer_digits_count(long double number);
long double s21_fractional_to_integer(long double number, int precision,
                                      int *zeros_count);

void s21_set_sign(s21_decimal *value, char minus);
int s21_is_positive(s21_decimal *value);

int s21_get_exp(const s21_decimal *value);
void s21_set_exp(s21_decimal *value, uint32_t new_exponent);

s21_decimal *s21_zeroing_decimal(s21_decimal *value);

// Big decimal func
void s21_decimal_to_big_decimal(s21_decimal *src_decimal,
                                s21_big_decimal *dst_big_decimal);
void s21_big_decimal_to_decimal(s21_big_decimal *src_big_decimal,
                                s21_decimal *dst_decimal);

void s21_equating_exp(s21_big_decimal *value_1, s21_big_decimal *value_2);

void s21_removing_last_zeros(s21_big_decimal *value);

char s21_is_big_decimal_inf(s21_big_decimal value_1);

void s21_bankers_rounding(s21_big_decimal *value);

#endif