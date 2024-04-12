#include "../../../s21_bit_functions.h"

char s21_internal_bit_add(info_for_bit_calc value_1, info_for_bit_calc value_2,
                          info_for_bit_calc *result) {
  char return_result = BITS_OK;

  size_t max_bit_size = s21_get_number_real_size(value_1);
  {  // Находим индекс самой старшей единицы. (из двух чисел)
    const size_t temp_bit_size = s21_get_number_real_size(value_2);

    if (max_bit_size < temp_bit_size) {
      max_bit_size = temp_bit_size;
    }

    // Любой результат может быть только на 1 цифру больше
    max_bit_size += 1;
  }

  // Выбираем операцию
  char operation_flag = (value_1.sign == value_2.sign) ? 1 : 0;

  char temp_bit = 0;
  for (size_t i = 0; i < max_bit_size; ++i) {
    if (operation_flag == 1) {  // Сложение
      temp_bit =
          (char)((i < value_1.bits_count
                      ? s21_get_bit(value_1.value, value_1.start_bit_index + i)
                      : 0) +
                 (i < value_2.bits_count
                      ? s21_get_bit(value_2.value, value_2.start_bit_index + i)
                      : 0) +
                 temp_bit);

    } else {  // Вычитание
      temp_bit =
          (char)(((i < value_1.bits_count
                       ? s21_get_bit(value_1.value, value_1.start_bit_index + i)
                       : 0) +
                  2) -
                 ((i < value_2.bits_count
                       ? s21_get_bit(value_2.value, value_2.start_bit_index + i)
                       : 0) +
                  temp_bit));
    }

    if (i >= result->bits_count &&
        (operation_flag == 1 ? temp_bit : temp_bit != 2)) {
      return_result = BITS_OVERFLOW;
      break;
    }

    s21_set_bit(result->value, result->start_bit_index + i,
                (char)(temp_bit % 2));
    temp_bit = (char)((operation_flag == 1) ? temp_bit > 1 : temp_bit < 2);
  }
  return return_result;
}

char s21_bit_add(info_for_bit_calc value_1, info_for_bit_calc value_2,
                 info_for_bit_calc *result) {
  char return_result = BITS_OK;

  if (!value_1.bits_count && !value_2.bits_count && !result->bits_count) {
    return_result = BITS_ZERO_SIZE;
  } else {
    if (value_1.sign == value_2.sign) {
      result->sign = value_1.sign;

    } else {
      const char temp_sign_1 = value_1.sign;
      const char temp_sign_2 = value_2.sign;

      value_1.sign = 0;
      value_2.sign = 0;

      s21_bits_comparison(value_1, value_2, &(result->sign));

      // Чтобы правильно вычитание работало
      // Мы всегда должны вычитать из большего меньшее
      if (result->sign == -1) {
        const info_for_bit_calc temp_info = value_1;
        value_1 = value_2;
        value_2 = temp_info;

        value_1.sign = temp_sign_2;
        value_2.sign = temp_sign_1;
      } else {
        value_1.sign = temp_sign_1;
        value_2.sign = temp_sign_2;
      }

      // Определяем знак результата
      result->sign = (char)(result->sign == 0  ? 0
                            : result->sign > 0 ? temp_sign_1
                                               : temp_sign_2);
    }
    const size_t temp_result_size =
        (result->bits_count / 8) + (result->bits_count % 8 > 0 ? 1 : 0);
    void *temp_result = calloc(1, temp_result_size);
    info_for_bit_calc temp_result_info = {.value = temp_result,
                                          .start_bit_index = 0,
                                          .bits_count = result->bits_count,
                                          .sign = 0};

    if (temp_result) {
      return_result = s21_internal_bit_add(value_1, value_2, &temp_result_info);
      if (return_result == BITS_OK) {
        s21_zeroing_bits(result->value, result->start_bit_index,
                         result->bits_count);

        return_result = s21_get_bit_segment(&temp_result_info, result);
      }

      free(temp_result);
    } else {
      return_result = BITS_MEMORY_ALLOCATION_FAILURE;
    }
  }

  return return_result;
}
