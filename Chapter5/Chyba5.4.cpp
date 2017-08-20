int BitsTogglingRequiredToConvertCounting(unsigned A, unsigned B)
{
	int counter = 0;

	//Get rightmost bit set position
	//TODO: Unsigned type needed here?
	int pos = A ^ (A & (A-1));

	//Variable for comparing the value of searched number
	unsigned testValue = A;

	for (int i = pos; i >= 0; --i)
	{
		if ((testValue ^ (1 << i)) < B)
		{
			continue;
		}
		else
		{
			++counter;
			testValue ^= (1 << i);
		}

	}
	return counter;
}

//Alternative, probably much faster version
int BitsTogglingRequiredToConvertXor(unsigned A, unsigned B)
{
	int counter = 0;
	for (unsigned xorOutcome = A ^ B; xorOutcome != 0; c >>= !)
	{
		counter += xorOutcome & 1U;
	}
	return counter;
}
