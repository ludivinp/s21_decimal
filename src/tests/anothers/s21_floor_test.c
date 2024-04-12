#include "../s21_tests_runner.h"

#define c15 0b00000000000011110000000000000000    // scale 15
#define m5 0b10000000000001010000000000000000     // minus scale 5
#define c1 0b00000000000000010000000000000000     // scale 1
#define minus 0b10000000000000000000000000000000  // minus scale 0

START_TEST(floor_test_01) {
  s21_decimal number = {{123, 456, 789, 0}};
  s21_decimal number_res = {0};
  int res = s21_floor(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], number.bits[0]);
  ck_assert_int_eq(number_res.bits[1], number.bits[1]);
  ck_assert_int_eq(number_res.bits[2], number.bits[2]);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(floor_test_02) {
  s21_decimal number = {{123, 456, 22, c1}};
  s21_decimal number_res = {0};
  int res = s21_floor(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b11001100110011001100110011011001);
  ck_assert_int_eq(number_res.bits[1], 0b110011001100110011001101100000);
  ck_assert_int_eq(number_res.bits[2], 0b10);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(floor_test_03) {
  s21_decimal number = {{(DCML_BITS_TYPE)1 << 31, 0, 989789, m5}};
  s21_decimal number_res = {{}};
  int res = s21_floor(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b1100111110010110011111001011000);
  ck_assert_int_eq(number_res.bits[1], 0b11100101110111000001111001111001);
  ck_assert_int_eq(number_res.bits[2], 0b1001);
  ck_assert_int_eq(number_res.bits[3], minus);
}
END_TEST

START_TEST(floor_test_04) {
  s21_decimal number = {{423674234, 0, 123512632, m5}};
  s21_decimal number_res = {{}};
  int res = s21_floor(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b11010100101010100010000101101101);
  ck_assert_int_eq(number_res.bits[1], 0b100000010101101000000111101100);
  ck_assert_int_eq(number_res.bits[2], 0b10011010011);
  ck_assert_int_eq(number_res.bits[3], minus);
}
END_TEST

START_TEST(floor_test_05) {
  s21_decimal number = {{1, 2, 3, c15}};
  s21_decimal number_res = {{}};
  int res = s21_floor(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0b1101100000101100);
  ck_assert_int_eq(number_res.bits[1], 0);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(floor_test_06) {
  s21_decimal number = {{0, 0, 0, c15}};
  s21_decimal number_res = {{}};
  int res = s21_floor(number, &number_res);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(number_res.bits[0], 0);
  ck_assert_int_eq(number_res.bits[1], 0);
  ck_assert_int_eq(number_res.bits[2], 0);
  ck_assert_int_eq(number_res.bits[3], 0);
}
END_TEST

START_TEST(floor_test_07) {
  s21_decimal number = {{123, 123, 123, 0}};
  int res = s21_floor(number, NULL);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *s21_floor_suite() {
  TCase *tcase = tcase_create("s21_floor_tcase");
  Suite *suite = suite_create("s21_floor");

  tcase_add_test(tcase, floor_test_01);
  tcase_add_test(tcase, floor_test_02);
  tcase_add_test(tcase, floor_test_03);
  tcase_add_test(tcase, floor_test_04);
  tcase_add_test(tcase, floor_test_05);
  tcase_add_test(tcase, floor_test_06);
  tcase_add_test(tcase, floor_test_07);

  suite_add_tcase(suite, tcase);
  return suite;
}