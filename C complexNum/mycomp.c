#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "complex.h"
#define INPUT_SIZE 100
#define COMMAND_SIZE 20
#define TOKENS_ARR_SIZE 10



int main()
{
	int i,j;
	double realInput, imaginaryInput;
	char **tokens;
	char *ptr1;
	char *ptr2;
	char str[INPUT_SIZE], commandName[COMMAND_SIZE], theRest[COMMAND_SIZE];
	char strCopy[INPUT_SIZE];
	char ch1 = '\0';
	char ch2 = '\0';	
	
	Complex A = {0, 0};
	Complex B = {0, 0};
	Complex C = {0, 0};
	Complex D = {0, 0};
	Complex E = {0, 0};
	Complex F = {0, 0};
	
	struct CompVars
	{
		char name;
		Complex *comp;
	} comps[7];
	
	comps[0].name = 'A';
    comps[0].comp = &A;
    
    comps[1].name = 'B';
    comps[1].comp = &B;
    
    comps[2].name = 'C';
    comps[2].comp = &C;
    
    comps[3].name = 'D';
    comps[3].comp = &D;
    
    comps[4].name = 'E';
    comps[4].comp = &E;
    
    comps[5].name = 'F';
    comps[5].comp = &F;
    
    comps[6].name = '#';
    comps[6].comp = NULL;
    
    printf("Welcome to complex number calculator! to use the calculator first use the read_comp format to assign numbers to one or more of the variables then use the other formats to calculate. The formats and their function (without the |'s) : |read_comp var,number,number| - assigns a complex number to a variable, |print_comp var| - prints the number assigned to the variable, |add_comp var,var| - prints the sum of two variables, |sub_comp var,var| - prints the difference of two variables");
    
	printf(" |mult_comp_real var number| - prints the product of a variable and a real number, |mult_comp_img var number| - prints the product of a variable and an imaginary number, |mult_comp_comp var var| - prints the product of two variables, |abs_comp var| - prints the absolute value of a complex variable, |stop| - stops the calculator. There are 6 variables of complex numbers - A, B, C, D, E and F.\n\n");
	
	memset(str, '\0', sizeof(str)); /* initializes str with nulls to check for illegal exits */
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL)
    {
			printf("Illegal exit - exited without using stop command");
			return 0;
	}
    printf("\nYou have entered: %s \n", str);
    theRest[0] = '\0';
    commandName[0] = '\0';
    sscanf(str, "%s %s", commandName, theRest); /* commandName will be the command name to look for, theRest is used for checking the validity of the stop command */
    
    while(!(strcmp(commandName, "stop") == 0 && theRest[0] == '\0'))
    {
    	if(strcmp(commandName, "stop") == 0 && theRest[0] != '\0')	/* checks the validity of the stop command */
    	{
    		printf("Extraneous text after end of command\n\n");
    	}
		else if(strcmp(commandName, "read_comp") == 0)
		{
			strcpy(strCopy, str);	/* creates a copy of str to send to the format checking method that includes usage of strtok which erases the content of the variable */
   			if(checkFormat1(strCopy) == 0)
   			{ 
   				tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
				tokens = split(str); /* split spilts the string by ' ' and ',' using strtok */
   				
   				sscanf(tokens[1], " %c", &ch1); /* getting the variable */
   				
	   			for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++) /* getting the index of the variable */
	   			{	
					
	   			}
   			
   				realInput = strtod(tokens[2], &ptr1);
  				imaginaryInput = strtod(tokens[3], &ptr2);
   				read_comp(comps[i].comp , realInput, imaginaryInput); /* calling the read_comp method with the given parameters */
   				free(tokens);
   			} 
			
		}
		
	
	else if(strcmp(commandName, "print_comp") == 0)
	{
		strcpy(strCopy, str); /* creating a copy because checkFormat methods use strtok */
		if(checkFormat4(strCopy) == 0)
		{ 
			tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
			tokens = split(str); /* splits the str using strtok */
			
			sscanf(tokens[1], " %c", &ch1);
			
   			for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++)
   			{	
					
   			}
			print_comp(comps[i].comp); /* calls print_comp method with the name of the variable as the parameter */
			free(tokens);
		}
		
	}
		
		else if(strcmp(commandName, "add_comp") == 0)
		{
			strcpy(strCopy, str);
			if(checkFormat2(strCopy) == 0)
	   		{
	   			tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
				tokens = split(str);
	   			
   				sscanf(tokens[1], " %c", &ch1);	/* finds two variables in this format */
   				sscanf(tokens[2], " %c", &ch2);
	   			for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++)
	   			{	
	   				
	   			}
	   			
	   			for(j=0;comps[j].comp!=NULL && (int)ch2 != (int)comps[j].name;j++)
	   			{	
	   					
	   			}
   			
	   			add_comp(comps[i].comp, comps[j].comp);	/* calls add_comp with the variables as the parameters */
	   			free(tokens);
	   		}
	
		}
		
		else if(strcmp(commandName, "sub_comp") == 0)
		{
			strcpy(strCopy, str);
			if(checkFormat2(strCopy) == 0)
	   		{		
				tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
				tokens = split(str);
	   			
   				sscanf(tokens[1], " %c", &ch1);
   				sscanf(tokens[2], " %c", &ch2);
	   			for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++)
	   			{	
	   				
	   			}
	   			
	   			for(j=0;comps[j].comp!=NULL && (int)ch2 != (int)comps[j].name;j++)
	   			{	
	   					
	   			}
	   			
	   			sub_comp(comps[i].comp, comps[j].comp); /* calls sub_comp with the variables as the parameters */
	   			free(tokens);
			}
		}
		
		else if(strcmp(commandName, "mult_comp_real") == 0)
		{
			strcpy(strCopy, str);
			if(checkFormat3(strCopy) == 0)	/* checkFormat3 checks for variable and a number */
			{
				tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
				tokens = split(str);
		   		
	   			sscanf(tokens[1], " %c", &ch1);
		   		for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++)
		   		{	
		   				
		   		}
		   		
	   			realInput = strtod(tokens[2], &ptr1);
	   			mult_comp_real(comps[i].comp, realInput); /* calls mult_comp_real with the variable and the number as the parameters */
	   			free(tokens);
	   		}
	
		}
		
		else if(strcmp(commandName, "mult_comp_img") == 0)
		{
			strcpy(strCopy, str);
			if(checkFormat3(strCopy) == 0)
			{
				tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
				tokens = split(str);
	   			
   				sscanf(tokens[1], " %c", &ch1);
	   			for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++)
	   			{	
	   				
	   			}
		   			
	   			imaginaryInput = strtod(tokens[2], &ptr1);
	   			mult_comp_img(comps[i].comp, imaginaryInput); /* calls mult_comp_img with the variable and the number as the parameters */
	   			free(tokens);
	   		}
		}
		
		else if(strcmp(commandName, "mult_comp_comp") == 0)
		{
			strcpy(strCopy, str);
			if(checkFormat2(strCopy) == 0)
			{
				tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
				tokens = split(str);
		   		
	   			sscanf(tokens[1], " %c", &ch1);
	   			sscanf(tokens[2], " %c", &ch2);
		   		for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++)
		   		{	
		   				
		   		}
		   			
		   		for(j=0;comps[j].comp!=NULL && (int)ch2 != (int)comps[j].name;j++)
		   		{	
		   					
		   		}
		   		
		   		mult_comp_comp(comps[i].comp, comps[j].comp); /* calls mult_comp_comp with the variable and the number as the parameters */
		   		free(tokens);
			}
		}
		
		else if(strcmp(commandName, "abs_comp") == 0)
		{
			strcpy(strCopy, str);
			if(checkFormat4(strCopy) == 0)
			{	
	   			tokens = calloc(TOKENS_ARR_SIZE, sizeof(char *));
			
				tokens = split(str);
	   				
				sscanf(tokens[1], " %c", &ch1);
	   			
	   			for(i=0;comps[i].comp!=NULL && (int)ch1 != (int)comps[i].name;i++)
	   			{	

	   			}
	   			
	   			abs_comp(comps[i].comp); /* calls mult_comp_real with the variable as the parameter */
	   			free(tokens);
	   		}
	
		}
		
		else if(commandName[0] == '\0')	/* empty input lines are legal */
		{
		
		
		}
		
		else	/* if the input command name does not correspond with any of the command names */
		{
			printf("Undefined command name\n\n");
		}
		
		memset(str, '\0', sizeof(str));
		printf("Enter a string: ");
		if(fgets(str, sizeof(str), stdin) == NULL)	/* checks if the user exited before using the stop command */
		{
			printf("Illegal exit - exited without using stop command");
			return 0;
		}
	    printf("\nYou have entered: %s \n", str);
		theRest[0] = '\0';
		commandName[0] = '\0';
    	sscanf(str, "%s %s", commandName, theRest);
		
	}

	return 0;
}








