#include "../../../s21_bit_functions.h"

char s21_bit_mul(info_for_bit_calc value_1, info_for_bit_calc value_2,
                 info_for_bit_calc *result) {
  char return_result = BITS_OK;

  if (!value_1.bits_count && !value_2.bits_count) {
    return_result = BITS_ZERO_SIZE;

  } else {
    size_t max_bit_index = s21_get_number_real_size(value_1);

    void *temp_result = NULL;
    {
      const size_t temp_result_size =
          result->bits_count / 8 + (result->bits_count % 8 > 0 ? 1 : 0);
      temp_result = calloc(1, temp_result_size);

      if (!temp_result) {
        return_result = BITS_ERROR;
      }
    }
    info_for_bit_calc temp_result_info = {.value = temp_result,
                                          .start_bit_index = 0,
                                          .bits_count = result->bits_count,
                                          .sign = 0};

    char is_first_add = 1;
    for (ssize_t i = (ssize_t)max_bit_index - 1;
         return_result == BITS_OK && i >= 0; --i) {
      if (is_first_add) {
        is_first_add = 0;
      } else {
        if (s21_get_number_real_size(temp_result_info) >=
            temp_result_info.bits_count) {
          return_result = BITS_OVERFLOW;
          break;

        } else {
          s21_shift_bits(&temp_result_info, 1, 0);
        }
      }

      if (s21_get_bit(value_1.value, value_1.start_bit_index + i)) {
        return_result =
            s21_bit_add(temp_result_info, value_2, &temp_result_info);
      }
    }

    if (return_result == BITS_OK) {
      s21_get_bit_segment(&temp_result_info, result);
      result->sign = (char)((!value_1.sign) ^ (!value_2.sign));
    }

    free(temp_result);
  }

  return return_result;
}
