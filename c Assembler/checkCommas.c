#include <stdio.h>
#include <ctype.h>

int checkCommas(const char *line)
{
    int commaFound = 0;
    int i;
    
    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] == ',')
        {
            /* if a comma was found previously */
            if (commaFound) /* two commas found consecutively or with white space */
            { 
                return 0; 
            }
            commaFound = 1;
        }
        else if (isspace(line[i]))
        {
            continue; /* skips white spaces */
        }
        else
        {
            /* resets commaFlag if another char was found */
            commaFound = 0;
        }
    }
    
    return 1; /* no consecutive commas found */
}
