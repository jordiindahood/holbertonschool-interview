#ifndef HEAP_SORT
#define HEAP_SORT

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void sift_down(int *array, size_t size, size_t root, size_t n);

#endif
