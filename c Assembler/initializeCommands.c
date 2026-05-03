#include "assembler.h"

/* initializes the commandsArray that contains all the commands structs, their command codes and the number of operands they receive */
struct Commands* getCommandsArray()
{
	static struct Commands commands[COMMANDS_SIZE];

	strcpy(commands[0].commandName, "mov");	/* populates each command struct with its corresponding values: name, code and operands */
	commands[0].commandCode = 0;
	commands[0].operands = 2;

	strcpy(commands[1].commandName, "cmp");
	commands[1].commandCode = 1;
	commands[1].operands = 2;

	strcpy(commands[2].commandName, "add");
	commands[2].commandCode = 2;
	commands[2].operands = 2;

	strcpy(commands[3].commandName, "sub");
	commands[3].commandCode = 3;
	commands[3].operands = 2;

	strcpy(commands[4].commandName, "not");
	commands[4].commandCode = 4;
	commands[4].operands = 1;

	strcpy(commands[5].commandName, "clr");
	commands[5].commandCode = 5;
	commands[5].operands = 1;

	strcpy(commands[6].commandName, "lea");
	commands[6].commandCode = 6;
	commands[6].operands = 2;

	strcpy(commands[7].commandName, "inc");
	commands[7].commandCode = 7;
	commands[7].operands = 1;

	strcpy(commands[8].commandName, "dec");
	commands[8].commandCode = 8;
	commands[8].operands = 1;

	strcpy(commands[9].commandName, "jmp");
	commands[9].commandCode = 9;
	commands[9].operands = 1;

	strcpy(commands[10].commandName, "bne");
	commands[10].commandCode = 10;
	commands[10].operands = 1;

	strcpy(commands[11].commandName, "red");
	commands[11].commandCode = 11;
	commands[11].operands = 1;

	strcpy(commands[12].commandName, "prn");
	commands[12].commandCode = 12;
	commands[12].operands = 1;

	strcpy(commands[13].commandName, "jsr");
	commands[13].commandCode = 13;
	commands[13].operands = 1;

	strcpy(commands[14].commandName, "rts");
	commands[14].commandCode = 14;
	commands[14].operands = 0;

	strcpy(commands[15].commandName, "stop");
	commands[15].commandCode = 15;
	commands[15].operands = 0;

	strcpy(commands[16].commandName, "#");
	commands[16].commandCode = -1;
	commands[16].operands = -1;
	
	return commands;
}
