#ifndef MEMORY_H
#define MEMORY_H

struct Test
{
	int x, y, z;
	char a;
};

void* Memory = 0;
void* MemPtr = Memory;

char* Memory_AllocateCharArr(unsigned int Size)
{
	char *Start = (char*)MemPtr;
	char *End = Start + Size;
	*End = '\0';
	MemPtr = End + 1;
	return Start;
}

#endif