char* FillSpacesWithText(char* string)
{
	int stringCounter = 0;
	int spacesCounter = 0;
	while (*string)
	{
		if (*string == ' ')
		{
			//Here we can store the position of space characters
			//Or we can iterate over the string twice
			++spacesCounter;
		}
		++stringCounter;
		++string;
	}
	
	//Reset the string pointer to initail position
	string -= stringCounter;
	char* outString = new char[stringCounter + (2 * spacesCounter)];
	
	while (*string)
	{
		if (*string == ' ')
		{
			//Kind of dumb, but assiging cstring with "" and incrementing pointer by 3 
			//produces compile error
			*outString = '%';
			++outString;
			*outString = '2';
			++outString;
			*outString = '0';
			++outString; 
		}
		else
		{
			*outString = *string;
			++outString;
		}
	}

	//Reset the outString pointer to the begining of to be returned string
	outString -= stringCounter + (2 * spacesCounter);

	return outString;
}

int main()
{
	char* dupa = new char[5];
	char* kolejnaDupa = FillSpacesWithText(dupa);
	return 0;
}
