#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  vec_int v;
  if (vec_init(&v, 2) != 0)
    return 1;

  for (int i = 0; i < 1000; i++)
    vec_append(&v, i);

  for (int i = 0; i < 1000; i++) {
    if (vec_get(&v, i) != i) {
      fprintf(stderr, "mismatch at %d\n", i);
      return 1;
    }
  }

  vec_put(&v, 500, -1);
  printf("v[500] = %d, size = %zu, capacity = %zu\n", vec_get(&v, 500), v.size,
         v.capacity);

  vec_free(&v);
  return 0;
}
