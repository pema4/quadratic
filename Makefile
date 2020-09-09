CC:=gcc
CFLAGS:=-Wall
SRC:=src
OBJ:=obj
BIN:=bin
DOCS:=docs

.PHONY: all docs app tests runTests runApp clean

all: app tests docs

app: $(BIN)/app

tests: $(BIN)/tests

docs: $(DOCS)/index.html

runTests: $(BIN)/tests
	@$?

runApp: $(BIN)/app
	@$?

clean:
	@echo "Removing $(OBJ), $(BIN), and $(DOCS) directories"
	@rm -rf $(OBJ) $(BIN) $(DOCS)

$(BIN)/app: $(OBJ)/main.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	@echo "Linking $@"
	@mkdir -p $(BIN)
	@$(CC) -o $@ $^ -lm

$(BIN)/tests: $(OBJ)/tests.o $(OBJ)/quadratic.o $(OBJ)/utils.o
	@echo "Linking $@"
	@mkdir -p $(BIN)
	@$(CC) -o $@ $^ -lm

$(OBJ)/main.o: $(SRC)/main.c $(SRC)/quadratic.h
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/tests.o: $(SRC)/tests.c $(SRC)/testlib.h $(SRC)/utils.h $(SRC)/quadratic.h
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/quadratic.o: $(SRC)/quadratic.c $(SRC)/quadratic.h $(SRC)/utils.h
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ)/utils.o: $(SRC)/utils.c $(SRC)/utils.h
	@echo "Compiling $@"
	@mkdir -p $(OBJ)
	@$(CC) -c $(CFLAGS) -o $@ $<

$(DOCS)/index.html: $(wildcard $(SRC)/*)
	@echo "Compiling documentation"
	@doxygen Doxyfile
