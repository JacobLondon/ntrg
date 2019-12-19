CC=clang
TARGET=ntrg
CFLAGS=-std=c11 -Ince/ -Ijlib/include/ -march=native -lncurses

OBJ_FILES=src/main.o src/room.o
STATIC_LIBS=jlib/jlib.a

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $@ $(OBJ_FILES) $(CFLAGS) $(STATIC_LIBS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)
