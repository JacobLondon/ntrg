CC=clang
TARGET=ntrg
CFLAGS=-std=c11 -Ince/ -Ijlib/include/ -march=native -lncurses

OBJ_FILES=main.o
STATIC_LIBS=jlib/jlib.a

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CC) -o $@ $< $(CFLAGS) $(STATIC_LIBS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)
