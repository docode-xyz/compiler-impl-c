#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *checked_malloc(int len) {
  void *ptr = calloc(1, len);
  if (!ptr) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }

  return ptr;
}

string String(char *str) {
  string str_ = checked_malloc(strlen(str) + 1);
  strcpy(str_, str);

  return str_;
}