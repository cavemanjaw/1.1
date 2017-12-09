#include <cstring>
#include <string>
#include <climits>

class ParentheseClass
{
public:
	ParentheseClass(int nrOfParentheses):
		numberOfLeftAllocableParentheses(nrOfParentheses - 1),
		numberOfRightAllocableParentheses(nrOfParentheses),
		parentheseString("("),
		numberOfRightAllocatedParentheses(0),
		numberOfLeftAllocatedParentheses(1)
	{
	}

	ParentheseClass()
	{
	}

	~ParentheseClass()
	{
	}

	void AddLeftParenthese()
	{
		parentheseString.push_back('(');
		--numberOfLeftAllocableParentheses;
		++numberOfLeftAllocatedParentheses;
	}
	
	void AddRightParenthese()
	{
		parentheseString.push_back(')');
		--numberOfRightAllocableParentheses;
		++numberOfRightAllocatedParentheses;
	}

	int GetAllocableRight()
	{
		return numberOfRightAllocableParentheses;
	}
	
	int GetAllocableLeft()
	{
		return numberOfLeftAllocatedParentheses;
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
	std::string parentheseString;
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
				ParentheseClass objectToInsert = buffer[i];
				objectToInsert.AddLeftParenthese();

				buffer[allocatedObjects] = objectToInsert;
				++allocatedObjects;
			}
			
			if (buffer[i].GetAllocableLeft() > 0 && (buffer[i].NumberOfLeftParentheses() > buffer[i].NumberOfRightParentheses()))
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
		
		// After memcpy() we have this amount of objects in buffer
		allocatedObjects = newlyAllocatedObjects;
	}
	// This is to prevent destructors of buffer array from dealocating garbage values pointers
	memset(&buffer, 0, sizeof(ParentheseClass) * bufferSize);
}

int main()
{
	//This is computing false for case of one parenthese!
	AddParentheseVla(2, &SaveResults);//Skad argumenty wziac? Jak przekazac adres large buffer do skopiowania????
	
	
	return 0;
}
