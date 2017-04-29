#ifndef PRACTICE_PROBLEMS_H
#define PRACTICE_PROBLEMS_H

#include "sort.h"

// NOTE: Assumes strings are null terminate
// NOTE: Assumes input can not be modified
// NOTE: If modifiable, sort on no data structs
//		 sort on permutation tests.
bool Practice_StringAllUnique(char* CharString);
bool Practice_StringAllUnique(unsigned short* UnicodeString);
void Practice_StringReverse(char* CharString);
void Practice_StringReverse(unsigned short* UnicodeString);
bool Practice_StringIsPermutation(char* CharStringA,
	char* CharStringB);
bool Practice_StringIsPermutation(unsigned short* UnicodeStringA,
	unsigned short* UnicodeStringB);
void Practice_StringReplaceSpaces(char* CharString);
void Practice_StringBasicCompress(char* CharString);

// TODO 
void Practice_StringRotateMatrix90(char* NbyNMatrix); // can you do in place?
void Practice_StringMatrixZeroRowColumn(char* MbyNMatrix);
bool Practice_StringIsSubstring(char* CharStringA, char* CharStringB);
bool Practice_StringIsRotation(char* CharStringA, char* CharStringB);
#endif
