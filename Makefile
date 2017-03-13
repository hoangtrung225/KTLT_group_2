CC = gcc

execute: CheckList.h
    $(CC) -std=c99 CheckContactList.c CheckList.o -o CheckContactList
CheckList.h:  CheckList.c
	$(CC) -c CheckList.c -std=c99
clean:
	rm *.o