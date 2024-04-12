#include "../s21_tests_runner.h"

START_TEST(s21_add_00) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(memcmp(&value_1.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * DCML_BITS_COUNT),
                   0);
}
END_TEST

START_TEST(s21_add_01) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }
  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_2, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_INF);
}
END_TEST

START_TEST(s21_add_02) {
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
  s21_set_sign(&value_2, 1);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_NEG_INF);
}
END_TEST

START_TEST(s21_add_03) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(5, &value_1);
  s21_from_float_to_decimal(10, &value_2);
  s21_from_float_to_decimal(15, &value_4);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_04) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(-5, &value_1);
  s21_from_float_to_decimal(-10, &value_2);
  s21_from_float_to_decimal(-15, &value_4);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_05) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(-5, &value_1);
  s21_from_float_to_decimal(10, &value_2);
  s21_from_float_to_decimal(5, &value_4);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_06) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(5, &value_1);
  s21_from_float_to_decimal(-10, &value_2);
  s21_from_float_to_decimal(-5, &value_4);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_07) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(10, &value_1);
  s21_from_float_to_decimal(-5, &value_2);
  s21_from_float_to_decimal(5, &value_4);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_08) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_4 = {};

  s21_from_float_to_decimal(-10, &value_1);
  s21_from_float_to_decimal(5, &value_2);
  s21_from_float_to_decimal(-5, &value_4);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_4), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_4), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_4.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_09) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(powf(2, (float)_i) + powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_10) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(-powf(2, (float)(float)_i), &value_1);
  s21_from_float_to_decimal(-powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(-powf(2, (float)_i) + -powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_11) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(-powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(-powf(2, (float)_i) + powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_12) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_real_res = {};

  s21_from_float_to_decimal(powf(2, (float)_i), &value_1);
  s21_from_float_to_decimal(-powf(2, (float)_i), &value_2);

  s21_from_float_to_decimal(powf(2, (float)_i) + -powf(2, (float)_i),
                            &value_real_res);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_real_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_real_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_real_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_13) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_res = {};

  for (size_t i = 1; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_res, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_14) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_res = {};

  // 79,228,162,514,264,337,593,543,950,334
  for (size_t i = 1; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }

  // 0.1
  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);
  s21_set_exp(&value_2, 1);

  //
  for (size_t i = 1; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_res, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_15) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};
  s21_decimal value_res = {};

  for (size_t i = 1; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX + 1, 1);
  s21_set_exp(&value_2, 1);

  for (size_t i = 1; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_res, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(s21_is_positive(&value_res), s21_is_positive(&value_3));
  ck_assert_int_eq(s21_get_exp(&value_res), s21_get_exp(&value_3));
  ck_assert_int_eq(memcmp(&value_res.bits, &value_3.bits,
                          sizeof(DCML_BITS_TYPE) * (DCML_BITS_COUNT - 1)),
                   0);
}
END_TEST

START_TEST(s21_add_16) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_INF);
}
END_TEST

START_TEST(s21_add_17) {
  s21_decimal value_1 = {};
  s21_decimal value_2 = {};
  s21_decimal value_3 = {};

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&value_1, DCML_MANT_BIT_INDEX + i, 1);
  }
  s21_set_sign(&value_1, 1);

  s21_set_bit(&value_2, DCML_MANT_BIT_INDEX, 1);
  s21_set_sign(&value_2, 1);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_NEG_INF);
}
END_TEST

START_TEST(s21_add_18) {
  s21_decimal value_1 = {{123456789, 0, 0, 0}};
  s21_decimal value_2 = {{123456789, 0, 0, 0}};
  s21_decimal value_3 = {};

  s21_set_exp(&value_1, 3);
  s21_set_exp(&value_2, 4);

  ck_assert_int_eq(s21_add(value_1, value_2, &value_3), ARITHMETIC_OK);

  ck_assert_int_eq(1, s21_is_positive(&value_3));
  ck_assert_int_eq(4, s21_get_exp(&value_3));
  ck_assert_int_eq(value_1.bits[0], value_2.bits[0]);
}
END_TEST

Suite *s21_add_suite() {
  TCase *tcase = tcase_create("s21_add_tcase");
  Suite *suite = suite_create("s21_add");

  tcase_add_test(tcase, s21_add_00);
  tcase_add_test(tcase, s21_add_01);
  tcase_add_test(tcase, s21_add_02);
  tcase_add_test(tcase, s21_add_03);
  tcase_add_test(tcase, s21_add_04);
  tcase_add_test(tcase, s21_add_05);
  tcase_add_test(tcase, s21_add_06);
  tcase_add_test(tcase, s21_add_07);
  tcase_add_test(tcase, s21_add_08);
  tcase_add_loop_test(tcase, s21_add_09, 0, 16);
  tcase_add_loop_test(tcase, s21_add_10, 0, 16);
  tcase_add_loop_test(tcase, s21_add_11, 0, 16);
  tcase_add_loop_test(tcase, s21_add_12, 0, 16);
  tcase_add_test(tcase, s21_add_13);
  tcase_add_test(tcase, s21_add_14);
  tcase_add_test(tcase, s21_add_15);
  tcase_add_test(tcase, s21_add_16);
  tcase_add_test(tcase, s21_add_17);
  tcase_add_test(tcase, s21_add_18);

  suite_add_tcase(suite, tcase);
  return suite;
}