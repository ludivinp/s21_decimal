#include "../s21_tests_runner.h"

#define STANDARD_PRECISION 8

START_TEST(s21_fractional_to_integer_00) {
  const long double number = 123.123;
  const int precision = STANDARD_PRECISION;
  ck_assert_ldouble_eq_tol(s21_fractional_to_integer(number, precision, NULL),
                           123, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_01) {
  const long double number = NAN;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), -1, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_02) {
  const long double number = INFINITY;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), -1, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_03) {
  const long double number = -INFINITY;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), -1, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_04) {
  const long double number = 123.456;
  const int precision = -10;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), -1, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_05) {
  const long double number = 123.456;
  const int precision = 0;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), -1, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_06) {
  const long double number = 0.0;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 0, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_07) {
  const long double number = 123.0;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 0, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_08) {
  const long double number = -123.0;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 0, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_09) {
  const long double number = 0.1;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;

  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 1, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_10) {
  const long double number = 0.9;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 9, 0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_11) {
  const long double number = 0.01234567;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;

  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 1234567.0L,
      0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_12) {
  const long double number = 12345670.01234567;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;

  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 1234567.0L,
      0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_13) {
  const long double number = -0.01234567;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 1234567.0L,
      0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_14) {
  const long double number = -12345670.01234567;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;
  ck_assert_ldouble_eq_tol(
      s21_fractional_to_integer(number, precision, &zeros_count), 1234567.0L,
      0.5L);
}
END_TEST

START_TEST(s21_fractional_to_integer_15) {  //
  const long double number = 9876543210.1234567890987654321L;
  const int precision = 18;
  int zeros_count = 0;

  char array1[50] = {};
  sprintf(array1, "%.*Lf", precision, number - truncl(number));
  char array2[50] = {};
  sprintf(array2, "0.%.0Lf",
          s21_fractional_to_integer(number, precision, &zeros_count));

  ck_assert_str_eq(array1, array2);
}
END_TEST

START_TEST(s21_fractional_to_integer_16) {
  const long double number = 12345670.01234567;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;

  s21_fractional_to_integer(number, precision, &zeros_count);

  ck_assert_int_eq(zeros_count, 1);
}
END_TEST

START_TEST(s21_fractional_to_integer_17) {
  const long double number = 0.001234567;
  const int precision = STANDARD_PRECISION;
  int zeros_count = 0;

  s21_fractional_to_integer(number, precision, &zeros_count);

  ck_assert_int_eq(zeros_count, 2);
}
END_TEST

Suite *s21_fractional_to_integer_suite() {
  TCase *tcase = tcase_create("s21_fractional_to_integer_tcase");
  Suite *suite = suite_create("s21_fractional_to_integer");

  tcase_add_test(tcase, s21_fractional_to_integer_00);
  tcase_add_test(tcase, s21_fractional_to_integer_01);
  tcase_add_test(tcase, s21_fractional_to_integer_02);
  tcase_add_test(tcase, s21_fractional_to_integer_03);
  tcase_add_test(tcase, s21_fractional_to_integer_04);
  tcase_add_test(tcase, s21_fractional_to_integer_05);
  tcase_add_test(tcase, s21_fractional_to_integer_06);
  tcase_add_test(tcase, s21_fractional_to_integer_07);
  tcase_add_test(tcase, s21_fractional_to_integer_08);
  tcase_add_test(tcase, s21_fractional_to_integer_09);
  tcase_add_test(tcase, s21_fractional_to_integer_10);
  tcase_add_test(tcase, s21_fractional_to_integer_11);
  tcase_add_test(tcase, s21_fractional_to_integer_12);
  tcase_add_test(tcase, s21_fractional_to_integer_13);
  tcase_add_test(tcase, s21_fractional_to_integer_14);
  tcase_add_test(tcase, s21_fractional_to_integer_15);
  tcase_add_test(tcase, s21_fractional_to_integer_16);
  tcase_add_test(tcase, s21_fractional_to_integer_17);

  suite_add_tcase(suite, tcase);
  return suite;
}
