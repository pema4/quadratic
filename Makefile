CC:=gcc
CFLAGS:=-Wall
SRC:=src
OBJ:=obj
BIN:=bin
DOCS:=docs

all: makeOutputDirs $(BIN)/executable $(BIN)/tests $(DOCS)/index.html

docs:

runTests: $(BIN)/tests
	$?

runExecutable: $(BIN)/executable
	$?

$(BIN)/executable: $(OBJ)/main.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	$(CC) -o $@ $^ -lm

$(BIN)/tests: $(OBJ)/tests.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	$(CC) -o $@ $^ -lm

$(OBJ)/main.o: $(SRC)/main.c $(SRC)/quadratic.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/tests.o: $(SRC)/tests.c $(SRC)/testlib.h $(SRC)/utils.h $(SRC)/quadratic.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/quadratic.o: $(SRC)/quadratic.c $(SRC)/quadratic.h $(SRC)/utils.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/utils.o: $(SRC)/utils.c $(SRC)/utils.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(DOCS)/index.html: $(wildcard $(SRC)/*)
	echo  $(ALL_SRC)
	doxygen Doxyfile

.PHONY: clean makeOutputDirs

makeOutputDirs:
	mkdir -p obj bin

clean:
	rm -rf $(OBJ) $(BIN) $(DOCS)