CC:=gcc
CFLAGS:=-Wall
SRC:=src
OBJ:=obj
BIN:=bin
DOCS:=docs

all: executable tests docs

runTests: tests
	$(BIN)/tests

runExecutable: executable
	$(BIN)/executable

executable: $(OBJ)/main.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	$(CC) $(CFLAGS) $(OBJ)/main.o $(OBJ)/quadratic.o $(OBJ)/utils.o -o $(BIN)/executable -lm

tests: $(OBJ)/tests.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	$(CC) $(CFLAGS) $(OBJ)/tests.o $(OBJ)/quadratic.o $(OBJ)/utils.o -o $(BIN)/tests -lm

$(OBJ)/%.o: $(SRC)/%.c makeOutputDirs
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: makeOutputDirs clean

docs: $(SRC)/*
	doxygen Doxyfile

makeOutputDirs:
	mkdir -p obj bin

clean:
	rm -rf $(OBJ) $(BIN) $(DOCS)