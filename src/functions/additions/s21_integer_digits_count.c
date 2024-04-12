#include "../../s21_decimal.h"

// -1 = Error
int s21_integer_digits_count(long double number) {
  short int digits_count = 0;

  if (!isinf(number) && !isnan(number)) {
    number = fabsl(number);
    number = truncl(number);

    while (number > 0) {
      number = truncl(number / 10);

      ++digits_count;
    }
  } else {
    digits_count = -1;
  }

  return digits_count;
}