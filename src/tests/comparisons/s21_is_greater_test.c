#include "../s21_tests_runner.h"

START_TEST(s21_is_greater_00) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_01) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_sign(&test_decimal_1, true);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_02) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 28);
  s21_set_exp(&test_decimal_2, 28);

  s21_set_sign(&test_decimal_2, true);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_03) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 0);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_04) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_05) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 28);
  s21_set_exp(&test_decimal_2, 0);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_06) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 28);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_07) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}

START_TEST(s21_is_greater_08) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}

START_TEST(s21_is_greater_09) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX + i, 1);
  }

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_10) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_11) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_12) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0, &test_decimal_1);
  s21_from_float_to_decimal(0, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_13) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0, &test_decimal_1);
  s21_from_float_to_decimal(1, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_14) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(1, &test_decimal_1);

  s21_from_float_to_decimal(0, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_15) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.123f, &test_decimal_1);
  s21_from_float_to_decimal(123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_16) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(-123.123f, &test_decimal_1);
  s21_from_float_to_decimal(-123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_17) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.123f, &test_decimal_1);
  s21_from_float_to_decimal(-123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_18) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(-123.123f, &test_decimal_1);
  s21_from_float_to_decimal(123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_19) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0.123456f, &test_decimal_1);
  s21_from_float_to_decimal(0.123456f, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_20) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.456f, &test_decimal_1);

  s21_from_float_to_decimal(123.456f, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_FALSE);
}
END_TEST

START_TEST(s21_is_greater_21) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.4567f, &test_decimal_1);

  s21_from_float_to_decimal(123.456f, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

START_TEST(s21_is_greater_22) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(9876543, &test_decimal_1);

  s21_from_float_to_decimal(987654, &test_decimal_2);

  ck_assert_int_eq(s21_is_greater(test_decimal_1, test_decimal_2),
                   COMPARISON_TRUE);
}
END_TEST

Suite *s21_is_greater_suite() {
  TCase *tcase = tcase_create("s21_is_greater_tcase");
  Suite *suite = suite_create("s21_is_greater");

  tcase_add_test(tcase, s21_is_greater_00);
  tcase_add_test(tcase, s21_is_greater_01);
  tcase_add_test(tcase, s21_is_greater_02);
  tcase_add_test(tcase, s21_is_greater_03);
  tcase_add_test(tcase, s21_is_greater_04);
  tcase_add_test(tcase, s21_is_greater_05);
  tcase_add_test(tcase, s21_is_greater_06);
  tcase_add_test(tcase, s21_is_greater_07);
  tcase_add_test(tcase, s21_is_greater_08);
  tcase_add_test(tcase, s21_is_greater_09);
  tcase_add_test(tcase, s21_is_greater_10);
  tcase_add_test(tcase, s21_is_greater_11);
  tcase_add_test(tcase, s21_is_greater_12);
  tcase_add_test(tcase, s21_is_greater_13);
  tcase_add_test(tcase, s21_is_greater_14);
  tcase_add_test(tcase, s21_is_greater_15);
  tcase_add_test(tcase, s21_is_greater_16);
  tcase_add_test(tcase, s21_is_greater_17);
  tcase_add_test(tcase, s21_is_greater_18);
  tcase_add_test(tcase, s21_is_greater_19);
  tcase_add_test(tcase, s21_is_greater_20);
  tcase_add_test(tcase, s21_is_greater_21);
  tcase_add_test(tcase, s21_is_greater_22);

  suite_add_tcase(suite, tcase);
  return suite;
}
