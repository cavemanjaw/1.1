#include <iostream>
#include <vector>
#include <string>

// Consts references? 
// First invocation of this function - which type of argument should we have? Vector of size of 1 containing starting
// string, or just std::string? If the latter, what can we do with further calls, the expect list or vector of 
// strings. 

// We could pass only string! Since we are only receiving initally a string which would be reduced by one character
// in every call!

// Analyze the memory impacts!
// One solution is to give it a wrap function, e.g. "find permutations"
// Name of this function of off right now :P
std::vector<std::string> InsertCharacterInEveryPossiblePlace(std::string& string)
{
	if (string.length() != 1)
	{
		// Cache last character and reduce the string
		char lastStringChar = string.back();
		string.pop_back();

		// The naming is just off ;)
		// Call the function, magical recursion happens
		std::vector<std::string> receivedVectorOfStrings = InsertCharacterInEveryPossiblePlace(string);
	
		std::vector<std::string> newVectorOfStrings;

		// There should be invocation of this function somewhere! So we can first cache the subtracted value 
		// and then wait for the invocation to finish, and give us the place in which we can put the subtracted
		// character

		// Place the cached character in every possible place for every element of receivedVectorOfStrings
		for (auto& v: receivedVectorOfStrings)
		{
			// Looping over string invalidates iterators of string, cache the value
			for (int i = 0; i <= v.length(); ++i)
			{	
				std::string stringToPush = v;
				newVectorOfStrings.push_back(stringToPush.insert(i, 1, lastStringChar));
			}
		}
		// Return reference? RVO?
		return newVectorOfStrings;
	}
	else
	{
		std::vector<std::string> initialVector(1, string);
		return initialVector;
	}
}

// This wrap-around is not needed in the current solution!
std::vector<std::string> FindAllPermutationsOfString(std::string string)
{

	return InsertCharacterInEveryPossiblePlace(string);
}

int main()
{
	std::string exampleString = "Ulalala";
	FindAllPermutationsOfString(exampleString);
	return 0;
}
