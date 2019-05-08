.PHONY: all clean

all: bin/geometry

BUILD_SRC := ./build/src
BUILD_TEST := ./build/test

bin/geometry: $(BUILD_SRC)/main.o $(BUILD_SRC)/circle.o
	gcc -Wall -Werror $(BUILD_SRC)/main.o $(BUILD_SRC)/circle.o -o bin/geometry -lm

$(BUILD_SRC)/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o $(BUILD_SRC)/main.o

$(BUILD_SRC)/circle.o: src/circle.c
	gcc -Wall -Werror -c src/circle.c -o $(BUILD_SRC)/circle.o

test: bin/test

bin/test: $(BUILD_TEST)/main.o $(BUILD_TEST)/circle.o
	gcc -Wall -Werror $(BUILD_TEST)/main.o $(BUILD_TEST)/circle.o -o bin/test -lm

$(BUILD_TEST)/main.o: test/main.c
	gcc -Wall -Werror -c -I thirdparty -I src test/main.c -o $(BUILD_TEST)/main.o

$(BUILD_TEST)/circle.o: src/circle.c src/circle.h
	gcc -Wall -Werror -c -I thirdparty -I src src/circle.c -o $(BUILD_TEST)/circle.o

run_test: test
	bin/test

clean:
	rm -rf $(BUILD_SRC)/*.o $(BUILD_TEST)/*.o bin/geometry bin/test

