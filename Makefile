CC:=gcc
CFLAGS:=-Wall
SRC:=src
OBJ:=obj
BIN:=bin
DOCS:=docs

.PHONY: all docs runTests runExecutable clean

all: $(BIN)/executable $(BIN)/tests $(DOCS)/index.html

docs: $(DOCS)/index.html

runTests: $(BIN)/tests
	$?

runExecutable: $(BIN)/executable
	$?

clean:
	rm -rf $(OBJ) $(BIN) $(DOCS)

$(BIN)/executable: $(OBJ)/main.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	mkdir -p $(BIN)
	$(CC) -o $@ $^ -lm

$(BIN)/tests: $(OBJ)/tests.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	mkdir -p $(BIN)
	$(CC) -o $@ $^ -lm

$(OBJ)/main.o: $(SRC)/main.c $(SRC)/quadratic.h
	mkdir -p $(OBJ)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/tests.o: $(SRC)/tests.c $(SRC)/testlib.h $(SRC)/utils.h $(SRC)/quadratic.h
	mkdir -p $(OBJ)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/quadratic.o: $(SRC)/quadratic.c $(SRC)/quadratic.h $(SRC)/utils.h
	mkdir -p $(OBJ)
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/utils.o: $(SRC)/utils.c $(SRC)/utils.h
	mkdir -p $(OBJ)
	$(CC) -c $(CFLAGS) -o $@ $<

$(DOCS)/index.html: $(wildcard $(SRC)/*)
	doxygen Doxyfile
