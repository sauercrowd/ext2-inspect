OBJ	:= $(patsubst src/%.c,obj/%.o,$(wildcard src/*.c))
CCFLAGS	+=-I./include -Wall
BIN 	:= ext2-inspect
OBJDIR 	:= obj


all: $(BIN)

$(BIN): $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS)-o $(BIN) $(OBJ) $(LDFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

obj/%.o: src/%.c
	$(CC) -c $(CCFLAGS) -o $@ $<

clean:
	rm -rf obj/ $(BIN)

.PHONY: clean
