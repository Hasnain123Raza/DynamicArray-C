#include "DynamicArray.h"

void terminate(const char *message)
{
	printf("%s", message);
	exit(EXIT_FAILURE);
}



DynamicArray *createDynamicArray(unsigned int initialCapacity)
{
	DynamicArray *dynamicArray = (DynamicArray*) malloc(sizeof(DynamicArray));

	if (!dynamicArray)
		return NULL;

	int *data = (int*) calloc(initialCapacity, sizeof(int));

	if (!data)
	{
		free(dynamicArray);
		return NULL;
	}

	dynamicArray->capacity = initialCapacity;
	dynamicArray->length = 0;
	dynamicArray->data = data;

	return dynamicArray;
}

void destroyDynamicArray(DynamicArray *dynamicArray)
{
	free(dynamicArray->data);
	free(dynamicArray);
}

int growDynamicArray(DynamicArray *dynamicArray)
{
	int newCapacity = dynamicArray->capacity * 2;

	int *newData = (int*) calloc(newCapacity, sizeof(int));

	if (!newData)
	{
		free(newData);
		return 0;
	}

	int *oldData = dynamicArray->data;
	for (int counter = 0; counter < dynamicArray->capacity; counter++)
		*(newData + counter) = *(oldData + counter);

	free(oldData);
	dynamicArray->data = newData;
	dynamicArray->capacity = newCapacity;

	return 1;
}



int getValueDynamicArray(DynamicArray *dynamicArray, unsigned int index)
{
	if (index >= dynamicArray->length)
		terminate("Attempt to get value at an index out of bounds\n");

	return *(dynamicArray->data + index);
}

void setValueDynamicArray(DynamicArray *dynamicArray, unsigned int index, int value)
{
	if (index >= dynamicArray->length)
		terminate("Attempt to set value at an index out of bounds\n");

	*(dynamicArray->data + index) = value;
}

int pushValueDynamicArray(DynamicArray *dynamicArray, int value)
{
	if (dynamicArray->length == dynamicArray->capacity)
		if (!growDynamicArray(dynamicArray))
			return 0;

	*(dynamicArray->data + dynamicArray->length) = value;
	dynamicArray->length++;
	return 1;
}

int popValueDynamicArray(DynamicArray *dynamicArray)
{
	if (dynamicArray->length == 0)
		terminate("Attempt to pop an empty list\n");

	int poppedValue = *(dynamicArray->data + dynamicArray->length - 1);
	dynamicArray->length--;

	return poppedValue;
}

int insertValueDynamicArray(DynamicArray *dynamicArray, unsigned int index, int value)
{
	if (index > dynamicArray->length)
		terminate("Attempt to insert value at an index out of bounds\n");

	if (dynamicArray->length == dynamicArray->capacity)
		if (!growDynamicArray(dynamicArray))
			return 0;

	int *data = dynamicArray->data;
	for (int counter = dynamicArray->length + 1; counter > index; counter--)
		*(data + counter) = *(data + counter - 1);

	*(data + index) = value;
	dynamicArray->length++;
	return 1;
}

int removeValueDynamicArray(DynamicArray *dynamicArray, unsigned int index)
{
	if (index >= dynamicArray->length)
		terminate("Attempt to remove value at an index out of bounds\n");

	int *data = dynamicArray->data;
	int removedValue = *(data + index);

	for (int counter = index; counter < dynamicArray->length - 1; counter++)
	       *(data + counter) = *(data + counter + 1);

	dynamicArray->length--;
	return removedValue;	
}
