#include <iostream>
#include "sort.h"
#include "datastructures.h" 
#include "algorithms.h"
#include "conversions.h"

#include <stdio.h>

using namespace std;

int main()
{

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


	int IntArray[20];
	IntArray[0] = 8;
	IntArray[1] = 23;
	IntArray[2] = 9;
	IntArray[3] = 1;
	IntArray[4] = 85;
	IntArray[5] = 3465;
	IntArray[6] = 3; 
	IntArray[7] = 9;
	IntArray[8] = 0;
	IntArray[9] = 12;

	IntArray[10] = 13;
	IntArray[11] = 53;
	IntArray[12] = 5;
	IntArray[13] = 7;
	IntArray[14] = 6;
	IntArray[15] = 743;
	IntArray[16] = 43;
	IntArray[17] = 23;
	IntArray[18] = 85;
	IntArray[19] = -1;

	QuickSort(IntArray, 0, 19);
	//MergeSort(IntArray, 20);

	for (unsigned int i = 0; i < 20; i++)
	{
		cout << IntArray[i] << " ";
	}
	cout << endl;

	int graph[MaxVNumber][MaxVNumber] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	int Result[9] = {};
	Algorithm_Dijkstras(graph, 0, Result);

	for (int i = 0; i < MaxVNumber; i++)
	{
		cout << Result[i] << " ";
	}

	cout << endl;

	system("pause");

	return 0;
}