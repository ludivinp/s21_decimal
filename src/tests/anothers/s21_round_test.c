#include "../s21_tests_runner.h"

START_TEST(s21_round_test_0) {
  s21_decimal value = {};
  s21_decimal testvalue = {};

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(0, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, testvalue.bits[3]);
}
END_TEST

START_TEST(s21_round_test_1) {
  s21_decimal value = {};
  s21_decimal testvalue = {{-1, -1, -1, 0}};

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(0, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
}
END_TEST

START_TEST(s21_round_test_2) {
  s21_decimal value = {{-1, -1, -1, 0}};
  s21_decimal testvalue = {{-1, -1, -1, 0}};

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(value.bits[0], testvalue.bits[0]);
  ck_assert_int_eq(value.bits[1], testvalue.bits[1]);
  ck_assert_int_eq(value.bits[2], testvalue.bits[2]);
}
END_TEST

START_TEST(s21_round_test_3) {
  s21_decimal value = {{0, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 1);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(0, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_4) {
  s21_decimal value = {{1, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 1);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(0, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_5) {
  s21_decimal value = {{5, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 10);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(0, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_6) {
  s21_decimal value = {{123756, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 3);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(124, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_7) {
  s21_decimal value = {{123456, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 6);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(0, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_8) {
  s21_decimal value = {{1, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_sign(&value, 1);
  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(1, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
  ck_assert_int_eq(0, s21_is_positive(&testvalue));
}
END_TEST

START_TEST(s21_round_test_9) {
  s21_decimal value = {{1, 0, 0, 0}};
  s21_decimal testvalue = {};

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(1, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
  ck_assert_int_eq(1, s21_is_positive(&testvalue));
}
END_TEST

START_TEST(s21_round_test_10) {
  s21_decimal value = {{7, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 1);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(1, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_11) {
  s21_decimal value = {{57, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 2);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(1, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_12) {
  s21_decimal value = {{176, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 2);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(2, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_13) {
  s21_decimal value = {{50, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 2);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(1, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_14) {
  s21_decimal value = {{144, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 2);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(1, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST

START_TEST(s21_round_test_15) {
  s21_decimal value = {{13, 0, 0, 0}};
  s21_decimal testvalue = {};

  s21_set_exp(&value, 2);

  ck_assert_int_eq(ANOTHER_OK, s21_round(value, &testvalue));
  ck_assert_int_eq(0, testvalue.bits[0]);
  ck_assert_int_eq(0, testvalue.bits[1]);
  ck_assert_int_eq(0, testvalue.bits[2]);
  ck_assert_int_eq(0, s21_get_exp(&testvalue));
}
END_TEST
Suite *s21_round_suite() {
  TCase *tcase = tcase_create("s21_round_tcase");
  Suite *suite = suite_create("s21_round");
  tcase_add_test(tcase, s21_round_test_0);
  tcase_add_test(tcase, s21_round_test_1);
  tcase_add_test(tcase, s21_round_test_2);
  tcase_add_test(tcase, s21_round_test_3);
  tcase_add_test(tcase, s21_round_test_4);
  tcase_add_test(tcase, s21_round_test_5);
  tcase_add_test(tcase, s21_round_test_6);
  tcase_add_test(tcase, s21_round_test_7);
  tcase_add_test(tcase, s21_round_test_8);
  tcase_add_test(tcase, s21_round_test_9);
  tcase_add_test(tcase, s21_round_test_10);
  tcase_add_test(tcase, s21_round_test_11);
  tcase_add_test(tcase, s21_round_test_12);
  tcase_add_test(tcase, s21_round_test_13);
  tcase_add_test(tcase, s21_round_test_14);
  tcase_add_test(tcase, s21_round_test_15);
  suite_add_tcase(suite, tcase);
  return suite;
}
