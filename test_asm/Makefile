

CC=gcc
CFLAGS= -O0 -g -Wall

TARGET=test_asm

OBJ_DIR=objs
SRC=$(wildcard *.c)
DIR=$(notdir $(SRC))
OBJ=$(patsubst %.c,$(OBJ_DIR)/%.o,$(DIR))

build: clean $(OBJ_DIR) $(OBJ_DIR)/$(TARGET)

$(OBJ_DIR):
	echo "create directory"
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/$(TARGET): $(OBJ)
	echo "create target"	
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC)
	echo "create target *.o"		
	$(CC)  -c $< -o $@

clean:
	echo "clean"
	-rm -fr objs
