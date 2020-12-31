#include "interfaces.h"
#include <stdio.h>

int main(int argc, char **argv)
{
   void *char_array_handle;

   if (argc != 2)
   {
      printf("Usage: ./gpl <filename>\n");
      return 1;
   }

   char_array_handle = char_array_init();

   read_file(argv[1], char_array_handle);
   if (char_array_length(char_array_handle) == 0) return 1;
   char_array_print(char_array_handle);

   char_array_delete_single_line_comments(char_array_handle);
   char_array_delete_multi_line_comments(char_array_handle);
   if (char_array_length(char_array_handle) == 0) return 1;
   char_array_print(char_array_handle);

   
   //success = parse_file(file_text, assembly);
   //if (!success) return 1;

   //write_file("out.c", get_assembly_text());
   //system("gcc out.c");

   //write_file("out.c", program_text);
   //system("gcc out.c");


   printf("Compile succeeded\n");
   return 0;
}
