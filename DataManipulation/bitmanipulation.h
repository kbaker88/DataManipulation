#ifndef BITMANIPULATION_H
#define BITMANIPULATION_H

int* Bit_ReturningPointer()
{
	int* x = new int;
	return x;
}

void Bit_PointerParam(int** TestPtr)
{
	int *NewPtr = *TestPtr;

	int y = 0;
}

#endif