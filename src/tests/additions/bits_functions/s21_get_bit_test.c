#include "../../s21_tests_runner.h"

START_TEST(s21_get_bit_00) {
  char test = 0;

  ck_assert_int_eq(0, s21_get_bit(&test, 0));
}
END_TEST

START_TEST(s21_get_bit_01) {
  char test = (int)powf(2, (float)_i);

  ck_assert_int_eq(1, s21_get_bit(&test, _i));
}
END_TEST

START_TEST(s21_get_bit_02) {
  char test = 127;

  ck_assert_int_eq(0, s21_get_bit(&test, 7));
}
END_TEST

START_TEST(s21_get_bit_03) {
  char test = 127;

  for (size_t i = 0; i < sizeof(char) * 8 - 1; ++i) {
    ck_assert_int_eq(1, s21_get_bit(&test, i));
  }
}
END_TEST

START_TEST(s21_get_bit_04) {
  long long int test = (int)powf(2, (float)_i * 8);

  ck_assert_int_eq(1, s21_get_bit(&test, _i * 8));
}
END_TEST

START_TEST(s21_get_bit_05) {
  long long int test = INT64_MIN;

  ck_assert_int_eq(1, s21_get_bit(&test, sizeof(test) * 8 - 1));
}
END_TEST

Suite *s21_get_bit_suite() {
  TCase *tcase = tcase_create("s21_get_bit_tcase");
  Suite *suite = suite_create("s21_get_bit");

  tcase_add_test(tcase, s21_get_bit_00);
  tcase_add_loop_test(tcase, s21_get_bit_01, 0, 8);
  tcase_add_test(tcase, s21_get_bit_02);
  tcase_add_test(tcase, s21_get_bit_03);
  tcase_add_loop_test(tcase, s21_get_bit_04, 0, 8);
  tcase_add_test(tcase, s21_get_bit_05);

  suite_add_tcase(suite, tcase);
  return suite;
}
