INCLUDE_DIR = include
OBJ_DIR = obj
SRC_DIR = src

PROG = main.exe
CC = gcc
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR) -std=c17 -c

_DEPS = aes.h gf2^8.h iofile.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJ = aes.o gf2^8.o iofile.o main.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

.PHONY: all memorycheck clean

all : $(PROG)

memorycheck : $(PROG)
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG)

clean:
	rm -f $(OBJ_DIR)/*.o $(PROG)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $<

$(PROG) : $(OBJ)
	$(CC) -o $@ $^ -lm -lpthread