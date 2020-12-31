#include "interfaces.h"
#include <stdio.h>
#include <stdlib.h>

struct Char_Array
{
   uint64_t length;
   char *buffer;
};


void * char_array_init()
{
   struct Char_Array *char_array;

   char_array = malloc(sizeof(struct Char_Array));
   char_array->length = 0;
   char_array->buffer = NULL;

   return char_array;
}

void char_array_alloc(void *handle, size_t length)
{
   struct Char_Array *char_array = (struct Char_Array *) handle;
   char_array->length = length;
   char_array->buffer = malloc(length);
}

char * char_array_raw_buffer(void *handle)
{
   struct Char_Array *char_array = (struct Char_Array *) handle;
   return char_array->buffer;
}

size_t char_array_length(void *handle)
{
   struct Char_Array *char_array = (struct Char_Array *) handle;
   return char_array->length;
}

void char_array_print(void *handle)
{
   struct Char_Array *char_array = (struct Char_Array *) handle;
   char last_char;
   int length;

   length = char_array->length;
   last_char = char_array->buffer[length - 1];
   char_array->buffer[length - 1] = 0;
   printf("%s\n", char_array->buffer);
   char_array->buffer[length - 1] = last_char;
}

void char_array_delete_single_line_comments(void *handle)
{
   struct Char_Array *char_array = (struct Char_Array *) handle;
   enum { NONE, COMMENT };
   int state;

   state = NONE;
   for (size_t i = 0; i < char_array->length; i++)
   {
      if (state == NONE)
      {
         if (i+1 < char_array->length &&
             char_array->buffer[i] == '/' && 
             char_array->buffer[i+1] == '/')
         {
            state = COMMENT;
            char_array->buffer[i] = ' ';
         }
      }
      else if (state == COMMENT)
      {
         if (char_array->buffer[i] == '\r' || 
             char_array->buffer[i] == '\n')
         {
            state = NONE;
         }
         else
         {
            char_array->buffer[i] = ' ';
         }
      }
   }
}


void char_array_delete_multi_line_comments(void *handle)
{
   struct Char_Array *char_array = (struct Char_Array *) handle;
   enum { NONE, COMMENT };
   int state;

   state = NONE;
   for (size_t i = 0; i < char_array->length; i++)
   {
      if (state == NONE)
      {
         if (i+1 < char_array->length &&
             char_array->buffer[i] == '/' && 
             char_array->buffer[i+1] == '*')
         {
            state = COMMENT;
            char_array->buffer[i] = ' ';
         }
      }
      else if (state == COMMENT)
      {
         if (i+1 < char_array->length &&
             char_array->buffer[i] == '*' && 
             char_array->buffer[i+1] == '/')
         {
            char_array->buffer[i] = ' ';
            char_array->buffer[i+1] = ' ';
            state = NONE;
         }
         else
         {
            char_array->buffer[i] = ' ';
         }
      }
   }

   if (state == COMMENT) char_array->length = 0;
}


void char_array_process_lines(void *handle)
{

}

