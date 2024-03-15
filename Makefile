CC = g++
CFLAGS = -g -Wall -Wextra
TARGET = library

default: $(TARGET)

$(TARGET): library.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) library.o main.o

library.o: library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp 

main.o: main.cpp library.h
	$(CC) $(CFLAGS) -c main.cpp 

clean:
	$(RM) *.o *~
