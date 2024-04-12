#include "../../s21_tests_runner.h"

START_TEST(s21_decimal_to_big_decimal_00) {
  s21_decimal test_decimal = {};
  s21_big_decimal test_big_decimal = {};

  s21_decimal_to_big_decimal(&test_decimal, &test_big_decimal);

  ck_assert_int_eq(!s21_is_positive(&test_decimal), test_big_decimal.sign);

  ck_assert_int_eq(s21_get_exp(&test_decimal), test_big_decimal.exponent);

  {
    info_for_bit_calc test_decimal_info = {
        .sign = 0,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .bits_count = DCML_MANT_BIT_SIZE,
        .value = &test_decimal.bits};
    info_for_bit_calc test_big_decimal_info = {
        .sign = 0,
        .start_bit_index = 0,
        .bits_count = sizeof(test_big_decimal.mantissa) * 8,
        .value = &test_big_decimal.mantissa};

    char result = 0;
    ck_assert_int_eq(
        s21_bits_comparison(test_decimal_info, test_big_decimal_info, &result),
        BITS_OK);

    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(s21_decimal_to_big_decimal_01) {
  s21_decimal test_decimal = {};
  s21_big_decimal test_big_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(powf(2, _i), &test_decimal),
                   CONVERTORS_OK);

  s21_decimal_to_big_decimal(&test_decimal, &test_big_decimal);

  ck_assert_int_eq(!s21_is_positive(&test_decimal), test_big_decimal.sign);

  ck_assert_int_eq(s21_get_exp(&test_decimal), test_big_decimal.exponent);

  {
    info_for_bit_calc test_decimal_info = {
        .sign = 0,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .bits_count = DCML_MANT_BIT_SIZE,
        .value = &test_decimal.bits};
    info_for_bit_calc test_big_decimal_info = {
        .sign = 0,
        .start_bit_index = 0,
        .bits_count = sizeof(test_big_decimal.mantissa) * 8,
        .value = &test_big_decimal.mantissa};

    char result = 0;
    ck_assert_int_eq(
        s21_bits_comparison(test_decimal_info, test_big_decimal_info, &result),
        BITS_OK);

    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(s21_decimal_to_big_decimal_02) {
  s21_decimal test_decimal = {};
  s21_big_decimal test_big_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(-powf(2, _i), &test_decimal),
                   CONVERTORS_OK);

  s21_decimal_to_big_decimal(&test_decimal, &test_big_decimal);

  ck_assert_int_eq(!s21_is_positive(&test_decimal), test_big_decimal.sign);

  ck_assert_int_eq(s21_get_exp(&test_decimal), test_big_decimal.exponent);

  {
    info_for_bit_calc test_decimal_info = {
        .sign = 0,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .bits_count = DCML_MANT_BIT_SIZE,
        .value = &test_decimal.bits};
    info_for_bit_calc test_big_decimal_info = {
        .sign = 0,
        .start_bit_index = 0,
        .bits_count = sizeof(test_big_decimal.mantissa) * 8,
        .value = &test_big_decimal.mantissa};

    char result = 0;
    ck_assert_int_eq(
        s21_bits_comparison(test_decimal_info, test_big_decimal_info, &result),
        BITS_OK);

    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(s21_decimal_to_big_decimal_03) {
  s21_decimal test_decimal = {};
  s21_big_decimal test_big_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(0.123, &test_decimal),
                   CONVERTORS_OK);

  s21_decimal_to_big_decimal(&test_decimal, &test_big_decimal);

  ck_assert_int_eq(!s21_is_positive(&test_decimal), test_big_decimal.sign);

  ck_assert_int_eq(s21_get_exp(&test_decimal), test_big_decimal.exponent);

  {
    info_for_bit_calc test_decimal_info = {
        .sign = 0,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .bits_count = DCML_MANT_BIT_SIZE,
        .value = &test_decimal.bits};
    info_for_bit_calc test_big_decimal_info = {
        .sign = 0,
        .start_bit_index = 0,
        .bits_count = sizeof(test_big_decimal.mantissa) * 8,
        .value = &test_big_decimal.mantissa};

    char result = 0;
    ck_assert_int_eq(
        s21_bits_comparison(test_decimal_info, test_big_decimal_info, &result),
        BITS_OK);

    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(s21_decimal_to_big_decimal_04) {
  s21_decimal test_decimal = {};
  s21_big_decimal test_big_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(-0.123, &test_decimal),
                   CONVERTORS_OK);

  s21_decimal_to_big_decimal(&test_decimal, &test_big_decimal);

  ck_assert_int_eq(!s21_is_positive(&test_decimal), test_big_decimal.sign);

  ck_assert_int_eq(s21_get_exp(&test_decimal), test_big_decimal.exponent);

  {
    info_for_bit_calc test_decimal_info = {
        .sign = 0,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .bits_count = DCML_MANT_BIT_SIZE,
        .value = &test_decimal.bits};
    info_for_bit_calc test_big_decimal_info = {
        .sign = 0,
        .start_bit_index = 0,
        .bits_count = sizeof(test_big_decimal.mantissa) * 8,
        .value = &test_big_decimal.mantissa};

    char result = 0;
    ck_assert_int_eq(
        s21_bits_comparison(test_decimal_info, test_big_decimal_info, &result),
        BITS_OK);

    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(s21_decimal_to_big_decimal_05) {
  s21_decimal test_decimal = {};
  s21_big_decimal test_big_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(123.456, &test_decimal),
                   CONVERTORS_OK);

  s21_decimal_to_big_decimal(&test_decimal, &test_big_decimal);

  ck_assert_int_eq(!s21_is_positive(&test_decimal), test_big_decimal.sign);

  ck_assert_int_eq(s21_get_exp(&test_decimal), test_big_decimal.exponent);

  {
    info_for_bit_calc test_decimal_info = {
        .sign = 0,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .bits_count = DCML_MANT_BIT_SIZE,
        .value = &test_decimal.bits};
    info_for_bit_calc test_big_decimal_info = {
        .sign = 0,
        .start_bit_index = 0,
        .bits_count = sizeof(test_big_decimal.mantissa) * 8,
        .value = &test_big_decimal.mantissa};

    char result = 0;
    ck_assert_int_eq(
        s21_bits_comparison(test_decimal_info, test_big_decimal_info, &result),
        BITS_OK);

    ck_assert_int_eq(result, 0);
  }
}
END_TEST

START_TEST(s21_decimal_to_big_decimal_06) {
  s21_decimal test_decimal = {};
  s21_big_decimal test_big_decimal = {};

  ck_assert_int_eq(s21_from_float_to_decimal(-123.456, &test_decimal),
                   CONVERTORS_OK);

  s21_decimal_to_big_decimal(&test_decimal, &test_big_decimal);

  ck_assert_int_eq(!s21_is_positive(&test_decimal), test_big_decimal.sign);

  ck_assert_int_eq(s21_get_exp(&test_decimal), test_big_decimal.exponent);

  {
    info_for_bit_calc test_decimal_info = {
        .sign = 0,
        .start_bit_index = DCML_MANT_BIT_INDEX,
        .bits_count = DCML_MANT_BIT_SIZE,
        .value = &test_decimal.bits};
    info_for_bit_calc test_big_decimal_info = {
        .sign = 0,
        .start_bit_index = 0,
        .bits_count = sizeof(test_big_decimal.mantissa) * 8,
        .value = &test_big_decimal.mantissa};

    char result = 0;
    ck_assert_int_eq(
        s21_bits_comparison(test_decimal_info, test_big_decimal_info, &result),
        BITS_OK);

    ck_assert_int_eq(result, 0);
  }
}
END_TEST

Suite *s21_decimal_to_big_decimal_suite() {
  TCase *tcase = tcase_create("s21_decimal_to_big_decimal_tcase");
  Suite *suite = suite_create("s21_decimal_to_big_decimal");

  tcase_add_test(tcase, s21_decimal_to_big_decimal_00);
  tcase_add_loop_test(tcase, s21_decimal_to_big_decimal_01, 0, 16);
  tcase_add_loop_test(tcase, s21_decimal_to_big_decimal_02, 0, 16);
  tcase_add_test(tcase, s21_decimal_to_big_decimal_03);
  tcase_add_test(tcase, s21_decimal_to_big_decimal_04);
  tcase_add_test(tcase, s21_decimal_to_big_decimal_05);
  tcase_add_test(tcase, s21_decimal_to_big_decimal_06);

  suite_add_tcase(suite, tcase);
  return suite;
}
