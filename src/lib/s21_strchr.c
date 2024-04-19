#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  int count = 0;
  s21_size_t length = s21_strlen(str);
  for (s21_size_t i = 0; i < length && !count; i++) {
    if (str[i] == (unsigned char)c) {
      res = (char *)str + i;
      count++;
    }
  }
  return res;
}