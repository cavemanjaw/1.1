#include <vector>
#include <iostream>

std::vector<int> MergeVectorBIntoA(std::vector<int>& a, const std::vector<int>& b)
{
	std::vector<int>::iterator aItr = a.begin();
	std::vector<int>::const_iterator bItr = b.begin();
	std::vector<int> outputVector;

	while (aItr != a.end() && bItr != b.end())
	{
		if (*aItr < *bItr)
		{
			outputVector.push_back(*aItr);
			++aItr;
		}
		else if (*aItr == *bItr)
		{
			outputVector.push_back(*aItr);
			outputVector.push_back(*aItr);
			++aItr;
			++bItr;
		}
		else
		{
			outputVector.push_back(*bItr);
			++bItr;
		}
	}
	return outputVector;
}

int main()
{

	return 0;
}
