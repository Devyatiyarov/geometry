
all: geometry


geometry: main.o functions.o
	gcc -Wall -Werror build/main.o build/functions.o -o bin/geometry
main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o
functions.o: src/functions.c
	gcc -Wall -Werror -c src/functions.c -o build/functions.o


clean:
rm -rf build/*.o bin/geometry
