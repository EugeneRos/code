assembler: assembler.o split.o initializeCommands.o placeMacros.o firstPass.o secondPass.o initializeRegisters.o toBase64.o checkFile.o checkRegisters.o checkFormats.o linkedListsMethods.o checkCommas.o
	gcc -ansi -pedantic -g -Wall checkCommas.o linkedListsMethods.o checkFormats.o checkRegisters.o checkFile.o toBase64.o initializeRegisters.o secondPass.o firstPass.o placeMacros.o initializeCommands.o split.o assembler.o -o assembler
assembler.o: assembler.c assembler.h
	gcc -c -ansi -pedantic -g -Wall assembler.c -o assembler.o
split.o: split.c 
	gcc -c -ansi -pedantic -g -Wall split.c -o split.o
initializeCommands.o: initializeCommands.c 
	gcc -c -ansi -pedantic -g -Wall initializeCommands.c -o initializeCommands.o
placeMacros.o: placeMacros.c 
	gcc -c -ansi -pedantic -g -Wall placeMacros.c -o placeMacros.o
firstPass.o: firstPass.c 
	gcc -c -ansi -pedantic -g -Wall firstPass.c -o firstPass.o
secondPass.o: secondPass.c 
	gcc -c -ansi -pedantic -g -Wall secondPass.c -o secondPass.o
initializeRegisters.o: initializeRegisters.c 
	gcc -c -ansi -pedantic -g -Wall initializeRegisters.c -o initializeRegisters.o
toBase64.o: toBase64.c 
	gcc -c -ansi -pedantic -g -Wall toBase64.c -o toBase64.o
checkFile.o: checkFile.c 
	gcc -c -ansi -pedantic -g -Wall checkFile.c -o checkFile.o
checkRegisters.o: checkRegisters.c 
	gcc -c -ansi -pedantic -g -Wall checkRegisters.c -o checkRegisters.o
checkFormats.o: checkFormats.c 
	gcc -c -ansi -pedantic -g -Wall checkFormats.c -o checkFormats.o
linkedListsMethods.o: linkedListsMethods.c 
	gcc -c -ansi -pedantic -g -Wall linkedListsMethods.c -o linkedListsMethods.o
checkCommas.o: checkCommas.c 
	gcc -c -ansi -pedantic -g -Wall checkCommas.c -o checkCommas.o
