#include <iostream>
#include <Windows.h>

#include "sort.h"
#include "datastructures.h" 
#include "algorithms.h"
#include "conversions.h"
#include "memory.h"
#include "bitmanipulation.h"
#include "practice_problems.h"

#include <stdio.h>

using namespace std;

#define KB 1024
#define MB (KB * KB)
#define GB (MB * KB)

// MEMORY_ALLOCATION
// BIT_MANIPULATION
// TYPE_CONVERSIONS
// SORT_ALGORITHMS
// GRAPH_ALGORITHMS
// PRACTICE_PROBLEMS

int main()
{
	///////////////////////////////////////////////////////
	// MEMORY_ALLOCATION
#if 0
	_SYSTEM_INFO SystemInfo;

	GetSystemInfo(&SystemInfo);
	unsigned int NumberOfPages = GB / SystemInfo.dwPageSize;

	Memory = VirtualAlloc(0, NumberOfPages * SystemInfo.dwPageSize,
		MEM_COMMIT, PAGE_READWRITE);

	Test *Testing = (Test*)Memory;
	Testing->x = 10;
	Testing->y = 1024;
	Testing->z = 2;
	Testing->a = 'a';
	MemPtr = (char*)Memory + sizeof(Test);

	Test *Testing2 = (Test*)MemPtr;
	Testing2->a = 'c';
	Testing2->x = 2;
	Testing2->y = 8;
	Testing2->z = 16;
	MemPtr = (char*)MemPtr + sizeof(Test);

	char* CharTest = Memory_AllocateCharArr(12);
	CharTest[0] = 'a';
	CharTest[1] = 'b';
	CharTest[2] = 'c';
	CharTest[3] = 'd';
	CharTest[11] = 'z';

	int *IntTest = Memory_AllocateIntArr(64);
	IntTest[64] = 0xFFFFFFFF;
	IntTest[0] = 0xFFFFFFFF;
	IntTest[32] = 100;
	float *FloatTest = Memory_AllocateFloatArr(64);
	FloatTest[0] = -100.0524f;
	FloatTest[64] = -100.0524f;

	char* Ending = (char *)MemPtr;
	*Ending = 'E';

	VirtualFree(Memory, NumberOfPages * SystemInfo.dwPageSize, 
		MEM_RELEASE);
#endif
	///////////////////////////////////////////////////
	// BIT_MANIPULATION
#if 0
	unsigned long long Value = 202;

	int *x = new int[2]{};
	x[0] = 1;
	x[1] = 2;

	int* y = x;
	for (int i = 0; i < 5; i++)
	{
		if (y)
		{
			cout << x[i] << endl;
		}
		y++;
	}
	delete[] x;
	cout << (Value & 0xF) << endl;
	cout << ((Value & 0xF0) >> 4) << endl;

	int * TestPtr = Bit_ReturningPointer();
	Bit_PointerParam(&TestPtr);
	//Bit_PointerParam(&Bit_ReturningPointer()); // ERROR
	delete TestPtr;

	int z = 2;
	int c = 3;

	z ^= (c ^= (z ^= c));


	cout << p << " " << o << endl;

	cout << z << " " << c << endl;

	int solution = (int)&((char*)z)[c];
	cout << solution << endl;

#endif
	//////////////////////////////////////////////////
	// TYPE_CONVERSIONS
#if 0
	char Buffer[16] = {};
	float Float = 0.0f;

	Utility_FloatToChar(Float, 3, Buffer);

	for (unsigned int i = 0; i < 16; i++)
	{
		cout << Buffer[i];
	}
	cout << endl << endl;

	char FloatToCharBuffer[16] = {};

	_snprintf_s(FloatToCharBuffer, sizeof(FloatToCharBuffer),
		"%0.1f", Float); // ms/f
	for (unsigned int i = 0; i < 16; i++)
	{
		cout << FloatToCharBuffer[i];
	}
	cout << endl << endl;
#endif
	/////////////////////////////////////////////////
	// SORT_ALGORITHMS
#if 1
	int IntArray[20] = { 8, 23, 9, 1, 85, 
		3465, 3, 9, 0, 12, 13, 53, 5, 7,
		6, 743, 43, 23, 85, -1 };

	char CharArray[6] = { 'd', 'c', 'a', 'b', 'f', 'e' };

	Sort_QuickSort(IntArray, 0, 19);
	Sort_QuickSort(CharArray, 0, 5);
	//Sort_MergeSort(IntArray, 20);
	for (unsigned int i = 0; i < 6; i++)
	{
		cout << CharArray[i] << " ";
	}
	cout << endl;

	for (unsigned int i = 0; i < 20; i++)
	{
		cout << IntArray[i] << " ";
	}
	cout << endl;
#endif
	////////////////////////////////////////////////////
	// GRAPH_ALGORITHMS
#if 0
	int graph[MaxVNumber][MaxVNumber] = 
	{ 
	{ 0,  4,  0,  0,  0,  0,  0,  8,  0 },
	{ 4,  0,  8,  0,  0,  0,  0, 11,  0 },
	{ 0,  8,  0,  7,  0,  4,  0,  0,  2 },
	{ 0,  0,  7,  0,  9, 14,  0,  0,  0 },
	{ 0,  0,  0,  9,  0, 10,  0,  0,  0 },
	{ 0,  0,  4, 14, 10,  0,  2,  0,  0 }, 
	{ 0,  0,  0,  0,  0,  2,  0,  1,  6 },
	{ 8, 11,  0,  0,  0,  0,  1,  0,  7 },
	{ 0,  0,  2,  0,  0,  0,  6,  7,  0 }
	};

	int Result[9] = {};
	Algorithm_Dijkstras(graph, 0, Result);

	for (int i = 0; i < MaxVNumber; i++)
	{
		cout << Result[i] << " ";
	}

	cout << endl;
#endif
	//////////////////////////////////////////////////////
	// PRACTICE_PROBLEMS
#if 1

	if (Practice_StringAllUnique("Ttsting\0"))
	{
		cout << "Character string is unique" << endl;
	}
	else
	{
		cout << "Character string is not unique" << endl;
	}

	unsigned short UnicodeString[6] = {'c', 'a', 't', 0x0FFF, 0x054F, 0};
	if (Practice_StringAllUnique(UnicodeString))
	{
		cout << "Unicode string is unique" << endl;
	}
	else
	{
		cout << "Unicode string is not unique" << endl;
	}

	char CharString[4] = { 'c', 'a', 't', 0 };
	Practice_StringReverse(CharString);
	for (unsigned int i = 0; i < 4; i++)
		cout << CharString[i];
	cout << endl;

	char CharStringA[5] = { 'v', 'b', 'a', 'd', '\0' };
	char CharStringB[5] = { 'd', 'v', 'a', 'b', '\0' };

	if (Practice_StringIsPermutation(CharStringA, CharStringB))
	{
		cout << "Character String B is a permutation of Character String A" << endl;
	}
	else
	{
		cout << "Character String B is not a permutation of Character String A" << endl;
	}

	char CharStringReplace[23] = { 'T', 'e', 's', 't', 'i', 'n', 'g', ' ',
		't', 'h', 'i', 's', ' ', 's', 't', 'r', 'i', 'n', 'g', ' ', ' ', ' ', ' '};
	Practice_StringReplaceSpaces(CharStringReplace);
	cout << CharStringReplace << endl;
#endif
	//////////////////////////////////////////////////////

	system("pause");
	return 0;
}