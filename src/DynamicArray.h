#if !defined(DYNAMICARRAY_H)
#define DYNAMICARRAY_H

typedef struct DynamicArray {
	unsigned int capacity;
	unsigned int length;
	int *data;
} DynamicArray;

/* Attempts to allocate a new DynamicArray structure with the specified initial capacity.
 * Returns a NULL value upon failure. */
DynamicArray *createDynamicArray(unsigned int initialCapacity);
/* Frees the specified DynamicArray */
void destroyDynamicArray(DynamicArray *dynamicArray);
/* Attempts to allocate more area to increase capacity by two. Returns 1 upon success
 * and 0 upon failure. */
int growDynamicArray(DynamicArray *dynamicArray);

/* Returns the value at the specified index without bounds checking. */
int getValueDynamicArray(DynamicArray *dynamicArray, unsigned int index);
/* Sets the value at the specified index without bounds checking. Does not increment
 * length. Does not grow DynamicArray. Only use it for mutating values within bounds. */
void setValueDynamicArray(DynamicArray *dynamicArray, unsigned int index, int value);
/* Pushes the value at the end of the array. Increments length. Grows DynamicArray. 
 * Returns 1 upon success and 0 upon failure (while growing). */
int pushValueDynamicArray(DynamicArray *dynamicArray, int value);
/* Pops a value off from the end of the array and returns it */
int popValueDynamicArray(DynamicArray *dynamicArray);
/* Inserts a value at the specified index by pushing existing values to the right.
 * Increments length. Grows DynamicArray. Returns 1 upon success and 0 upon failure
 * (while growing). */
int insertValueDynamicArray(DynamicArray *dynamicArray, unsigned int index, int value);
/* Removes a value at the specified index by pulling existing values to the left.
 * Returns the removed value. */
int removeValueDynamicArray(DynamicArray *dynamicArray, unsigned int index);

#endif
