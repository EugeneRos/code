#define COMMANDS_SIZE 17
#define COMMANDS_SIZE 17
#define COMMAND_NAME_SIZE 5
#define MACRO_SIZE 80
#define MACRO_NAME_SIZE 20
#define NAME_SIZE 20
#define REGISTERS_SIZE 9
#define MAX_FILENAME_LENGTH 20
#define MAX_LINE_LENGTH 80
#define DESTINATION_ADDRESSING 2
#define OPCODE 5
#define SOURCE_ADDRESSING 9
#define INSTANT_ADDRESSING 1
#define DIRECT_ADDRESSING 3
#define REGISTER_ADDRESSING 5
#define ONE_BINARY_WORDS 1
#define TWO_BINARY_WORDS 2
#define THREE_BINARY_WORDS 3
#define A_R_E_ABSOLUTE 0
#define A_R_E_RELOCATABLE 2
#define A_R_E_EXTERNAL 1
#define START_OF_BINARY_WORD 2
#define LABEL_TYPE_SIZE 10
#define MEMORY_START 100
#define DATA_SIZE 1000
#define DESTINATION_REGISTER 2
#define SOURCE_REGISTER 7
#define SECOND_BINARY_WORD 1
#define THIRD_BINARY_WORD 2
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


struct list_el 
{
	char name[NAME_SIZE];
	struct list_el * next;
};

typedef struct list_el item;

struct macro_name 
{
	char name[NAME_SIZE];
	char macro[MACRO_SIZE];
	struct macro_name * next;
};

typedef struct macro_name macroName;

struct Commands
{
	char commandName[COMMAND_NAME_SIZE];
	char commandCode;
	char operands;
} commands[COMMANDS_SIZE];

struct label
{
	char name[NAME_SIZE];
	short int labelAddress;
	char labelType[LABEL_TYPE_SIZE];
	struct label * next;
};

typedef struct label Label;

struct Asm_Registers
{
	char name[NAME_SIZE];
	short int regCode;
	struct asm_register * next;
} asm_registers[REGISTERS_SIZE];


extern char **split(char *str);
extern struct Commands* getCommandsArray();
extern void placeMacros(char fileName[]);
extern void freeMacroList(macroName* head);
extern macroName* createMacroNode(const char* name, const char* macro);
extern void toBase64(short int **machineCode, char destinationFilename[], int IC, int DC);
extern Label* createLabelNode(const char* name, int address, const char* labelType);
extern void freeLabels(Label** firstLabel);
extern int containsOnlyNumbers(const char *str);
extern void addLabelNode(Label** Labels, const char* token, int IC, char labelType[]);
extern void firstPass(char fileName[]);
extern void secondPass(short int **machineCode, Label **Labels, char fileName[], int DCreceived);
extern struct Asm_Registers* getRegistersArray();
extern int searchForWord(FILE *file, const char *word);
extern void checkFile(char fileName[]);
extern int checkRegisters(char reg[]);
extern int checkFormat1(char **tokens, int n, int lineNumber, item *Labels);
extern int addItem(item** head, const char* name);
extern int checkFormat2(char **tokens, int n, int lineNumber, item *Labels);
extern int checkFormat3(char **tokens, int n, int lineNumber, item *Labels);
extern int checkFormat4(char **tokens, int n, int lineNumber, item *Labels);
extern int checkFormat5(char **tokens, int n, int lineNumber, item *Labels);
extern int checkOperand(char *operand);
extern int checkLabels(char* tokens, item* Labels);
extern void freeItems(item* head);
extern Label* getLabel(Label **Labels, char *token);
extern int checkCommas(const char *line);
extern int checkLabelFormat(char *operand);

