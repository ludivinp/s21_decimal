#include "../s21_tests_runner.h"

START_TEST(s21_mul_00) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT),
                   0);
}
END_TEST

START_TEST(s21_mul_01) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }
  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_2, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_INF);
}
END_TEST

START_TEST(s21_mul_02) {
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

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_NEG_INF);
}
END_TEST

START_TEST(s21_mul_03) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  s21_set_bit(&value_1, DCML_MANT_BIT_INDEX, 1);
  s21_set_sign(&value_1, 0);

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);
  s21_set_sign(&value_2, 0);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);
  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT),
                   0);
}
END_TEST

START_TEST(s21_mul_04) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  s21_set_bit(&value_1, DCML_MANT_BIT_INDEX, 1);
  s21_set_sign(&value_1, 1);

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);
  s21_set_sign(&value_2, 1);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  s21_set_sign(&value_1, 0);
  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT),
                   0);
}
END_TEST

START_TEST(s21_mul_05) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  s21_set_bit(&value_1, DCML_MANT_BIT_INDEX, 1);
  s21_set_exp(&value_1, 1);
  s21_set_sign(&value_1, 0);

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);
  s21_set_exp(&value_2, 0);
  s21_set_sign(&value_2, 0);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT),
                   0);
}
END_TEST

START_TEST(s21_mul_06) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  s21_set_bit(&value_1, DCML_MANT_BIT_INDEX, 1);
  s21_set_exp(&value_1, 0);
  s21_set_sign(&value_1, 0);

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);
  s21_set_exp(&value_2, 1);
  s21_set_sign(&value_2, 0);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(memcmp(&value_2.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT),
                   0);
}
END_TEST

START_TEST(s21_mul_07) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  s21_from_float_to_decimal(1, &value_1);
  s21_from_float_to_decimal(1, &value_2);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_3), 1);
  ck_assert_int_eq(s21_get_exp(&value_1), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_08) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  s21_from_float_to_decimal(-1, &value_1);
  s21_from_float_to_decimal(-1, &value_2);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_3), 1);
  ck_assert_int_eq(s21_get_exp(&value_1), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_09) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(powf(2, (float)_i) * powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_10) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(-powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(-powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(-powf(2, (float)_i) * -powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_11) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(-powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(-powf(2, (float)_i) * powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_12) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(-powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(powf(2, (float)_i) * -powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_13) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal((powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_1);
  s21_from_float_to_decimal((powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_2);

  s21_from_float_to_decimal((powf(2, (float)_i) / powf(10, (float)_i)) *
                                (powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_real_res);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_14) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(-(powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_1);
  s21_from_float_to_decimal((powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_2);

  s21_from_float_to_decimal(-(powf(2, (float)_i) / powf(10, (float)_i)) *
                                (powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_real_res);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_mul_15) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal((powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_1);
  s21_from_float_to_decimal(-(powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_2);

  s21_from_float_to_decimal((powf(2, (float)_i) / powf(10, (float)_i)) *
                                -(powf(2, (float)_i) / powf(10, (float)_i)),
                            &value_real_res);

  ck_assert_int_eq(s21_mul(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

Suite *s21_mul_suite() {
  TCase *tcase = tcase_create("s21_mul_tcase");
  Suite *suite = suite_create("s21_mul");

  tcase_add_test(tcase, s21_mul_00);
  tcase_add_test(tcase, s21_mul_01);
  tcase_add_test(tcase, s21_mul_02);
  tcase_add_test(tcase, s21_mul_03);
  tcase_add_test(tcase, s21_mul_04);
  tcase_add_test(tcase, s21_mul_05);
  tcase_add_test(tcase, s21_mul_06);
  tcase_add_test(tcase, s21_mul_07);
  tcase_add_test(tcase, s21_mul_08);
  tcase_add_loop_test(tcase, s21_mul_09, 0, 8);
  tcase_add_loop_test(tcase, s21_mul_10, 0, 8);
  tcase_add_loop_test(tcase, s21_mul_11, 0, 8);
  tcase_add_loop_test(tcase, s21_mul_12, 0, 8);

  tcase_add_loop_test(tcase, s21_mul_13, 0, 3);
  tcase_add_loop_test(tcase, s21_mul_14, 0, 3);
  tcase_add_loop_test(tcase, s21_mul_15, 0, 3);

  suite_add_tcase(suite, tcase);
  return suite;
}