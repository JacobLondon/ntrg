CC=clang
TARGET=ntrg
CFLAGS=-std=c11 -Ince/ -march=native -lncurses
OBJ_FILES=main.o

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $(TARGET) $(OBJ_FILES) $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)
