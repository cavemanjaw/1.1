//TODO: Wirte methods for c-string type string, std string and also poiner arithmetics

#include <string>
#include <iostream>

int LengthOfString(char* string)
{
    int lengthOfString = 0;
    //Not really needed, since string var is local and function returns only the lengthOfString var
    char* ptr = string;
    
    while (*ptr)
    {
        //Could be changed to string var, since is is not used anywhere else to be interpreted as the c-string
        ++ptr;
        ++lengthOfString;
    }
    
    return lengthOfString;
}

bool HasUniqueCharactersPointers(char* string)
{
	while (*string)
	{
		char* ptr = string + 1;
		while (*ptr)
		{
			if (*string == *ptr)
			{
				return false;
			}
			++ptr;
		}
		++string;
	}
	return true;
}

//For c-strings, char* type of string
bool HasUniqueCharacters(char* string)
{
    int stringLength = LengthOfString(string);
    
    for (int i = 0; i < stringLength; ++i)
    {
        for (int j = i + 1; j < stringLength; ++j)
        {
            if (string[i] == string[j])
            {
                return false;
            }
        }
    }
    
    //Since all chars have been compared there are no the same chars in passed string   
    return true;
}

bool HasUniqueCharacters(std::string string)
{
	for (int i = 0; i < string.size(); ++i)
	{
		for (int j = i + 1; j < string.size(); ++j)
		{
			if (string.at(i) == string.at(j))
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
    char zmienna[] = "Kot";
    char cos[] = "KotK";
    std::string kolejnaZmienna = "DupaD";
    std::cout << HasUniqueCharacters(kolejnaZmienna);	
    std::cout << HasUniqueCharacters(zmienna);
    std::cout << HasUniqueCharactersPointers(cos);
    return 0;   
}
