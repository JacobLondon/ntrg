CC=clang
TARGET=ntrg
CFLAGS=-std=c11 -Ince/ -Ijlib/include/ -march=native -lncurses
OBJ_FILES=main.o
INC_FILES=jlib/include/

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $(TARGET) $(OBJ_FILES) $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)
