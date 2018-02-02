#include <iostream>

bool FindElement(int** array, int element, int* M, int *N)
{
	int arrayN = *N;
	*N = 0;
	*M = *M - 1;
	while (*N < arrayN && *M >=0)
	{
		if (array[*N][*M] == element)
		{
			return true;
		}
		else if (array[*N][*M] > element)
		{
			--M;
		}
		else
		{
			++N;
		}
	}
}

int main()
{
	return 0;
}
