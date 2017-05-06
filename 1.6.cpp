#include <iostream>
#include <cstring>
#include <string>

int* NewContMatrix(int matrixSize)
{
	int* returnedPtr = malloc(matrixSize * matrixSize * sizeof(int));
	return returnedPtr;
}

//Zaokr¹glanie do góry potrzebne!
int* New4BitMatrix(int matrixSize)
{	
	int* returnedMatrix = malloc(matrixSize * (matrixSize / 2) + (matrixSize % 2));	
	return returnedMatrix;
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
	int* returnedPtr = NewContMatrix(matrixSize);
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			retrunedPtr[((matrixSize - j - 1) * matrixSize) + i] = inputMatrix[(i * matrixSize) + j];	
		}
	}
	return returnedPtr;
}

//For accessing specific element in 4bit array
int Access4BitMatrix(int* matrix, int matrixSize, int row, int column)

//Funkcja obliczaj¹ca, który int

//Funkcja obliczaj¹ca i ile przesun¹c tego inta

int* RotateMatrix4Bits(int* inputMatrix, int matrixSize)
{
	int* retrunedMatrix = New4BitMatrix(matrixSize);
	int sizeInInts = (matrixSize / 8) + (matrixSize % 2);

	//Loop over all the elements?
	for (int i = 0; i < matrixSize * matrixSize; ++i)
	{
		
	}
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
	
