all: driver static dynamic


driver: src/driver.c src/DynamicArray.c
	gcc src/driver.c src/DynamicArray.c -o bin/driver

static: src/DynamicArray.c
	gcc -c src/DynamicArray.c -o build/DynamicArray.o
	ar rcs build/libDynamicArray.a build/DynamicArray.o
	rm build/DynamicArray.o

dynamic: src/DynamicArray.c
	gcc -fPIC -c src/DynamicArray.c -o build/DynamicArray.o
	gcc -shared build/DynamicArray.o -o build/libDynamicArray.so
	rm build/DynamicArray.o

clean:
	rm build/* bin/*
