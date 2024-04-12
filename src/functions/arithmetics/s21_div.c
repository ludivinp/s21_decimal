#include "../../s21_bit_functions.h"
#include "../../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_value = ARITHMETIC_OK;

  uint8_t zero = 0;
  const info_for_bit_calc kInfoZero = {&zero, 0, 0, 8};
  uint8_t ten = 10;
  const info_for_bit_calc kInfoTen = {&ten, 0, 0, 8};

  const s21_decimal kDecimalZero = {};
  const s21_decimal kDecimalOne = {{1, 0, 0, 0}};

  s21_zeroing_decimal(result);

  if (s21_is_equal(value_2, kDecimalZero) == 1) {
    return_value = ARITHMETIC_DIV_BY_ZERO;
  } else if (s21_is_equal(value_1, kDecimalZero)) {
    /*
     * Do nothing as the result is already zeroed.
     */
  } else if (s21_is_equal(value_2, kDecimalOne)) {
    memcpy(result->bits, &value_1.bits, 128 / 8);
  } else {
    s21_big_decimal big_value_1 = {0};
    s21_big_decimal big_value_2 = {0};

    s21_decimal_to_big_decimal(&value_1, &big_value_1);
    s21_decimal_to_big_decimal(&value_2, &big_value_2);

    s21_equating_exp(&big_value_1, &big_value_2);

    const s21_big_decimal kInitialDivisor = big_value_2;

    info_for_bit_calc info_dividend = {&big_value_1.mantissa, 0, 0,
                                       sizeof(big_value_1.mantissa) * 8};
    info_for_bit_calc info_divisor = {&big_value_2.mantissa, 0, 0,
                                      sizeof(big_value_2.mantissa) * 8};

    const char kResultSign =
        (s21_is_positive(&value_1) != s21_is_positive(&value_2)) ? 1 : 0;

    s21_big_decimal big_result = {0};
    big_result.sign = kResultSign;

    info_for_bit_calc info_result = {&big_result.mantissa, 0, 0,
                                     sizeof(big_result.mantissa) * 8};

    uint8_t eps = 29;
    uint8_t result_exp = 0;

    // while dividend != 0
    char compare_dividend_to_zero;
    while (s21_bits_comparison(info_dividend, kInfoZero,
                               &compare_dividend_to_zero) == BITS_OK &&
           compare_dividend_to_zero != kEqual && eps > 0) {
      // while dividend < divisor
      char compare_dividend_to_divisor;
      while (s21_bits_comparison(info_dividend, info_divisor,
                                 &compare_dividend_to_divisor) == BITS_OK &&
             compare_dividend_to_divisor == kLess && eps > 1) {
        s21_bit_mul(info_dividend, kInfoTen, &info_dividend);
        s21_bit_mul(info_result, kInfoTen, &info_result);
        ++result_exp;
        --eps;
      }

      if (eps > 0) {
        s21_big_decimal int_div_result = {0};
        info_for_bit_calc info_int_div_result = {
            &int_div_result.mantissa, 0, 0,
            sizeof(int_div_result.mantissa) * 8};

        s21_bit_div(&info_dividend, &info_divisor, &info_int_div_result);

        s21_bit_mul(info_result, kInfoTen, &info_result);
        s21_bit_add(info_result, info_int_div_result, &info_result);

        s21_bit_mul(info_divisor, info_int_div_result, &info_divisor);

        s21_bit_sub(info_dividend, info_divisor, &info_dividend);
        s21_bit_mul(info_dividend, kInfoTen, &info_dividend);

        memcpy(info_divisor.value, kInitialDivisor.mantissa,
               info_divisor.bits_count / 8);

        // while int_div_result >= 10
        char compare_int_div_result_to_ten;
        while (s21_bits_comparison(info_int_div_result, kInfoTen,
                                   &compare_int_div_result_to_ten) == BITS_OK &&
               compare_int_div_result_to_ten != kLess && eps > 1) {
          s21_bit_div(&info_int_div_result, &kInfoTen, &info_int_div_result);
          --eps;
        }

        ++result_exp;
        --eps;
      }
    }

    --result_exp;
    big_result.exponent = result_exp;

    if (s21_is_big_decimal_inf(big_result) == true) {
      if (big_result.sign == 0) {
        return_value = ARITHMETIC_INF;
      } else {
        return_value = ARITHMETIC_NEG_INF;
      }
    } else {
      s21_big_decimal_to_decimal(&big_result, result);
    }
  }

  return return_value;
}