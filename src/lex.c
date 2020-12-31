#include "interfaces.h"


static char s_assembly[100000];
static int s_assembly_index = 0;

void append_assembly(char *s)
{
   while (*s != 0)
   {
      s_assembly[s_assembly_index] = *s;
      s++;
      s_assembly_index++;
   }
}

/*static
bool is_whitespace(const char c)
{
   if (c == '\t' || c == '\n' || c == '\r' || c == ' ')
      return true;
   else
      return false;
}


static
bool skip_whitespace(const char *buffer, int &index)
{
   while(true)
   {
      if (!is_whitespace(buffer[index]))
         break;
      index++;
   }

   return true;
}*/


int parse_compound_statement(void *char_array, int *line_num)
{
   return SUCCESS;
}


int parse_program(void *char_array, int &line_num)
{
   char line[1000];
   char_array_get_line(char_array, *line_num, line);
   if (line[0] == 'p' &&
       line[1] == 'r' &&
       line[2] == 'o' &&
       line[3] == 'g' &&
       line[4] == 'r' &&
       line[5] == 'a' &&
       line[6] == 'm' &&
       line[7] == 0)
   {
      *line_num = *line_num + 1;
      append_assembly("int main()\n");
   }
   else
   {
      return FAIL;
   }

   if (parse_compound_statement(char_array, line_num) == FAIL)
   {
      return FAIL;
   }
   return SUCCESS;
}


void parse_file(void *char_array_handle)
{
   size_t line_num;

   line_num = 0;
   while (line_num < char_array_num_lines(char_array))
   {
      if(parse_empty_line(char_array, &line_num) == FAIL)
         break;
   }

   if (parse_program(char_array, &line_num) == FAIL)
      return FAIL;
   
   while (line_num < char_array_num_lines(char_array))
   {
      if(parse_empty_line(char_array, &line_num) == FAIL)
         return FAIL;
   }

   return SUCCEED;
}


/*size_t get_num_lines(struct Char_Array buffer)
{
   size_t num_lines = 0;
   for (size_t i = 0; i < buffer.length; i++)
   {
      if (buffer.string[i] == '\n') num_lines++;
   }
   return num_lines;
}


void parse_file_into_lines(struct Char_Array buffer)
{
   struct Lines lines;
   int num_lines;
   size_t *line_begin, *line_end;

   num_lines = get_num_lines(buffer);
   
   line_begin = malloc(num_lines * sizeof(size_t));
   line_end   = malloc(num_lines * sizeof(size_t));

   get_line_indices(buffer, line_begin, line_end);

   for (size_t i = 0; i < num_lines; i++)
   {
      strip_comments(buffer.string, line_begin, line_end);
      trim_lines(buffer.string, &line_begin, &line_end);
   }

   

   // Allocate lines
   lines.line = malloc(lines.num_lines * sizeof(char*));

   // Propagate indices
   lines.line[0] = &(buffer.string[i]);
   for (int i = 0; i < buffer.length; i++)
   {
      if (buffer.string[i] == '\n')
      {
         lines.eol[line_idx] = &(buffer.string[i]);
         line_idx++;
         if (line_idx < lines.num_lines)
            lines.line[line_idx] = &(buffer.string[i+1]);
      }
   }

   // Trim lines
   for (line_idx = 0; line_idx < lines.num_lines; line_idx++)
   {
      // Trim front of line
      while(true)
      {
         if (!is_whitespace(lines.line[line_idx]))
            break;
         lines.line[line_idx]++;
      }

      // Trim back of line
      while(true)
      {
         if (!is_whitespace(lines.eol[line_idx][-1]))
            break;
         lines.eol[line_idx]--;
      }
      lines.eol[line_idx][0] = 0;
   }
}
*/
