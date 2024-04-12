#include "../s21_tests_runner.h"

START_TEST(s21_sub_00) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT),
                   0);
}
END_TEST

START_TEST(s21_sub_01) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_2, DCML_MANT_BIT_INDEX + i, 1);
  }
  s21_set_sign(&value_2, 1);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_INF);
}
END_TEST

START_TEST(s21_sub_02) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }
  s21_set_sign(&value_1, 1);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_2, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_NEG_INF);
}
END_TEST

START_TEST(s21_sub_03) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(5, &value_1);
  s21_from_float_to_decimal(10, &value_2);
  s21_from_float_to_decimal(-5, &value_4);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_04) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(-5, &value_1);
  s21_from_float_to_decimal(-10, &value_2);
  s21_from_float_to_decimal(5, &value_4);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_05) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(-5, &value_1);
  s21_from_float_to_decimal(10, &value_2);
  s21_from_float_to_decimal(-15, &value_4);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_06) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(5, &value_1);
  s21_from_float_to_decimal(-10, &value_2);
  s21_from_float_to_decimal(15, &value_4);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_07) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(10, &value_1);
  s21_from_float_to_decimal(-5, &value_2);
  s21_from_float_to_decimal(15, &value_4);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_08) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(-10, &value_1);
  s21_from_float_to_decimal(5, &value_2);
  s21_from_float_to_decimal(-15, &value_4);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_09) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(powf(2, (float)_i) - powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_10) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(-powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(-powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(-powf(2, (float)_i) - -powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_11) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(-powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(-powf(2, (float)_i) - powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_12) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(-powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(powf(2, (float)_i) - -powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_13) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_res = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);
  s21_set_exp(&value_2, 1);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_res, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_sub_14) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_res = {};

  // 79,228,162,514,264,337,593,543,950,335
  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }

  // 0.1
  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX + 1, 1);
  s21_set_exp(&value_2, 1);

  // 79,228,162,514,264,337,593,543,950,335
  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_res, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_sub(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

Suite *s21_sub_suite() {
  TCase *tcase = tcase_create("s21_sub_tcase");
  Suite *suite = suite_create("s21_sub");

  tcase_add_test(tcase, s21_sub_00);
  tcase_add_test(tcase, s21_sub_01);
  tcase_add_test(tcase, s21_sub_02);
  tcase_add_test(tcase, s21_sub_03);
  tcase_add_test(tcase, s21_sub_04);
  tcase_add_test(tcase, s21_sub_05);
  tcase_add_test(tcase, s21_sub_06);
  tcase_add_test(tcase, s21_sub_07);
  tcase_add_test(tcase, s21_sub_08);
  tcase_add_loop_test(tcase, s21_sub_09, 0, 16);
  tcase_add_loop_test(tcase, s21_sub_10, 0, 16);
  tcase_add_loop_test(tcase, s21_sub_11, 0, 16);
  tcase_add_loop_test(tcase, s21_sub_12, 0, 16);
  tcase_add_test(tcase, s21_sub_13);
  tcase_add_test(tcase, s21_sub_14);

  suite_add_tcase(suite, tcase);
  return suite;
}