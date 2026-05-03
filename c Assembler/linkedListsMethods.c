#include "assembler.h"
#define VALID 1
#define NOT_VALID 0

macroName* createMacroNode(const char* name, const char* macro)
{
    macroName* newNode = (macroName*)malloc(sizeof(macroName));	/* creates a macro node with the given name and content of the macro */

    if (newNode != NULL) {
        strncpy(newNode->name, name, MACRO_NAME_SIZE - 1);
        newNode->name[MACRO_NAME_SIZE - 1] = '\0';

        strncpy(newNode->macro, macro, MACRO_SIZE - 1);
        newNode->macro[MACRO_SIZE - 1] = '\0';

        newNode->next = NULL;
    }
    else
    {
    	printf("Not enough memory");	/* insertMacroNodes will free the linked list if there's not enough memory to create a new node */
    }

    return newNode;
}

void insertMacroNode(macroName** head, const char* name, const char* macro)
{
    macroName* newNode = createMacroNode(name, macro);
	if(newNode == NULL)				/* empties the linked list if there's not enough memory to create a new node */
	{
		printf("Memory allocation failed. Unable to add item to the linked list.\n");
        freeMacroList(*head);
        return;
	}
	
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        macroName* current = *head;
        while (current->next != NULL)	/* traverses through the linked list and places the new node at the end */
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeMacroList(macroName* head)		/* frees the memory for each node in the macro linked list */
{
    macroName* current = head;
    macroName* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int addItem(item** head, const char* name)		/* add labels names in a linked list that is used for checks */
{
	item* current = *head;
	item* new_item = (item*)malloc(sizeof(item));
    if (new_item == NULL)
    {
        printf("Memory allocation failed. Unable to add item to the linked list.\n");
        freeItems(*head);
        return NOT_VALID;
    }

    /* check if the item already exists in the linked list */
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Item '%s' is already present in the linked list.\n", name);
            return NOT_VALID; /* the item is already present */
        }
        current = current->next;
    }

    strncpy(new_item->name, name, NAME_SIZE - 1);
    new_item->name[NAME_SIZE - 1] = '\0';
    new_item->next = NULL;

    if (*head == NULL) 
    {
        /* the linked list is empty, make the new item the head of the list */
        *head = new_item;
    }
    else 
    {
        /* traverse to the end of the list and add the new item */
        current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_item;
    }
    
	return VALID;
}

void freeItems(item* head)		/* frees the memory of each node of the linked list that is used for checks */
{
    item* current = head;
    item* nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int searchForWord(FILE *file, const char *word)		/* searches words in documents, for example to check whether entries and externals files */
{													/* need to be created */
    char line[MAX_LINE_LENGTH];

    /* reset file position indicator to the beginning */
    fseek(file, 0, SEEK_SET);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        /* check if the word is found in the line */
        if (strstr(line, word) != NULL)
        {
            return 1;	/* the word was found */
        }
    }
    return 0;
}

Label* createLabelNode(const char* name, int address, const char* labelType)	/* creates a label node in the Labels linked list  */
{
    Label* newNode = (Label*)malloc(sizeof(Label));

    if (newNode != NULL)
     {
        strncpy(newNode->name, name, NAME_SIZE - 1);	/* populates the name of the label */
        newNode->name[NAME_SIZE - 1] = '\0';
		
		newNode->labelAddress = address;	/* populates the address of the label */
        strncpy(newNode->labelType, labelType, LABEL_TYPE_SIZE - 1);	/* populates the type of the label */
        newNode->labelType[LABEL_TYPE_SIZE - 1] = '\0';	

        newNode->next = NULL;
    }

    return newNode;
}

void addLabelNode(Label** Labels, const char* token, int address, char labelType[])		/* adds label nodes to the labels linked list */
{
    Label* curr = *Labels;
    while (curr != NULL)
    {
        if (strcmp(curr->name, token) == 0)
        {
            curr->labelAddress = address;
            if(strcmp(labelType, "local") != 0)
            {
            	strncpy(curr->labelType, labelType, LABEL_TYPE_SIZE - 1);	
            	curr->labelType[LABEL_TYPE_SIZE - 1] = '\0';
            }
            return;
        }
        curr = curr->next;
    }

    curr = createLabelNode(token, address, labelType);
    
    if (curr == NULL)
    {
        freeLabels(Labels);
        printf("Not enough memory");
        return;
    }

    curr->next = *Labels;
    *Labels = curr;
}


void freeLabels(Label** firstLabel)		/* frees every node in the labels linked list */
{
    struct label* current = *firstLabel;
    struct label* temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }

    *firstLabel = NULL;
}

int containsOnlyNumbers(const char *str) {		/* checks whether a string contains a valid number (+ - in the beggining or only numbers) */
    int i = 0;
    
    if(!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
    	return 0;
    	
    i++;
    
    while (str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            return 0; /* Character is not a digit or + or - signs */
        }
        i++;
    }
    return 1; /* All characters are digits */
}

Label* getLabel(Label **Labels, char *token)	/* this method gets the Labels linked list and a string, it looks through the linked list */
{												/* and returns the label with name like that string */
    Label *curr1 = *Labels;
    while(curr1 != NULL && strcmp(curr1->name, token) != 0)
    {
        if(curr1->next == NULL)
        {
            return NULL;
        }
        curr1 = curr1->next;
    }
    return curr1;
}
