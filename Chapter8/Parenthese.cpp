#include <cstring>
#include <string>
#include <climits>
#include <assert.h>

class ParentheseClass
{
public:
	ParentheseClass(int nrOfParentheses):
		numberOfLeftAllocableParentheses(nrOfParentheses - 1),
		numberOfRightAllocableParentheses(nrOfParentheses),
		string(nullptr),
		numberOfRightAllocatedParentheses(0),
		numberOfLeftAllocatedParentheses(1)
	{
		// Calculate the size of allocation for string, two times the nrOfParentheses
		int allocationSize = 2 * nrOfParentheses;

		// nrOfParentheses times two, we must fit left and right ones
		string = new char[allocationSize];

		// The actual size for heap-allocated string
		allocatedStringSize = allocationSize;

		// Insert the initial left parenthese
		string[0] = '(';
	}

	ParentheseClass():
		string(nullptr),
		allocatedStringSize(0)
	{
	}

	ParentheseClass(const ParentheseClass& rhs):
		string(nullptr),
		allocatedStringSize(rhs.allocatedStringSize)
	{
		// Could be in constructor initializer list
		numberOfLeftAllocableParentheses = rhs.numberOfLeftAllocableParentheses;
		numberOfRightAllocableParentheses = rhs.numberOfRightAllocableParentheses;
		numberOfRightAllocatedParentheses = rhs.numberOfRightAllocatedParentheses;
		numberOfLeftAllocatedParentheses = rhs.numberOfLeftAllocatedParentheses;
	
		if (rhs.string != nullptr)
		{
			string = new char[rhs.allocatedStringSize];
			strcpy(string, rhs.string);
		}
	}
	
	// Write it in a way that won't have to check for self-assignment
	ParentheseClass& operator=(const ParentheseClass& rhs)
	{
		allocatedStringSize = rhs.allocatedStringSize;
		numberOfLeftAllocableParentheses = rhs.numberOfLeftAllocableParentheses;
		numberOfRightAllocableParentheses = rhs.numberOfRightAllocableParentheses;
		numberOfRightAllocatedParentheses = rhs.numberOfRightAllocatedParentheses;
		numberOfLeftAllocatedParentheses = rhs.numberOfLeftAllocatedParentheses;
		
		if (&rhs != this)
		{
			delete[] string;
			string = new char[rhs.allocatedStringSize];
			strcpy(string, rhs.string);
		}
		return *this;
	}

	~ParentheseClass()
	{
		delete string;
	}

	void Invalidate()
	{
		string = nullptr;
	}

	void AddLeftParenthese()
	{
		assert(numberOfLeftAllocableParentheses > 0);
		
		int locationToPutParenthese = 
			numberOfLeftAllocatedParentheses + numberOfRightAllocatedParentheses;
		
		// Assert when we cannot fit the parenthese in allocated array
		assert(allocatedStringSize - 1 >= locationToPutParenthese);
		
		string[numberOfLeftAllocatedParentheses + numberOfRightAllocatedParentheses] = '(';
		--numberOfLeftAllocableParentheses;
		++numberOfLeftAllocatedParentheses;
	}
	
	void AddRightParenthese()
	{
		assert(numberOfRightAllocableParentheses > 0);

		int locationToPutParenthese = 
			numberOfLeftAllocatedParentheses + numberOfRightAllocatedParentheses;
		
		// Assert when we cannot fit the parenthese in allocated array
		assert(allocatedStringSize - 1 >= locationToPutParenthese);
		
		string[numberOfLeftAllocatedParentheses + numberOfRightAllocatedParentheses] = ')';
		--numberOfRightAllocableParentheses;
		++numberOfRightAllocatedParentheses;
	}

	int GetAllocableRight()
	{
		return numberOfRightAllocableParentheses;
	}
	
	int GetAllocableLeft()
	{
		return numberOfLeftAllocableParentheses;
	}

	int NumberOfLeftParentheses()
	{
		return numberOfLeftAllocatedParentheses;
	}
	
	int NumberOfRightParentheses()
	{
		return numberOfRightAllocatedParentheses;
	}
	
private:
	int numberOfLeftAllocableParentheses;
	int numberOfRightAllocableParentheses;
	int numberOfRightAllocatedParentheses;
	int numberOfLeftAllocatedParentheses;
	char* string;
	int allocatedStringSize;
};

bool SaveResults(ParentheseClass* source, ParentheseClass* destination, size_t numOfBytes)
{
	memcpy(destination, source, numOfBytes);
	// Make it return false if the copying fails
	return true;
}

bool DiscardResults(ParentheseClass* source, ParentheseClass* destination, size_t numOfBytes)
{
	(void)source;
	(void)destination;
	(void)numOfBytes;
	return true;
}

// VLA and stack buffers allocation?
void AddParentheseVla(int nrOfParentheses, bool (*finalHandler)(ParentheseClass*, ParentheseClass*, size_t))
{	
	unsigned maxIterations = 2 * nrOfParentheses - 1;
	unsigned bufferSize = (1U << maxIterations) + (1U << (maxIterations - 1));
	ParentheseClass buffer[bufferSize];
	
	// Logic for the order of objects allocated in buffer
	unsigned allocatedObjects = 0;

	// Initialize VLA buffer with the base value of ParentheseClass object
	buffer[0] = ParentheseClass(nrOfParentheses);
	++allocatedObjects;	

	for (int j = 0; j < maxIterations; ++j)
	{
		unsigned loopRange = allocatedObjects;
		for (int i = 0; i < loopRange; ++i)
		{
			if (buffer[i].GetAllocableLeft() > 0)
			{
				// Add new ParenthesesClass object to newly allocated buffer
				// Decrement numberOfLeftParentheses
				// Add with newly added left parenthese

				//MEGA::TODO This creates objectToInsert with nullptr value and then calling
				// AddLeftParenthese writes some not owning part of memory!

				// Just call the constructor for arbitrary value of nrOfParentheses which max value is known at this point
				ParentheseClass objectToInsert = buffer[i];
				objectToInsert.AddLeftParenthese();

				buffer[allocatedObjects] = objectToInsert;
				++allocatedObjects;
			}
			
			// Logic was wrong, one should not check buffer[i].GetAllocableLeft() > 0	
			if (buffer[i].NumberOfLeftParentheses() > buffer[i].NumberOfRightParentheses())
			{
				// Almost the same as above, with the difference of added side of parenthese
				ParentheseClass objectToInsert = buffer[i];
				objectToInsert.AddRightParenthese();

				buffer[allocatedObjects] = objectToInsert;
				++allocatedObjects;
			}
		}
		
		// How much objects did we allocated in this iteration?
		unsigned newlyAllocatedObjects = allocatedObjects - loopRange;
		


		//Hello! You have to call destructors manually for those objects which are being overwritten
		for (int k = 0; k < loopRange; ++k)
		{
			// This should be called for every not used object in buffer before copying the current
			// "valuable" objects to the beginning of the buffer
			buffer[k].~ParentheseClass();
		}
		// Copy the newly allocated objects to the beginning of the buffer
		memmove(&buffer, &buffer[loopRange], sizeof(ParentheseClass) * newlyAllocatedObjects);
		
		// Invalidate objects at the end of buffer since they might point to the same resources and will be deleted by
		// the assignemnt operator for ParentheseClass the next iterations
		// THIS MUST HAPPEN AFTER THE MEMMOVE!
		for (int l = newlyAllocatedObjects; l < allocatedObjects; ++l)
		{
			buffer[l].Invalidate();
		}

		// After memcpy() we have this amount of objects in buffer
		allocatedObjects = newlyAllocatedObjects;
	}
	// This is to prevent destructors of buffer array from dealocating garbage values pointers
	//memset(&buffer, 0, sizeof(ParentheseClass) * bufferSize); NOT NEEDED SINCE THE ADDITION OF CALLING DTORS AND INVALIDATE()
}

int main()
{
	//This is computing false for case of one parenthese!
	AddParentheseVla(2, &SaveResults);//Skad argumenty wziac? Jak przekazac adres large buffer do skopiowania????
	
	
	return 0;
}
