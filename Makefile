CC=clang
TARGET=ntrg
CFLAGS=-std=c11 -Ince/ -Ijlib/include/ -march=native -lncurses

OBJ_FILES=src/globals.o src/room.o src/player.o src/main.o
STATIC_LIBS=jlib/jlib.a nce/nce.a

.PHONY: clean

all: subsystem main

subsystem:
	$(MAKE) -C jlib
	$(MAKE) -C nce

main: $(OBJ_FILES) $(STATIC_LIBS)
	$(CC) -o $(TARGET) $^ $(CFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)

subclean:
	$(MAKE) clean -C jlib
	$(MAKE) clean -C nce