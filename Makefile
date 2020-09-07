CC=gcc
SRC=src
OUT=out

all: executable tests

runTests: tests
	$(OUT)/tests

runExecutable: executable
	$(OUT)/executable

executable: $(OUT)/main.o $(OUT)/quadratic.o $(OUT)/utils.o
	$(CC) $(OUT)/main.o $(OUT)/quadratic.o $(OUT)/utils.o -o $(OUT)/executable -lm

tests: $(OUT)/tests.o $(OUT)/quadratic.o $(OUT)/utils.o
	$(CC) $(OUT)/tests.o $(OUT)/quadratic.o $(OUT)/utils.o -o $(OUT)/tests -lm

$(OUT)/%.o: $(SRC)/%.c makeOut
	$(CC) -c $< -o $@

makeOut: 
	mkdir -p $(OUT)

clean:
	rm -rf $(OUT)