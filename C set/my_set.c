#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 10
#define ENLARGE_SIZE(X) ((X) + 10)
#define IN_THE_SET 1
#define NOT_IN_THE_SET 0

int get_set(int **pp);
int print_set(int *p, int actualSetSize);


int main()
{
	int *p;
	int actualSetSize;

	p = (int *)calloc(INITIAL_SIZE, sizeof(int));	/* initializes the dynamic array */
	printf("get_set: \n\n");
	actualSetSize = get_set(&p);
	printf("\n print_set:");
	print_set(p, actualSetSize);
	free(p);
	return 0;
}

int get_set(int **pp)
{
	int *p = *pp;	/* accessing the array from the main through a pointer to pointer to the array */
	int userInput = 0;
	int setSize = INITIAL_SIZE;
	int actualSetSize = 0;
	int presentInSet;
	int *q;
	int numbersInInput;
	

	printf("Please enter the next number \n");
	numbersInInput = scanf("%d", &userInput);

	while(numbersInInput >= 1) /* numbersInInput is the value that scanf returns when it scans for decimal numbers */
	{
		
		presentInSet = NOT_IN_THE_SET;
		printf("You've entered: %d \n" , userInput);	/* checks if the number is already present in the set */
		for(q = p ; q < p + actualSetSize && presentInSet==NOT_IN_THE_SET; q++)
		{
			if(*q == userInput)
			{
				presentInSet = IN_THE_SET;
			}
		}
		
		if(actualSetSize + 1 >= setSize)	/* check if the array that holds the set needs to be increased */
		{									/* and increases the size if needed */
			q = (int *)realloc(p,(ENLARGE_SIZE(setSize))*sizeof(int));
			if(q==NULL)	/* frees the memory if there's not enough space to increase the array size */
			{
				free(p);
				printf("No space\n");
				return 0;
			}
			else
			{
				p = q;
				*pp = p;
				setSize = ENLARGE_SIZE(INITIAL_SIZE);
			}
		}
		if(presentInSet == NOT_IN_THE_SET)	/* if the number isn't present in the set it adds it */
		{
			p[actualSetSize] = userInput;
			actualSetSize++;
		}
		printf("Please enter the next number, enter EOF or a letter to print the set \n");
		numbersInInput = scanf("%d", &userInput);
	}
	
	return actualSetSize;
}

int print_set(int *p, int actualSetSize)	/* traverses through the dynamic array according to the pointer */
{											/* and the size that it gets passed as parameters */
	int i;
	printf("\n");
	for(i=0;i<actualSetSize;i++)
	{
		printf("\n %d ", p[i]);
	}
	printf("\n");
	return 0;
}

