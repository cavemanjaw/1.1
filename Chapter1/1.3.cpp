#include <iostream>

void RemoveDuplicates(char* string)
{
	char* innerItr;
	char* outerItr = string;
	
	while (*outerItr)
	{
		innerItr = outerItr + 1;
		while (*innerItr)
		{
			if (*outerItr == *innerItr)
			{
				char* removeItr = innerItr;
				while (*removeItr)
				{
					*removeItr = *(removeItr + 1);
					++removeItr;
				}
				--innerItr;
			}
			++innerItr;		
		}
		++outerItr;
	}
}

int main()
{
    char zmienna[] = "Dupadupdup";
    std::cout << zmienna; 
    RemoveDuplicates(zmienna);
    std::cout << zmienna;
}