#include <stdio.h>

#include "DynamicArray.h"

void printDynamicArray(DynamicArray *dynamicArray)
{
	printf("Capacity: %d\n", dynamicArray->capacity);
	printf("Length: %d\n", dynamicArray->length);

	for (int counter = 0; counter < dynamicArray->length; counter++)
		printf("%d: %d\n", counter, getValueDynamicArray(dynamicArray, (unsigned int)counter));

	printf("\n");
}

int main(void)
{
	printf("Initial DynamicArray\n");
	DynamicArray *dynamicArray = createDynamicArray(2);

	printDynamicArray(dynamicArray);

	printf("Adding 10 integers\n");
	for (int counter = 0; counter < 10; counter++)
	{
		pushValueDynamicArray(dynamicArray, counter);
	}
	printDynamicArray(dynamicArray);

	printf("Popping 5 integers\n");
	for (int counter = 0; counter < 5; counter++)
	{
		popValueDynamicArray(dynamicArray);
	}
	printDynamicArray(dynamicArray);

	printf("Inserting 99 at index 2\n");
	insertValueDynamicArray(dynamicArray, 2, 99);
	printDynamicArray(dynamicArray);

	printf("Removing value at index 2\n");
	removeValueDynamicArray(dynamicArray, 2);
	printDynamicArray(dynamicArray);

	printf("Setting value at index 2 to 99\n");
	setValueDynamicArray(dynamicArray, 2, 99);
	printDynamicArray(dynamicArray);

	printf("Growing DynamicArray\n");
	growDynamicArray(dynamicArray);
	printDynamicArray(dynamicArray);

	printf("Destroying DynamicArray\n");
	destroyDynamicArray(dynamicArray);

	return 0;
}
