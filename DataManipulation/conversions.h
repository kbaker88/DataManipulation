#ifndef CONVERSIONS_H
#define CONVERSIONS_H

int Math_Power(int Base, int Exponent)
{
	int Result = 1;
	while (Exponent)
	{
		if (Exponent & 1)
			Result *= Base;
		Exponent >>= 1;
		Base *= Base;
	}

	return Result;
}

static void Utility_FloatToChar(float Value, unsigned int Precision,
	char* ReturnBuffer)
{
	if (Value == 0.0f)
	{
		if (ReturnBuffer)
		{
			ReturnBuffer[0] = '0';
			ReturnBuffer[1] = '.';
			for (int i = 0; i < Precision; i++)
			{
				ReturnBuffer[2 + i] = '0';
			}
		}
		else
		{
			//TODO: Error, buffer is too small
			ReturnBuffer = 0;
		}
	}
	else if (Precision > 8)
	{
		//TODO: Error, doesn't support precision that high
		ReturnBuffer = 0;
	}
	else
	{
		union
		{
			float BitsAsFloat;
			unsigned int BitsAsInt;
		} FloatingPoint;

		FloatingPoint.BitsAsFloat = Value;
		const unsigned int MaxDigitSignificanBuffer = 9;
		unsigned int Index = 0;
		unsigned int DecimalResult = 0;
		unsigned int multiplier = 1;
		int IntegerLength = 0;

		bool ValueIsNegative = (FloatingPoint.BitsAsInt >> 31) != 0;

		if (ValueIsNegative)
		{
			ReturnBuffer[Index] = '-';
			Index++;
		}

		int Exponent = ((FloatingPoint.BitsAsInt &
			(255 << 23)) >> 23) - 127;
		unsigned int Significand =
			FloatingPoint.BitsAsInt & ((1 << 23) | 0x7FFFFF);

		// NOTE: If there is an integer component.
		if (Exponent >= 0)
		{
			int IntegerPart =
				((Significand >> (23 - Exponent)) | (1 << Exponent));

			char IntegerBuffer[MaxDigitSignificanBuffer] = {};

			// NOTE: Break down IntegerPart into a char buffer
			// NOTE: It will be read in backwards using remainders
			while ((IntegerPart > 0) && (IntegerLength < MaxDigitSignificanBuffer))
			{
				IntegerBuffer[IntegerLength] = (IntegerPart % 10) + 48;
				IntegerLength++;
				IntegerPart = IntegerPart / 10;
			}
			// NOTE: Reverse the integer char buffer and put into result char buffer
			// NOTE: This does not yet account for integers over 16777215.
			// TODO: Account for integers over 16777215 up to 3.4028230 × 10^38
			for (int i = IntegerLength - 1; i >= 0; i--)
			{
				ReturnBuffer[Index] = IntegerBuffer[i];
				Index++;
			}

			ReturnBuffer[Index] = '.';
			Index++;

			// NOTE: Calculate the decimal remainder and multiply it to fit into an integer
			for (int i = 23 - (Exponent + 1); i >= 0; i--)
			{
				// NOTE: If the significand's bit is set in position i
				if (Significand & (1 << i))
				{
					// NOTE: Decimal result += 1 / 2^(position after .) * 1000000000
					DecimalResult +=
						(int)((float)(1.0f / (float)Math_Power(2, multiplier))
							* 1000000000.0f);
				}
				multiplier++;
			}

		}
		else
		{
			// NOTE: There will be no integer value with a negative exponent
			ReturnBuffer[Index] = '0';
			Index++;
			IntegerLength++;
			ReturnBuffer[Index] = '.';
			Index++;

			// NOTE: This is the decimal value stored in the significand without exponent
			unsigned int DecimalValue = Significand | (1 << 23);

			// NOTE: Add the exponent to the multiplier to account for leading 0's
			//		 after the . but before the first set bit
			// NOTE: Subtraction because Exponent is negative
			multiplier -= (Exponent + 1);

			for (int i = 23; i >= 0; i--)
			{
				if (DecimalValue & (1 << i))
				{
					// TODO: Check the rounding errors on this calculation
					DecimalResult +=
						(int)((float)(1.0f / (float)Math_Power(2, multiplier))
							* 1000000000.0f);
				}
				multiplier++;
			}
		}

		// NOTE: Brute force method of displaying leading 0's 
		//		 after the . but before the first set bit
		// TODO: Find a cleaner solution
		if (DecimalResult < 100000000)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 10000000)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 1000000)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 100000)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 10000)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 1000)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 100)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 10)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}
		if (DecimalResult < 1)
		{
			ReturnBuffer[Index] = '0';
			Index++;
		}

		char DecimalBuffer[MaxDigitSignificanBuffer] = {};
		int DecimalLength = 0;
		// NOTE: Break down the Decimal value into a char buffer
		// NOTE: It will be read in backwards using remainders
		// NOTE: Error from this decimal length not taking into account
		//		 the leading 0's after the . and before the first set bit
		// TODO: Take into account the leader 0's into the decimal length
		while ((DecimalResult > 0) && (DecimalLength < MaxDigitSignificanBuffer))
		{
			DecimalBuffer[DecimalLength] = (DecimalResult % 10) + 48;
			DecimalLength++;
			DecimalResult = DecimalResult / 10;
		}

		if (DecimalLength)
		{
			// NOTE: Reverse the decimal char buffer into the result buffer
			for (int DecimalPosition = DecimalLength - 1;
				DecimalPosition >= (DecimalLength - (int)Precision);
				DecimalPosition--)
			{
				ReturnBuffer[Index] = DecimalBuffer[DecimalPosition];
				Index++;
			}
		}

		// NOTE: Include the integer and the decimal point into precision
		// NOTE: This is only referring to when float has a decimal value
		// TODO: Fix error with large integers past 16777215 where
		//		 precision treats it as having a decimal.
		int PrecisionLength = IntegerLength + 1 + (int)Precision;

		// NOTE: Take account for the negative sign in the precision length
		if (ValueIsNegative)
		{
			PrecisionLength++;
		}

		// NOTE: Round up starting from the precision length
		char* CarryOverPosition = &ReturnBuffer[PrecisionLength];
		if (*CarryOverPosition > '4')
		{
			while ((*CarryOverPosition > '4') && (PrecisionLength > 0))
			{
				*CarryOverPosition = '0';
				CarryOverPosition--;
				PrecisionLength--;
				if (*CarryOverPosition == '.')
				{
					CarryOverPosition--;
					PrecisionLength--;
				}
			}
			*CarryOverPosition = *CarryOverPosition + 1;
		}

		// NOTE: Cut off all values after the precision length
		for (int ExtraDecimals = PrecisionLength;
			ExtraDecimals < (int)Index;
			ExtraDecimals++)
		{
			ReturnBuffer[ExtraDecimals] = 0;
		}
	}
}

#endif
