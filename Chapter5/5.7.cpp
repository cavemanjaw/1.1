unsigned FetchBit(unsigned variable, int bitPosition)
{
	return variable & (1U << bitPosition);
}

unsigned ReturnMissingInteger(unsigned* integerTable, int tableSize)
{
	bool isPreviousBitSet = FetchBit(integerTable[0], 0);
	bool isCurrentBitSet;
	
	for (int i = 1; i < tableSize; ++i)
	{
		isCurrentBitSet = FetchBit(integerTable[i], 0);
		if (isPreviousBitSet == isCurrentBitSet)
		{
			//Found, return
			//Check all the bits of this int and construct output value
		}
		else
		{
			isPreviousBitSet = isCurrentBitSet;
		}
	}
}

int main()
{
	//I think that there is a way to do it with XOR
	//Oh, wait. I'm supposed to fetch only one jth bit...
	return 0;
}
