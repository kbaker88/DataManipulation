#include "practice_problems.h"

#define NO_ADDITIONAL_DATA_STRUCTS 1

bool Practice_StringAllUnique(char* CharString)
{
#if NO_ADDITIONAL_DATA_STRUCTS
	if (CharString)
	{
		char* StringItr = CharString + 1;
		while (*CharString)
		{
			while (*StringItr)
			{
				if (*CharString == *StringItr)
				{
					return false;
				}
				StringItr++;
			}
			CharString++;
			StringItr = CharString + 1;
		}
		return true;
	}
	else
	{
		return false;
	}
#else
	if (CharString)
	{
		bool Glyphs[256] = {};
		while (*CharString)
		{
			if (Glyphs[*CharString])
			{
				return false;
		}
			else
			{
				Glyphs[*CharString] = true;
			}
			CharString++;
	}
		return true;
	}
	else
	{
		return false;
	}
#endif

	return false;
}

bool Practice_StringAllUnique(unsigned short* UnicodeString)
{
#if NO_ADDITIONAL_DATA_STRUCTS
	if (UnicodeString)
	{
		unsigned short* StringItr = UnicodeString + 1;
		while (*UnicodeString)
		{
			while (*StringItr)
			{
				if (*UnicodeString == *StringItr)
				{
					return false;
				}
				StringItr++;
			}
			UnicodeString++;
			StringItr = UnicodeString + 1;
		}
		return true;
	}
	else
	{
		return false;
	}
#else
	if (UnicodeString)
	{
		bool Glyphs[0xFFFF] = {};
		while (*UnicodeString)
		{
			if (Glyphs[*UnicodeString])
			{
				return false;
		}
			else
			{
				Glyphs[*UnicodeString] = true;
			}
			UnicodeString++;
	}
		return true;
	}
	else
	{
		return false;
	}
#endif

	return false;
}

void Practice_StringReverse(char* CharString)
{
	if (CharString)
	{
		char* StringItr = CharString;
		while (*StringItr)
			StringItr++;
		StringItr--;

		while (CharString < StringItr)
			*CharString++ ^= (*StringItr-- ^= (*CharString ^= *StringItr));
	}
}

void Practice_StringReverse(unsigned short* UnicodeString)
{
	if (UnicodeString)
	{
		unsigned short* StringItr = UnicodeString;
		while (*StringItr)
		{
			StringItr++;
		}
		StringItr--;

		while (UnicodeString < StringItr)
		{
			// NOTE: Swap and increment UnicodeString and StringItr
			*UnicodeString++ ^= (*StringItr-- ^= (*UnicodeString ^= *StringItr));
		}
	}
}

bool Practice_StringIsPermutation(char* CharStringA,
	char* CharStringB)
{
#if NO_ADDITIONAL_DATA_STRUCTS
	if (CharStringA && CharStringB)
	{
		char* StringEnd = CharStringA;
		int Index = 0;
		while (*StringEnd)
		{
			StringEnd++;
			Index++;
		}
		StringEnd--;

		if (CharStringB[Index] == 0)
		{
			Sort_QuickSort(CharStringA, 0, Index - 1);
			Sort_QuickSort(CharStringB, 0, Index - 1);

			while (Index >= 0)
			{
				if (CharStringA[Index] != CharStringB[Index])
				{
					return false;
				}
				Index--;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
#else
	if (CharStringA && CharStringB)
	{
		int CharCount[256] = {};
		unsigned int Length = 0;
		while (*CharStringA)
		{
			CharCount[*CharStringA]++;
			CharStringA++;
			Length++;
		}
		if (!*(CharStringB + Length))
		{
			while (*CharStringB)
			{
				if ((--CharCount[*CharStringB]) < 0)
				{
					return false;
				}
				else
				{
					CharStringB++;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
#endif

	return false;
}

bool Practice_StringIsPermutation(unsigned short* UnicodeStringA,
	unsigned short* UnicodeStringB)
{
#if NO_ADDITIONAL_DATA_STRUCTS
	if (UnicodeStringA && UnicodeStringB)
	{
		unsigned short* StringEnd = UnicodeStringA;
		int Index = 0;
		while (*StringEnd)
		{
			StringEnd++;
			Index++;
		}
		StringEnd--;

		if (UnicodeStringB[Index] == 0)
		{
			Sort_QuickSort(UnicodeStringA, 0, Index - 1);
			Sort_QuickSort(UnicodeStringB, 0, Index - 1);

			while (Index >= 0)
			{
				if (UnicodeStringA[Index] != UnicodeStringB[Index])
				{
					return false;
				}
				Index--;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
#else
	if (UnicodeStringA && UnicodeStringB)
	{
		int UnicodeGlyphCount[0xFFFF] = {};
		unsigned int Length = 0;
		while (*UnicodeStringA)
		{
			UnicodeGlyphCount[*UnicodeStringA]++;
			UnicodeStringA++;
			Length++;
		}
		if (!*(UnicodeStringB + Length))
		{
			while (*UnicodeStringB)
			{
				if ((--UnicodeGlyphCount[*UnicodeStringB]) < 0)
				{
					return false;
				}
				else
				{
					UnicodeStringB++;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
#endif

	return false;
}

void Practice_StringReplaceSpaces(char* CharString)
{
	if (CharString)
	{
		char* CharStringEnd = CharString;
		while (*CharStringEnd)
		{
			CharStringEnd++;
		}
		CharStringEnd--;

		char* CharStringItr = CharStringEnd;
		while (*CharStringItr == ' ')
		{
			CharStringItr--;
		}
		while (CharStringItr > CharString)
		{
			if (*CharStringItr == ' ')
			{
				*CharStringEnd = '0';
				CharStringEnd--;
				*CharStringEnd = '2';
				CharStringEnd--;
				*CharStringEnd = '%';
				CharStringEnd--;
				CharStringItr--;
			}
			else
			{
				*CharStringEnd = *CharStringItr;
				CharStringItr--;
				CharStringEnd--;
			}
		}
	}
}

void Practice_StringReplaceSpaces(unsigned short* UnicodeString)
{
	if (UnicodeString)
	{
		unsigned short* UnicodeStringEnd = UnicodeString;
		while (*UnicodeStringEnd)
		{
			UnicodeStringEnd++;
		}
		UnicodeStringEnd--;

		unsigned short* UnicodeStringItr = UnicodeStringEnd;
		while (*UnicodeStringItr == ' ')
		{
			UnicodeStringItr--;
		}
		while (UnicodeStringItr > UnicodeString)
		{
			if (*UnicodeStringItr == ' ')
			{
				*UnicodeStringEnd = '0';
				UnicodeStringEnd--;
				*UnicodeStringEnd = '2';
				UnicodeStringEnd--;
				*UnicodeStringEnd = '%';
				UnicodeStringEnd--;
				UnicodeStringItr--;
			}
			else
			{
				*UnicodeStringEnd = *UnicodeStringItr;
				UnicodeStringItr--;
				UnicodeStringEnd--;
			}
		}
	}
}

// aabbbcceeddda = a2b3c2e2d3a1
// abdddccceee = a1b1d3c3e3
// abcd = a1b1c1d1

void Practice_StringBasicCompress(char* CharString)
{
	if (CharString && (CharString + 1))
	{
		char* CharStringEnd = CharString;
		while (*CharStringEnd)
		{
			CharStringEnd++;
		}
		CharStringEnd--;

		char *CompressedCharString = new char[CharStringEnd - CharString]{};
		CompressedCharString[0] = *CharString;
		int CompressedItr = 1;
		char* CharItr = CharString + 1;
		int Count = 1;
		while (*CharString)
		{
			if (*CharString == *CharItr)
			{
				Count++;
				CharItr++;
			}
			else
			{
				CompressedCharString[CompressedItr] = Count;
				CompressedItr++;
				CompressedCharString[CompressedItr] = *CharItr;
				CompressedItr++;
				Count = 1;
				CharString = CharItr;
				CharItr++;
			}
		}

		int x = 0;
		delete[] CompressedCharString;
	}
}