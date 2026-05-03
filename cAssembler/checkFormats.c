#include "assembler.h"
#define VALID 1
#define NOT_VALID 0


int checkFormat1(char **tokens, int n, int lineNumber, item *Labels)
{
	int isValid = VALID;
	int i;
	for(i=n;tokens[i]!='\0';i++)	/* checks whether the number of operands is correct for the operation */
	{
		
	}
	if(i-n != 3)
	{
		printf("Invalid amount of arguments for the operation, line %d \n", lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+1] == '\0')		/* if there's not enough operands returns the result and continues to check the next line */
	{
		return isValid;
	}
	if(checkOperand(tokens[n+1]) == NOT_VALID)		/* checks whether the operand is legal - number, register or label */
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+1], lineNumber);
		isValid = NOT_VALID;
	}
	if(checkOperand(tokens[n+2]) == NOT_VALID)
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+2], lineNumber);
		isValid = NOT_VALID;
	}
	if(containsOnlyNumbers(tokens[n+2]) == 1)	/* checks if the destination operand is a number which it can't be */
	{
		printf("The destination operand for the operator can't be a number: %s, line %d \n", tokens[n+2],lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+1][0] == '@')
	{
		if(checkRegisters(tokens[n+1]) == 0)	/* checks whether the register exists */
		{
			printf("The register doesn't not exist: %s, line %d \n", tokens[n+1],lineNumber);
			isValid = NOT_VALID;
		}
	}
	if(containsOnlyNumbers(tokens[n+1]) == 0 && tokens[n+1][0] != '@')	/* checks whether the label exists in the input file */
	{
		if(checkLabels(tokens[n+1],Labels) == 0)
		{
			printf("The label doesn't not exist: %s, line %d \n", tokens[n+1],lineNumber);
			isValid = NOT_VALID;
		}
	}
	if(tokens[n+2][0] == '@')
	{
		if(checkRegisters(tokens[n+2]) == 0)
		{
			printf("The register doesn't not exist: %s, line %d \n", tokens[n+2],lineNumber);	/* checks whether the register exists */
			isValid = NOT_VALID;
		}
	}
	else
	{
		if(checkLabels(tokens[n+2],Labels) == 0)	/* checks whether the label exists in the input file */
		{
			printf("The label doesn't not exist: %s, line %d \n", tokens[n+2],lineNumber);
			isValid = NOT_VALID;
		}
	}
	
	return isValid;
}

int checkFormat2(char **tokens, int n, int lineNumber, item *Labels)
{
	int isValid = VALID;
	int i;
	for(i=n;tokens[i]!='\0';i++)
	{
		
	}
	if(i-n != 3)	/* checks whether the number of operands is correct for the operation */
		{
			printf("Invalid amount of arguments for the operation, line %d \n", lineNumber);
			isValid = NOT_VALID;
		}
	if(tokens[n+1] == '\0')
	{
		return isValid;
	}
	if(checkOperand(tokens[n+1]) == NOT_VALID)	/* checks the validity of the operands */
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+1], lineNumber);
		isValid = NOT_VALID;
	}
	if(checkOperand(tokens[n+2]) == NOT_VALID)
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+2], lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+1][0] == '@')	/* checks whether the registers exist */
	{
		if(checkRegisters(tokens[n+1]) == 0)
		{
			printf("The register doesn't not exist: %s, line %d \n", tokens[n+1],lineNumber);
			isValid = NOT_VALID;
		}
	}
	if(tokens[n+2][0] == '@')
	{
		if(checkRegisters(tokens[n+2]) == 0)
		{
			printf("The register doesn't not exist: %s, line %d \n", tokens[n+2],lineNumber);
			isValid = NOT_VALID;
		}
	}
	if(containsOnlyNumbers(tokens[n+1]) == 0 && tokens[n+1][0] != '@')	/* checks whether the labels exist in the file */
	{
		if(checkLabels(tokens[n+1],Labels) == 0)
		{
			printf("The label doesn't not exist: %s, line %d \n", tokens[n+1],lineNumber);
			isValid = NOT_VALID;
		}
	}
	if(containsOnlyNumbers(tokens[n+2]) == 0 && tokens[n+2][0] != '@')
	{
		if(checkLabels(tokens[n+2],Labels) == 0)
		{
			printf("The label doesn't not exist: %s, line %d \n", tokens[n+2],lineNumber);
			isValid = NOT_VALID;
		}
	}
	
	return isValid;
}

int checkFormat3(char **tokens, int n, int lineNumber, item *Labels)
{
	int isValid = VALID;
	int i;
	
	for(i=n;tokens[i]!='\0';i++)
	{
		
	}
	if(i-n != 2)	/* checks the number of operands */
	{
		printf("Invalid amount arguments for the operator, line %d \n", lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+1] == '\0')
	{
		return isValid;
	}
	if(checkOperand(tokens[n+1]) == NOT_VALID) /* checks the validity of the operand */
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+1], lineNumber);
		isValid = NOT_VALID;
	}
	if(containsOnlyNumbers(tokens[n+1]) == 1)	/* checks if the destination operand is a number which it can't be */
	{
		printf("The destination operand for the operator can't be a number: %s, line %d \n", tokens[n+1],lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+1][0] == '@')	/* checks if the register exists */
	{
		if(checkRegisters(tokens[n+1]) == 0)
		{
			printf("The register doesn't not exist: %s, line %d \n", tokens[n+1],lineNumber);
			isValid = NOT_VALID;
		}
	}
	else	/* checks if the label exists */
	{
		if(checkLabels(tokens[n+1],Labels) == 0)
		{
			printf("The label doesn't not exist: %s, line %d \n", tokens[n+1],lineNumber);
			isValid = NOT_VALID;
		}
	}
	
	return isValid;
}

int checkFormat4(char **tokens, int n, int lineNumber, item *Labels)
{
	int isValid = VALID;
	int i;
	
	for(i=n;tokens[i]!='\0';i++)
	{
		
	}
	if(i-n != 3)	/* checks the number of operands */
	{
		printf("Invalid amount of arguments for the operator, line %d \n", lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+1] == '\0')
	{
		return isValid;
	}
	
	if(checkOperand(tokens[n+1]) == NOT_VALID)	/* checks the validity of the operands */
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+1], lineNumber);
		isValid = NOT_VALID;
	}
	if(checkOperand(tokens[n+2]) == NOT_VALID)
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+2], lineNumber);
		isValid = NOT_VALID;
	}
	if(checkRegisters(tokens[n+1]) == 1 || containsOnlyNumbers(tokens[n+1]) == 1)	/* the source operand for lea operation has to be label */
	{
		printf("The source operand for the operator has to be label: %s, line %d \n", tokens[n+1],lineNumber);
		isValid = NOT_VALID;
	}

	if(containsOnlyNumbers(tokens[n+2]) == 1)	/* checks if the destination is a number which it can't be */
	{
		printf("The destination operand for the operator can't be a number: %s, line %d \n", tokens[n+2],lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+2][0] == '@')	/* checks whether the register exist */
	{
		if(checkRegisters(tokens[n+2]) == 0)
		{
			printf("The register doesn't not exist: %s, line %d \n", tokens[n+2],lineNumber);
			isValid = NOT_VALID;
		}
	}
	else
	{
		if(checkLabels(tokens[n+2],Labels) == 0)	/* checks whether the label exist in the file */
		{
			printf("The label doesn't not exist: %s, line %d \n", tokens[n+2],lineNumber);
			isValid = NOT_VALID;
		}
	}
	
	
	return isValid;
}

int checkFormat5(char **tokens, int n, int lineNumber, item *Labels)
{
	int isValid = VALID;
	int i;
	
	for(i=n;tokens[i]!='\0';i++)
	{
		
	}
	if(i-n != 2)	/* checks the number of operands for the operation */
	{
		printf("Invalid amount of arguments for the operator, line %d \n", lineNumber);
		isValid = NOT_VALID;
	}
	if(tokens[n+1] == '\0')
	{
		return isValid;
	}
	
	if(checkOperand(tokens[n+1]) == NOT_VALID)	/* checks the validity of the operand */
	{
		printf("Invalid operand: %s, line %d \n", tokens[n+1], lineNumber);
		isValid = NOT_VALID;
	}
	
	if(containsOnlyNumbers(tokens[n+1]) == 0 && tokens[n+1][0] != '@')
	{
		if(checkLabels(tokens[n+1],Labels) == 0)	/* checks whether the label exists in the file */
		{
			printf("The label doesn't not exist: %s, line %d \n", tokens[n+1],lineNumber);
			isValid = NOT_VALID;
		}
	}
	
	return isValid;
}





int checkOperand(char *operand)	/* checks whether the operand is valid which is either number, register or label */
{
	if(checkRegisters(operand) == 1 || containsOnlyNumbers(operand) == 1 || checkLabelFormat(operand) == 1)
	{
		return VALID;
	}
	else
	{
		return NOT_VALID;
	}
}


int checkLabels(char* tokens, item* Labels)	/* checks whether the label exists in the file */
{
    item* current = Labels;

    while (current != NULL)
    {
        if (strcmp(tokens, current->name) == 0)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int checkLabelFormat(char *operand)	/* checks whether the label is in the right format */
{
	int i = 0;
	
	if(operand[i] != '\0' && !isalpha(operand[i]))
	{
		return NOT_VALID; /* not a label because the first char isn't a letter */
	}
	
	i++;
	
	while (operand[i] != '\0')
    {
        if (!isalnum(operand[i]))
        {
            return NOT_VALID; /* not a label because the char isn't a letter or a number */
        }
        i++;
    }
	
	return VALID;
}




