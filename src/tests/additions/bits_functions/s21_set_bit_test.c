#include "../../s21_tests_runner.h"

START_TEST(s21_set_bit_00) {
  char test = 0;

  s21_set_bit(&test, 0, 0);

  ck_assert_int_eq(0, test);
}
END_TEST

START_TEST(s21_set_bit_01) {
  char test = 1;

  s21_set_bit(&test, 0, 0);

  ck_assert_int_eq(0, test);
}
END_TEST

START_TEST(s21_set_bit_02) {
  char test = 0;
  char result = (char)powf(2, (float)_i);

  s21_set_bit(&test, _i, 1);

  ck_assert_int_eq(result, test);
}
END_TEST

START_TEST(s21_set_bit_03) {
  char test = 127;

  s21_set_bit(&test, 7, 0);

  ck_assert_int_eq(test, test);
}
END_TEST

START_TEST(s21_set_bit_04) {
  char test = 0;
  char result = 0;

  for (int i = 0; i <= _i; ++i) {
    result += (char)powf(2, i);
    s21_set_bit(&test, i, 1);
  }

  ck_assert_int_eq(result, test);
}
END_TEST

START_TEST(s21_set_bit_05) {
  char test = -1;

  s21_set_bit(&test, 0, 0);

  ck_assert_int_eq(-2, test);
}
END_TEST

START_TEST(s21_set_bit_06) {
  char test = -1;

  for (int i = 0; i < 8; ++i) {
    s21_set_bit(&test, i, 0);
  }

  ck_assert_int_eq(0, test);
}
END_TEST

START_TEST(s21_set_bit_07) {
  long long int test = 0;
  long long int result = (long long int)powf(2, (float)_i * 8);

  s21_set_bit(&test, _i * 8, 1);

  ck_assert_int_eq(result, test);
}
END_TEST

START_TEST(s21_set_bit_08) {
  long long int test = 0;

  for (size_t i = 0; i < sizeof(test) * 8; ++i) {
    s21_set_bit(&test, i, 0);
  }

  ck_assert_int_eq(0, test);
}
END_TEST

Suite *s21_set_bit_suite() {
  TCase *tcase = tcase_create("s21_set_bit_tcase");
  Suite *suite = suite_create("s21_set_bit");

  tcase_add_test(tcase, s21_set_bit_00);
  tcase_add_test(tcase, s21_set_bit_01);
  tcase_add_loop_test(tcase, s21_set_bit_02, 0, 8);
  tcase_add_test(tcase, s21_set_bit_03);
  tcase_add_loop_test(tcase, s21_set_bit_04, 0, 8);
  tcase_add_test(tcase, s21_set_bit_04);
  tcase_add_test(tcase, s21_set_bit_05);
  tcase_add_test(tcase, s21_set_bit_06);
  tcase_add_loop_test(tcase, s21_set_bit_07, 0, 8);
  tcase_add_test(tcase, s21_set_bit_08);

  suite_add_tcase(suite, tcase);
  return suite;
}
