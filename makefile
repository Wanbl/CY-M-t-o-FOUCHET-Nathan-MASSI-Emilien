CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all:meteo

%.o: %.c header.h
	$(CC) -c $< -o $@

meteo: $(OBJ)
	$(CC) $^ -o $@
	
clean:
	rm -f $(OBJ) meteo
