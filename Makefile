CC=gcc
BUILD_DIR=./build
INCLUDE_DIR=./include
OBJ_DIR=./obj
CFLAGS=-I$(INCLUDE_DIR) -Wall -g

_OBJ = hello.o greeter.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

.PHONY: clean

$(OBJ_DIR)/%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

hello: always $(OBJ)
	$(CC) -o $(BUILD_DIR)/$@ $(OBJ) $(CFLAGS)

always:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o *~ core
