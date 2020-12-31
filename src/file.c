#include "interfaces.h"
#include <stdio.h>
#include <stdlib.h>

void read_file(char *filename, void *char_array_handle)
{
   FILE *file;
   char *raw_buffer;
   size_t length;

   // Open the file
   file = fopen(filename, "rb");
   if (file == NULL)
   {
      printf("Could not open file: %s\n", filename);
      return;
   }

   // Get file size
   fseek(file, 0, SEEK_END);
   char_array_alloc(char_array_handle, ftell(file) + 1);
   fseek(file, 0, SEEK_SET);

   // Get file contents
   raw_buffer = char_array_raw_buffer(char_array_handle);
   length = char_array_length(char_array_handle);
   fread(raw_buffer, sizeof(char), length, file);
   raw_buffer[length-1] = '\n';
   fclose(file);
}


/*bool write_file(const char *filename, const std::string &s)
{
   FILE *file;

   file = fopen(filename, "w");
   if (file == NULL)
   {
      printf("Could not open file for write: %s\n", filename);
      return false;
   }
   fprintf(file, "%s", s.c_str());
   fclose(file);

   return true;
}
*/

