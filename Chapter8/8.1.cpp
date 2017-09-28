#include <iostream>

//Write exception handling for this
int GetNthFibonacciNumber(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return GetNthFibonacciNumber(n - 1) + GetNthFibonacciNumber(n - 2);
	}
}

int main()
{
	std::cout << GetNthFibonacciNumber(1);
	std::cout << GetNthFibonacciNumber(2);
	std::cout << GetNthFibonacciNumber(23);
}
