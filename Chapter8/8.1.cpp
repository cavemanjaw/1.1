#include <iostream>

//Write exception handling for this
int GetNthFibonacciNumberRecursively(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n <= 2)
	{
		return 1;
	}
	else
	{
		return GetNthFibonacciNumberRecursively(n - 1) + GetNthFibonacciNumberRecursively(n - 2);
	}
}

int GetNthFibonacciNumber(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n <= 2)
	{
		return 1;
	}
	else
	{
		int nMinusTwoValue = 1;
		int nMinusOneValue = 1;
		int fibValue = nMinusTwoValue + nMinusOneValue;
		for (int i = 3; i < n; ++i)
		{
			nMinusTwoValue = nMinusOneValue;
			nMinusOneValue = fibValue;
			fibValue = nMinusTwoValue + nMinusOneValue;
		}
		return fibValue;
	}
}

int main()
{
	std::cout << GetNthFibonacciNumber(1);
	std::cout << GetNthFibonacciNumber(2);
	std::cout << GetNthFibonacciNumber(10);
}
