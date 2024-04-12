#include "../s21_tests_runner.h"

START_TEST(s21_decimal_comparison_00) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_01) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_sign(&test_decimal_1, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_02) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 28);
  s21_set_exp(&test_decimal_2, 28);

  s21_set_sign(&test_decimal_2, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_03) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 0);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_04) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_05) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 28);
  s21_set_exp(&test_decimal_2, 0);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_06) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 28);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_07) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_08) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_09) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_10) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_11) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_12) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_13) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_14) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_15) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}

START_TEST(s21_decimal_comparison_16) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_17) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_18) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}

START_TEST(s21_decimal_comparison_19) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 1);
  s21_set_sign(&test_decimal_2, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}

START_TEST(s21_decimal_comparison_20) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 0);
  s21_set_sign(&test_decimal_2, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_21) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 1);
  s21_set_sign(&test_decimal_2, 0);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_22) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 1);
  s21_set_sign(&test_decimal_2, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_23) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 1);
  s21_set_sign(&test_decimal_2, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_24) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 0);
  s21_set_sign(&test_decimal_2, 1);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}

START_TEST(s21_decimal_comparison_25) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 1);
  s21_set_sign(&test_decimal_2, 0);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_26) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 1);
  s21_set_exp(&test_decimal_2, 0);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 1);
  s21_set_sign(&test_decimal_2, 0);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_27) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 1);

  s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX, 1);
  s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX, 1);

  s21_set_sign(&test_decimal_1, 1);
  s21_set_sign(&test_decimal_2, 0);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}

START_TEST(s21_decimal_comparison_28) {
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

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_29) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&test_decimal_1.bits, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}
END_TEST

START_TEST(s21_decimal_comparison_30) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_set_exp(&test_decimal_1, 0);
  s21_set_exp(&test_decimal_2, 0);

  for (size_t i = 0; i < DCML_MANT_BIT_SIZE; i++) {
    s21_set_bit(&test_decimal_2.bits, DCML_MANT_BIT_INDEX + i, 1);
  }

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}
END_TEST

START_TEST(s21_decimal_comparison_31) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0, &test_decimal_1);
  s21_from_float_to_decimal(0, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_32) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0, &test_decimal_1);
  s21_from_float_to_decimal(1, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}
END_TEST

START_TEST(s21_decimal_comparison_33) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(1, &test_decimal_1);

  s21_from_float_to_decimal(0, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}
END_TEST

START_TEST(s21_decimal_comparison_34) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.123f, &test_decimal_1);
  s21_from_float_to_decimal(123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_35) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(-123.123f, &test_decimal_1);
  s21_from_float_to_decimal(-123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_36) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.123f, &test_decimal_1);
  s21_from_float_to_decimal(-123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}
END_TEST

START_TEST(s21_decimal_comparison_37) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(-123.123f, &test_decimal_1);
  s21_from_float_to_decimal(123.123f, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), -1);
}
END_TEST

START_TEST(s21_decimal_comparison_38) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(0.123456f, &test_decimal_1);
  s21_from_float_to_decimal(0.123456f, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_39) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.456f, &test_decimal_1);

  s21_from_float_to_decimal(123.456f, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 0);
}
END_TEST

START_TEST(s21_decimal_comparison_40) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(123.4567f, &test_decimal_1);

  s21_from_float_to_decimal(123.456f, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}
END_TEST

START_TEST(s21_decimal_comparison_41) {
  s21_decimal test_decimal_1 = {};
  s21_decimal test_decimal_2 = {};

  s21_from_float_to_decimal(9876543, &test_decimal_1);

  s21_from_float_to_decimal(987654, &test_decimal_2);

  ck_assert_int_eq(s21_decimal_comparison(test_decimal_1, test_decimal_2), 1);
}
END_TEST

Suite *s21_decimal_comparison_suite() {
  TCase *tcase = tcase_create("s21_decimal_comparison_tcase");
  Suite *suite = suite_create("s21_decimal_comparison");

  tcase_add_test(tcase, s21_decimal_comparison_00);
  tcase_add_test(tcase, s21_decimal_comparison_01);
  tcase_add_test(tcase, s21_decimal_comparison_02);
  tcase_add_test(tcase, s21_decimal_comparison_03);
  tcase_add_test(tcase, s21_decimal_comparison_04);
  tcase_add_test(tcase, s21_decimal_comparison_05);
  tcase_add_test(tcase, s21_decimal_comparison_06);
  tcase_add_test(tcase, s21_decimal_comparison_07);
  tcase_add_test(tcase, s21_decimal_comparison_08);
  tcase_add_test(tcase, s21_decimal_comparison_09);
  tcase_add_test(tcase, s21_decimal_comparison_10);
  tcase_add_test(tcase, s21_decimal_comparison_11);
  tcase_add_test(tcase, s21_decimal_comparison_12);
  tcase_add_test(tcase, s21_decimal_comparison_13);
  tcase_add_test(tcase, s21_decimal_comparison_14);
  tcase_add_test(tcase, s21_decimal_comparison_15);
  tcase_add_test(tcase, s21_decimal_comparison_16);
  tcase_add_test(tcase, s21_decimal_comparison_17);
  tcase_add_test(tcase, s21_decimal_comparison_18);
  tcase_add_test(tcase, s21_decimal_comparison_19);
  tcase_add_test(tcase, s21_decimal_comparison_20);
  tcase_add_test(tcase, s21_decimal_comparison_21);
  tcase_add_test(tcase, s21_decimal_comparison_22);
  tcase_add_test(tcase, s21_decimal_comparison_23);
  tcase_add_test(tcase, s21_decimal_comparison_24);
  tcase_add_test(tcase, s21_decimal_comparison_25);
  tcase_add_test(tcase, s21_decimal_comparison_26);
  tcase_add_test(tcase, s21_decimal_comparison_27);
  tcase_add_test(tcase, s21_decimal_comparison_28);
  tcase_add_test(tcase, s21_decimal_comparison_29);
  tcase_add_test(tcase, s21_decimal_comparison_30);
  tcase_add_test(tcase, s21_decimal_comparison_31);
  tcase_add_test(tcase, s21_decimal_comparison_32);
  tcase_add_test(tcase, s21_decimal_comparison_33);
  tcase_add_test(tcase, s21_decimal_comparison_34);
  tcase_add_test(tcase, s21_decimal_comparison_35);
  tcase_add_test(tcase, s21_decimal_comparison_36);
  tcase_add_test(tcase, s21_decimal_comparison_37);
  tcase_add_test(tcase, s21_decimal_comparison_38);
  tcase_add_test(tcase, s21_decimal_comparison_39);
  tcase_add_test(tcase, s21_decimal_comparison_40);
  tcase_add_test(tcase, s21_decimal_comparison_41);

  suite_add_tcase(suite, tcase);
  return suite;
}
