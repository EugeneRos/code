#include "assembler.h"



void secondPass(short int **machineCode, Label **Labels, char fileName[], int DCreceived)
{
	
	FILE *amFile, *entFile = NULL, *extFile = NULL;
	char amFileNameCopy[MAX_FILENAME_LENGTH], entFileName[MAX_FILENAME_LENGTH], extFileName[MAX_FILENAME_LENGTH];
	char **tokens;
	char *extension = NULL;
	Label *curr1 = NULL, *curr2 = NULL;
	int IC = 0; 
	int DC = DCreceived;
	int n, i, commandOperands;
	char line[MAX_LINE_LENGTH];
	struct Commands* commands = getCommandsArray();
	
	strcpy(amFileNameCopy, fileName);
	
    amFile = fopen(fileName, "r");	/* opens .am file */
    if (amFile == NULL)
    {
        printf("Couldn't open the source file.\n");
        return;
    }
    
    
    if(searchForWord(amFile, ".extern") == 1)	/* if there is .extern in the file creates .ext file */
    {
    	strcpy(extFileName, amFileNameCopy);
		extension = strstr(extFileName,".am");
		*extension = '\0';
		strncat(extFileName, ".ext", MAX_FILENAME_LENGTH - strlen(extFileName) - 1);
    	extFile = fopen(extFileName, "w");
    	if (extFile == NULL)
    	{
        	printf("Failed to open the destination file.\n");
        	return;
    	}
    }
    (void)extension;
    
    if(searchForWord(amFile, ".entry") == 1)	/* if there is .entry in the file creates .ent file */
    {
    	strcpy(entFileName, amFileNameCopy);
		extension = strstr(entFileName,".am");
		*extension = '\0';
		strncat(entFileName, ".ent", MAX_FILENAME_LENGTH - strlen(entFileName) - 1);
    	entFile = fopen(entFileName, "w");
    	if (entFile == NULL)
    	{
        	printf("Failed to open the destination file.\n");
        	return;
    	}
    }
    
	
	fseek(amFile, 0, SEEK_SET);
	
	while (fgets(line, sizeof(line), amFile) != NULL)	/* reads the .am file line by line */
    {
    	if (line[0] == '\n' || line[0] == ';')
    	{
        	continue;
    	}
    	n = 0;
    	
    	tokens = split(line);
        
        if(tokens[0][strlen(tokens[0])-1] == ':')	/* if there is a label starts processing from the second token  */
        {
        	n = 1;
        }
    	
    	if(strcmp(tokens[n],".entry") == 0)	/* prints the labels and their address that are the operand of .entry into the entry file */
        {
        	curr1 = getLabel(Labels,tokens[n+1]);
			
        	fprintf(entFile, "%-10s %d\n", tokens[n+1], (curr1->labelAddress));
        	continue;
        }
        else if(strcmp(tokens[n],".extern") == 0)		/* .extern .string and .data were handled in the first pass */
        {
        	continue;
        }
        else if(strcmp(tokens[n],".string") == 0)
        {
        	continue;
        }
        else if(strcmp(tokens[n],".data") == 0)
        {
        	continue;
        }
        
        for(i=0; strcmp(commands[i].commandName,tokens[n]) != 0; i++)
	    {
	    	if(strcmp(commands[i].commandName,"#") == 0)
	    	{
	    		printf("Command not found: %s", tokens[n]);
	    		return;
	    	}
	    }
	    
	    commandOperands = commands[i].operands;
        
        if(commandOperands == 2)
			{
				if(tokens[n+1][0] == '@' && tokens[n+2][0] == '@')	/* when the operands are two registers */
				{
					IC += TWO_BINARY_WORDS;
				}
				else if(containsOnlyNumbers(tokens[n+1]) == 0 && containsOnlyNumbers(tokens[n+2]) == 0 && tokens[n+1][0] != '@' && tokens[n+2][0] != '@')
				{
					/* when the operands are label and label */
					
					curr1 = getLabel(Labels,tokens[n+1]);	/* finds the labels in the operands inside the linked list */
					curr2 = getLabel(Labels,tokens[n+2]);
					
					if(strcmp(curr1->labelType,"external") == 0)	/* if the first label is external writes in the external file */
					{												/* and in the machineCode A_R_E */
						(*machineCode)[IC+1] |= A_R_E_EXTERNAL;
						fprintf(extFile, "%-10s %d\n", tokens[n+1], (IC+MEMORY_START+THIRD_BINARY_WORD));
					}
					else	/* if it's a usual label writes the label address to the binary word of the first operand */
					{
						(*machineCode)[IC+1] |= ((curr1->labelAddress)<<START_OF_BINARY_WORD);
					}
					
					if(strcmp(curr2->labelType,"external") == 0)	/* if the second label is external writes in the external file */
					{												/* and in the machineCode A_R_E */
						(*machineCode)[IC+2] |= A_R_E_EXTERNAL;
						fprintf(extFile, "%-10s %d\n", tokens[n+2], (IC+MEMORY_START+THIRD_BINARY_WORD));
					}
					else	/* if it's a usual label writes the label address to the binary word of the second operand */
					{
						(*machineCode)[IC+2] |= ((curr2->labelAddress)<<START_OF_BINARY_WORD);
					}
					IC += THREE_BINARY_WORDS;
				}
				else if(containsOnlyNumbers(tokens[n+1]) == 1 && containsOnlyNumbers(tokens[n+2]) == 0 && tokens[n+2][0] != '@')
				{
					/* when the operands are number and label */
					
					curr1 = getLabel(Labels,tokens[n+2]);
					
					if(strcmp(curr1->labelType,"external") == 0)	/* if the label is external */
					{
						(*machineCode)[IC+2] |= A_R_E_EXTERNAL;		/* writes external in the machineCode */
						fprintf(extFile, "%-10s %d\n", tokens[n+2], (IC+MEMORY_START+THIRD_BINARY_WORD)); /* and writes in the extern file  */
					}
					else
					{
						(*machineCode)[IC+2] |= ((curr1->labelAddress)<<START_OF_BINARY_WORD);	/* if it's a usual label writes the address */
						IC += THREE_BINARY_WORDS;												/* in the machineCode */
					}
				}
				else if(containsOnlyNumbers(tokens[n+1]) == 0 && containsOnlyNumbers(tokens[n+2]) == 0 && tokens[n+1][0] != '@' && tokens[n+2][0] == '@')
				{
					/* when the operands are label (source) and register (destination)*/
					
					curr1 = getLabel(Labels,tokens[n+1]);
					
					if(strcmp(curr1->labelType,"external") == 0)
					{
						(*machineCode)[IC+1] |= A_R_E_EXTERNAL;	/* external label */
						fprintf(extFile, "%-10s %d\n", tokens[n+1], (IC+MEMORY_START+THIRD_BINARY_WORD));
					}
					else
					{
						(*machineCode)[IC+1] |= ((curr1->labelAddress)<<START_OF_BINARY_WORD);	/* usual label */
						IC += THREE_BINARY_WORDS;
					}
				
				}
				else if(containsOnlyNumbers(tokens[n+1]) == 0 && containsOnlyNumbers(tokens[n+2]) == 0 && tokens[n+1][0] == '@' && tokens[n+2][0] != '@')
				{
					/* when the operands are register (source) and label (destination)*/
					
					curr1 = getLabel(Labels,tokens[n+2]);
					
					if(strcmp(curr1->labelType,"external") == 0)
					{
						(*machineCode)[IC+2] |= A_R_E_EXTERNAL;		/* external label */
						fprintf(extFile, "%-10s %d\n", tokens[n+2], (IC+MEMORY_START+THIRD_BINARY_WORD));
					}
					else
					{
						(*machineCode)[IC+2] |= ((curr1->labelAddress)<<START_OF_BINARY_WORD);	/* usual label */
						IC += THREE_BINARY_WORDS;
					}
				
				}
				else if(containsOnlyNumbers(tokens[n+1]) == 1 && containsOnlyNumbers(tokens[n+2]) == 0 && tokens[n+1][0] != '@' && tokens[n+2][0] == '@')
				{
					/* when the operands are number (source) and register (destination) */
					
					IC += THREE_BINARY_WORDS;
				}
			 }
			 else if(commandOperands == 1)	/* one operand */
			 {
			 	
			 	if(containsOnlyNumbers(tokens[n+1]) == 1)
			 	{
			 		
			 		/* when the operand is a number (destination) */
			 		IC += TWO_BINARY_WORDS;
			 	}
			 	else if(containsOnlyNumbers(tokens[n+1]) == 0 && tokens[n+1][0] != '@')
			 	{
			 		/* when the operand is a label (destination) */
			 		curr1 = getLabel(Labels,tokens[n+1]);
					
					if(strcmp(curr1->labelType,"external") == 0)
					{
						(*machineCode)[IC+1] |= A_R_E_EXTERNAL;	/* external label */
						fprintf(extFile, "%-10s %d\n", tokens[n+1], (IC+MEMORY_START+SECOND_BINARY_WORD));
					}
					else
					{
			 			(*machineCode)[IC+1] |= ((curr1->labelAddress)<<START_OF_BINARY_WORD);	/* usual label */
			 			(*machineCode)[IC+1] |= A_R_E_RELOCATABLE;
			 		}
			 		IC += TWO_BINARY_WORDS;
			 	}
			 	
			 	else if(containsOnlyNumbers(tokens[n+1]) == 0 && tokens[n+1][0] != '@')
			 	{
			 		
			 		/* when the operand is a register (destination) */
			 		
			 		IC += TWO_BINARY_WORDS;
			 	}
			 	
        
    		}
    		else /* operations without operands */ 
    		{
			 	IC++;
    		}

	}
	
	freeLabels(Labels);	/* frees the memory and closes the files */
	free(Labels);
	fclose(amFile);
	if(entFile != NULL)
	{
		fclose(entFile);
	}
	if(extFile != NULL)
	{
		fclose(extFile);
	}
	
	toBase64(machineCode, amFileNameCopy, IC, DC);	/* calls toBase64 method with the filled machineCode */
	

	}
	

