#ifndef SLIDE_LINE
#define SLIDE_LINE

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1
#define LINE_SIZE   32

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void merge_right(int *line, size_t size);
void merge_left(int *line, size_t size);
void compress_right(int *line, size_t size);
void compress_left(int *line, size_t size);

#endif
