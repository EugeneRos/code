#include <stdio.h>
#include <ctype.h>


int check_double(char str[])
{
	int i;
	int decimal_points =0;
	int minus = 0;
	
	for(i=0; str[i] == ' ' ||str[i] == '\t' ||str[i] == ',' || str[i] == '-';i++) /* checks if there is an illegal comma before the number */
	{
		if(str[i] == ',')
		{
			printf("Illegal comma: %s\n\n", str);
			return 1;
		}
		if(str[i] == '-')	/* counts number of minuses in the number */
			minus++;
		if(minus > 1)
			printf("Too many minuses: %s\n\n", str);
		
			
	}
	
	

	for ( ; str[i] != '\0' && str[i] != '\n' && str[i] != ' ' && str[i] != '\t'  ; i++) 
   	{
     	if (isdigit(str[i]) == 0 && str[i] != '.')	/* checks whether the number contains a character that can't be a part of a number */
        {
        	printf("Invalid parameter – not a number: %s\n\n", str);
         	return 1;
        }
        if (str[i] == '.') /* counts the number of points in number */
        {
         	decimal_points++;
        }
        if(decimal_points>1)
        {
        	printf("The operand contains more than one decimal point: %s\n\n", str);
        	return 1;
        }
        	/* there should be maximum one decimal point in the double number */
    }
    
    
    for( ; str[i] != '\0' && str[i] != ',' && str[i] != '\n';i++) /* checks whether there is extraneous chars after the number */
	{
		if(str[i] != ' ' && str[i] != '\t')
		{
			printf("Extraneous text after number: %s\n\n", str);
			return 1;
		}
	}
    
    return 0;	
}


