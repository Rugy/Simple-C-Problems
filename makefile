MAIN = SimpleProblems.c
EXE = $(MAIN:.c=.exe)
SRC = SimpleProblems.c ListNode.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall

main: $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

%o: %c
	$(CC) $(CFLAGS) $< -c -o $@
	
clean: 
	rm *.exe
	rm *.o