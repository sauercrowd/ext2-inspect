OBJ := $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c))
CCFLAGS +=-I./include -Wall
BIN := ext2-inspect

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	$(CC) -c $(CCFLAGS) -o $@ $<

clean:
	rm -f obj/* $(BIN)

.PHONY: clean
