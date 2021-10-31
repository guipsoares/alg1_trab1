INPUT = main.c utils.c lista.c
OUTPUT = out

all:
		gcc -Wall -g $(INPUT) -o $(OUTPUT) 

run:
		./$(OUTPUT)

debug:
		gcc -DDEBUG -Wall $(INPUT) -o $(OUTPUT)

valgrind:
		valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(OUTPUT)

