#ifndef COMPLEX_C
#define COMPLEX_C
#include "complex.h"
#include <math.h>



void read_comp(Complex *comp, double inputReal, double inputImaginary)	/* updates the values of the fields of the complex variable */
{
	comp->real = inputReal;
	comp->imaginary = inputImaginary;
}

void print_comp(Complex *comp)	/* print the value inside the complex variable */
{
	printf("%.2f + (%.2f)i \n\n", comp->real, comp->imaginary);
	
}

void add_comp(Complex *comp1, Complex *comp2) /* creates a new complex variable, saves the sum of the two complex variables in the fields of the new complex variable, then prints the new complex variable */
{
	Complex newComp;
	newComp.real = comp1->real + comp2->real;
	newComp.imaginary = comp1->imaginary + comp2->imaginary;
	print_comp(&newComp);
}

void sub_comp(Complex *comp1, Complex *comp2) /* prints the difference between two variables in a similar way to add_comp but with minus */
{
	Complex newComp;
	newComp.real = comp1->real - comp2->real;
	newComp.imaginary = comp1->imaginary - comp2->imaginary;
	print_comp(&newComp);
}

void mult_comp_real(Complex *comp1, double realNum) /* prints the product between a variable and a real number */
{
	Complex newComp;
	newComp.real = (comp1->real) * realNum;
	newComp.imaginary = (comp1->imaginary) * realNum;
	print_comp(&newComp);
}

void mult_comp_img(Complex *comp1, double imgNum) /* prints the product between a variable and an imaginary number */
{
	Complex newComp;
	newComp.real = -1 * (comp1->imaginary) * imgNum;
	newComp.imaginary = (comp1->real) * imgNum;
	print_comp(&newComp);
}

void mult_comp_comp(Complex *comp1, Complex *comp2) /* prints the product between two complex numbers */
{
	Complex newComp;
	newComp.real = (comp1->real) * (comp2->real) - (comp1->imaginary) * (comp2->imaginary);
	newComp.imaginary = (comp1->real) * (comp2->imaginary) + (comp1->imaginary) * (comp2->real);
	print_comp(&newComp);
}

void abs_comp(Complex *comp) /* prints the absolute value of a complex number */
{
	Complex newComp;
	newComp.real = sqrt((pow(comp->real,2)) + (pow(comp->imaginary,2)));
	newComp.imaginary = 0;
	print_comp(&newComp);
}



#endif
