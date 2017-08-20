unsigned SwapOddAndEvenBits(unsigned variable)
{
	unsigned secondMask = 0xAAAAAAAAU;
	unsigned firstMask = 0x55555555U;
	
	return ((variable & secondMask) >> 1) | ((variable & firstMask) << 1);
}

int main()
{

return 0;
}