
FLAGS = -Wall

.PHONY : program
program:
	gcc $(FLAGS) src/*.c -o gpl.exe
