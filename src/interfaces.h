#pragma once
#include <stdint.h>

void read_file(char *filename, void *char_array_handle);

void * char_array_init();
void char_array_alloc(void *handle, size_t length);
char * char_array_raw_buffer(void *handle);
size_t char_array_length(void *handle);
void char_array_print(void *handle);
void char_array_delete_single_line_comments(void *handle);
void char_array_delete_multi_line_comments(void *handle);
