all: driver build


driver: src/driver.c src/DynamicArray.c
	mkdir bin
	gcc src/driver.c src/DynamicArray.c -o bin/driver

build: src/DynamicArray.c
	mkdir build
	gcc -c src/DynamicArray.c -o build/DynamicArray.o
	ar rcs build/libDynamicArray.a build/DynamicArray.o
	rm build/DynamicArray.o
	gcc -fPIC -c src/DynamicArray.c -o build/DynamicArray.o
	gcc -shared build/DynamicArray.o -o build/libDynamicArray.so
	rm build/DynamicArray.o

clean:
	rm -r build bin
