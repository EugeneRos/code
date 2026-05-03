mycomp: mycomp.o complex.o check_double.o check_operand.o check_commas.o split.o format_checks.o
	gcc -ansi -pedantic -g -Wall split.o format_checks.o check_commas.o check_operand.o check_double.o complex.o mycomp.o -o mycomp -lm

mycomp.o: mycomp.c complex.h
	gcc -c -ansi -pedantic -g -Wall mycomp.c -o mycomp.o

complex.o: complex.c complex.h
	gcc -c -ansi -pedantic -g -Wall complex.c -o complex.o

check_double.o: check_double.c 
	gcc -c -ansi -pedantic -g -Wall check_double.c -o check_double.o
	
check_operand.o: check_operand.c 
	gcc -c -ansi -pedantic -g -Wall check_operand.c -o check_operand.o
	
check_commas.o: check_commas.c 
	gcc -c -ansi -pedantic -g -Wall check_commas.c -o check_commas.o

format_checks.o: format_checks.c 
	gcc -c -ansi -pedantic -g -Wall format_checks.c -o format_checks.o
	
split.o: split.c 
	gcc -c -ansi -pedantic -g -Wall split.c -o split.o
