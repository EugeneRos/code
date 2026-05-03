#include "assembler.h"

/* the assembler program receives the file names that are passed as arguments, checks them for assembly syntax and if they pass the checks runs the assembly process in which it creates am, obj, ent and ext files (ent and ext if there are entries and externals) */
int main(int argc, char **argv)
{
	int i;
	if (argc < 2)	/* the argument of the file name is required */
	{
        printf("File names weren't entered.\n");
        return 1;
    }
    
    for (i = 1; i < argc; i++)	/* runs the assembler with every file that is passed */
    {
        placeMacros(argv[i]);
    }
	
	
	return 0;
}
