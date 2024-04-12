#include "../s21_tests_runner.h"

START_TEST(s21_integer_digits_count_00) {
  const long double number = NAN;
  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), -1, 0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_01) {
  const long double number = INFINITY;
  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), -1, 0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_02) {
  const long double number = -INFINITY;
  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), -1, 0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_03) {
  const long double number = 0;
  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), 0, 0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_04) {
  const long double number = 9;
  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), 1, 0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_05) {
  const long double number = 1234567890;
  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), 10, 0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_06) {
  const long double number = -1234567890;
  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), 10, 0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_07) {
  const long double number = LDBL_MAX;
  char array[5000] = {};
  const int current_count =
      sprintf(array, "%.0Lf", number);  // .0 = без вывода дробной части

  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), current_count,
                           0.5L);
}
END_TEST

START_TEST(s21_integer_digits_count_08) {
  const long double number = LDBL_MIN;
  char array[5000] = {};
  const int current_count =
      sprintf(array, "%.0Lf",
              number) -
      1;  // .0 = без вывода дробной части и -1 чтобы убрать ноль

  ck_assert_ldouble_eq_tol(s21_integer_digits_count(number), current_count,
                           0.5L);
}
END_TEST

Suite *s21_integer_digits_count_suite() {
  TCase *tcase = tcase_create("s21_integer_digits_count_tcase");
  Suite *suite = suite_create("s21_integer_digits_count");

  tcase_add_test(tcase, s21_integer_digits_count_00);
  tcase_add_test(tcase, s21_integer_digits_count_01);
  tcase_add_test(tcase, s21_integer_digits_count_02);
  tcase_add_test(tcase, s21_integer_digits_count_03);
  tcase_add_test(tcase, s21_integer_digits_count_04);
  tcase_add_test(tcase, s21_integer_digits_count_05);
  tcase_add_test(tcase, s21_integer_digits_count_06);
  tcase_add_test(tcase, s21_integer_digits_count_07);
  tcase_add_test(tcase, s21_integer_digits_count_08);

  suite_add_tcase(suite, tcase);
  return suite;
}
