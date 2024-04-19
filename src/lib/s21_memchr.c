#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;
  int count = 0;
  unsigned char *arr = (unsigned char *)str;
  s21_size_t length = s21_strlen(str);
  for (s21_size_t i = 0; (n <= length ? i < n : i < length) && !count; i++) {
    if (arr[i] == (unsigned char)c) {
      res = arr + i;
      count++;
    }
  }
  return res;
}