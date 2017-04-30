#include <iostream>
#include <cstring>
#include <string>

int* NewContMatrix(int matrixSize)
{
	int* returnedPtr = malloc(matrixSize * matrixSize * sizeof(int));
	return returnedPtr;
}

int** NewMatrix(int matrixSize)
{
	int** returnedMatrix;
	returnedMatrix = new int*[matrixSize];
	for (int i = 0; i < matrixSize; ++i)
	{
		returnedMatrix[i] = new int[matrixSize];
	}
	return returnedMatrix;
}

int* RotateContSquareMatrix(int* inputMatrix, int matrixSize)
{
	//Write the method here :)
	int* returnedPtr;
	return returnedPtr;
}

int** RotateSquareMatrix(int** inputMatrix, int matrixSize)
{
	//Allocate memory for the returned matrix
	int** outputMatrix;
	outputMatrix = new int*[matrixSize];
	for (int i = 0; i < matrixSize; ++i)
	{
		outputMatrix[i] = new int[matrixSize];
	}
	
	//Fill the returned matrix with rotated values
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			outputMatrix[matrixSize - j - 1][i] = inputMatrix[i][j];
		}
	}
	return outputMatrix;
}	

	int main()
	{
		int** tablica;
		tablica = NewMatrix(4);
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				tablica[i][j] = i * j;
			}
		}
		
		
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				std::cout << tablica[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << "test" << std::endl;
		int** tatablica = RotateSquareMatrix(tablica, 4);
		
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				std::cout << tatablica[i][j];
			}
			std::cout << std::endl;
		}
		return 0;
	}
	
