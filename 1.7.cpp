#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>


//the best solution is to go through an array, at the end of loop, if there was encountered zero, replace whole line with zeros, during iteration we can store values of column and set accordingly, but there must be a loop for setting the prevoius column to zero, but they should be ignored during next passes! 

typedef std::vector<std::vector<int>> Array;

void RandomFillArray(Array& array)
{
    for (auto& row: array)
    {
        for(auto& element: row)
        {
            element = rand();
        }
    }
}

void PrintArray(const Array& array)
{
for (auto row: array)
    {
        for (auto element: row)
        {
            std::cout << element;
        }
        std::cout << std::endl;
    }
}

//Template this
//The logic of filling with zeros could be inversed for optimisation
void SetZeros(Array& array)
{
	std::vector<std::pair<int, int>> zerosCoordinates;
	int rowSize = array.size();

	//Assumption that those outer vectors are the same length
	int columnSize = array.at(0).size();

	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = 0; j < columnSize; ++j)
		{
			if (array[i][j] == 0)
			{
				zerosCoordinates.push_back(std::make_pair(i, j));
			}
		}
	}
	
	//Set rows to zeros
	for (auto element: zerosCoordinates)
	{
		array.at(element.first) = std::vector<int>(columnSize, 0);
	}

	//Set columns to zero
	for (auto element: zerosCoordinates)
	{
		//Iterate over rows
		for (int i = 0; i < rowSize; ++i)
		{
			array.at(i).at(element.second) = 0;
		}
	}
}

int main()
{
    Array araj;
    araj.resize(5);
    for (int i = 0; i < 5; ++i)
    {
        araj.at(i).resize(5);
    }
    RandomFillArray(araj);
    
    PrintArray(araj);
    
    return 0;
}