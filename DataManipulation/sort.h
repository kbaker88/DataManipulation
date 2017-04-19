#ifndef SORT_H
#define SORT_H

void QuickSort_Swap(int* A, int* B)
{
	int C = *A;
	*A = *B;
	*B = C;
}

unsigned int QuickSort_Partition(int* Arr,
	unsigned int Start, unsigned int End)
{
	unsigned int Index = Start;
	int Pivot = Arr[End];
	 
	for (unsigned int i = Start; i < End; i++)
	{
		if (Arr[i] <= Pivot)
		{
			QuickSort_Swap(&Arr[i], &Arr[Index]);
			Index++;
		}
	}
	QuickSort_Swap(&Arr[Index], &Arr[End]);

	return Index;
}

void QuickSort(int* Arr, unsigned int Start,
	unsigned int End)
{
	if (Start < End)
	{
		unsigned int Index = QuickSort_Partition(Arr, Start, End);
		if (Index)
		{
			QuickSort(Arr, Start, Index - 1);
		}
		QuickSort(Arr, Index + 1, End);
	}
}

void MergeSort_Merge(int* Left, unsigned int LeftLength,
	int* Right, unsigned int RightLength, int* Arr)
{
	unsigned int LeftArrIndex = 0;
	unsigned int RightArrIndex = 0;
	unsigned int ArrIndex = 0;

	while (LeftArrIndex<LeftLength && RightArrIndex< RightLength)
	{
		if (Left[LeftArrIndex] < Right[RightArrIndex])
		{
			Arr[ArrIndex++] = Left[LeftArrIndex++];
		}
		else
		{
			Arr[ArrIndex++] = Right[RightArrIndex++];
		}
	}
	while (LeftArrIndex < LeftLength)
	{
		Arr[ArrIndex++] = Left[LeftArrIndex++];
	}
	while (RightArrIndex < RightLength)
	{
		Arr[ArrIndex++] = Right[RightArrIndex++];
	}

}

int* MergeSort(int* Arr, unsigned int Length)
{
	if (Length < 2)
	{
		return Arr;
	}
	unsigned int Middle = Length / 2;
	int* Left = new int[Middle];
	int* Right = new int[Length - Middle];
	for (unsigned int i = 0; i < Middle; i++)
	{
		Left[i] = Arr[i];
	}
	for (unsigned int i = Middle; i < Length; i++)
	{
		Right[i - Middle] = Arr[i];
	}
	MergeSort(Left, Middle);
	MergeSort(Right, Length - Middle);
	MergeSort_Merge(Left, Middle, Right, Length - Middle, Arr);
	delete[] Left;
	delete[] Right;
}

#endif