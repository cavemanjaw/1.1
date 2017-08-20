//reverse meaning modify existing content of string
//reverse meaning function that returns a new string
#include <iostream>
void ReverseModify(char* string)
{
  char* endOfString = string;
  
  while (*endOfString)
  {
    ++endOfString;
  }
  
  //To get the last character, not the null
  --endOfString;
  
  int stringLength = endOfString - string + 1;
  
  char swapStore;
  for (int i = 0; i < stringLength / 2; ++i)
  {
    swapStore = *string;
    *string = *endOfString;
    *endOfString = swapStore;

    ++string;
    --endOfString;
  }
}

//Would be easier to just copy an input string at the beginning of the function
char* ReverseCreate(char* string)
{
  int stringLength = 0;
  while (*string)
  {
    ++stringLength;
    ++string;
  }
  
  char* returnedString = (char*)malloc(sizeof(char)*(stringLength + 1));
  char* returnedPtr = returnedString;
  for (int i = 0; i < stringLength; ++i)
  {
    *returnedPtr = *(--string);
    ++returnedPtr;
  }
  *returnedPtr = '\0';
  return returnedString;
}

int main()
{
  char mojString[] = "Dupa";
  std::cout << mojString;
  ReverseModify(mojString);
  std::cout << mojString;
  return 0;
}