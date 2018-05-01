/*
 * Input is a table of strings, we want to sort the table so all the anagrams are next to each other
 *
 */

#include <iostream>
#include <string>

//First approach will be a plain old array of strings

void SortByAnagrams(std::string array[], int stringArraySize)
{
   //The idea is to have an array of boolean values, that will indicate if char is present in investigated string


   //For every string in the array
   for (int i = 0; i < stringArraySize; ++i)
   {
      bool isCharInString[255] = {};
   
      //Build up the isCharInString array
      for (auto k = array[i].begin(); k != array[i].end(); ++k)
      {
         isCharInString[(unsigned)(*k)] = true;
      }

      //Search for anagrams for i-th string in array
      for (int j = i + 1; j < stringArraySize; ++j)
      {
         
      }
   }
}
