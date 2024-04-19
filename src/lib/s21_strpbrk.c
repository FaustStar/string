#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  int count = 0;
  s21_size_t length1 = s21_strlen(str1);
  s21_size_t length2 = s21_strlen(str2);
  for (s21_size_t i = 0; i < length1 && !count; i++) {
    for (s21_size_t j = 0; j < length2 && !count; j++) {
      if (str1[i] == str2[j]) {
        res = (char *)str1 + i;
        count++;
      }
    }
  }
  return res;
}