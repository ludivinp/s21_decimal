#include "../../s21_decimal.h"

// -1 = Error
long double s21_fractional_to_integer(long double number, int precision,
                                      int *zeros_count) {
  long double result_number = 0;

  if (precision > 0 && !isinf(number) && !isnan(number)) {
    number = fabsl(number);
    number -= truncl(number);

    int zeros_in_row = 0;
    while (precision) {
      number *= 10;
      result_number = rintl((result_number * 10) + rintl(number));

      if (rintl(number) < 0.5L && rintl(number) > -0.5L) {
        ++zeros_in_row;
      } else {
        zeros_in_row = 0;
      }

      if (zeros_count && (fabsl(rintl(result_number)) < DCML_EPSILON)) {
        ++(*zeros_count);
      }

      number -= rintl(number);

      --precision;
    }

    while (zeros_in_row) {
      result_number /= 10;
      --zeros_in_row;
    }
    result_number = rintl(result_number);

  } else {
    result_number = -1;
  }

  if (fabsl(rintl(result_number)) < DCML_EPSILON && zeros_count) {
    *zeros_count = 0;
  }

  return result_number;
}
