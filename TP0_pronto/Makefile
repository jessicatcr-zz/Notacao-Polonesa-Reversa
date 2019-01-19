TARGET = tp0
OBJECTS = pilha.o polonesa_reversa.o resolucao.o main.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic -g

defaulf: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

polonesa_reversa.o: polonesa_reversa.c polonesa_reversa.h pilha.h
	$(CC) $(CFLAGS) -c polonesa_reversa.c

resolucao.o: resolucao.c resolucao.h polonesa_reversa.h
	$(CC) $(CFLAGS) -c resolucao.c

main.o: main.c resolucao.h
	$(CC) $(CFLAGS) -c main.c

clean:
	-rm -f *.o
