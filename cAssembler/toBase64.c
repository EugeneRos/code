#define SIX_BITS_ON 63
#include "assembler.h"

/* translates the machineCode into Base64 */
void toBase64(short int **machineCode, char destinationFilename[], int IC, int DC)
{

	char base64Table[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
	'S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
	'q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};	/* the table for translating binary words */
	int i;
	FILE *destinationFile;
	char *extension;
	register char c1, c2;
	char newDestFilename[MAX_FILENAME_LENGTH];
	
	strcpy(newDestFilename, destinationFilename);
	extension = strstr(newDestFilename, ".am");
	*extension = '\0';
	strncat(newDestFilename, ".obj", MAX_FILENAME_LENGTH - strlen(newDestFilename) - 1);	
	
	destinationFile = fopen(newDestFilename, "w");	/* creates the .obj file */
    if (destinationFile == NULL) {
        printf("Failed to open the destination file.\n");
        return;
    }
    
    fprintf(destinationFile, "%d %d \n", IC, DC);	/* prints the IC and DC values at the top of the obj file */
	
	
	for(i = 0; i < IC + DC ; i++)
	{
		c1 = base64Table[(((*machineCode)[i]) & (SIX_BITS_ON << 6)) >> 6];	/* takes the 6 left bits of the binary word and translates to Base64 */
		c2 = base64Table[((*machineCode)[i]) & SIX_BITS_ON];			/* takes the 6 right bits of the binary word and translates to Base64 */
		fprintf(destinationFile, "%c%c \n", c1, c2);	/* prints the translated binary words in the obj file */
	}


	fclose(destinationFile);	/* closes the .obj file */
	free(machineCode);		/* frees the machineCode memory */

}
