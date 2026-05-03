#ifndef COMPLEX_H
#define COMPLEX_H
#include <stddef.h>
#include <stdio.h>

typedef struct
{
	double real;
	double imaginary;
} Complex;

extern void read_comp(Complex *comp, double inputReal, double inputImaginary);
extern void print_comp(Complex *comp);
extern void add_comp(Complex *comp1, Complex *comp2);
extern void sub_comp(Complex *comp1, Complex *comp2);
extern void mult_comp_real(Complex *comp1, double realNum);
extern void mult_comp_img(Complex *comp1, double imgNum);
extern void mult_comp_comp(Complex *comp1, Complex *comp2);
extern void abs_comp(Complex *comp);


extern int check_double(char str[]);
extern int check_operand(char str[]);
extern int check_commas(char str[]);
extern int checkFormat1(char str[]);
extern int checkFormat2(char str[]);
extern int checkFormat3(char str[]);
extern int checkFormat4(char str[]);
extern char **split(char *str);

#endif
