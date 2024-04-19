#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  s21_size_t length = s21_strlen(str);
  for (s21_size_t i = 0; i < length; i++) {
    if (str[i] == (unsigned char)c) {
      res = (char *)str + i;
    }
  }
  return res;
}