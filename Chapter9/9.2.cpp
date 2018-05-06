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
      unsigned charCounter = 0;
   
      //Build up the isCharInString array
      //If the iterator would be different type it can be used for counting
      for (auto k = array[i].begin(); k != array[i].end(); ++k)
      {
         isCharInString[(unsigned)(*k)] = true;
         ++charCounter;
      }

      //Search for anagrams for i-th string in array
      for (int j = i + 1; j < stringArraySize; ++j)
      {
        //Clean this up, it can be done more efficiently
        unsigned processedCharCounter = 0;

        for (auto m = array[j].begin(); m != array[j].end(); ++m)
        {
           auto currentlyProcessedChar = *m;
           
           //Char is no in the array
           if (isCharInString[(unsigned)(currentlyProcessedChar)] == false)
           {
              //Break the loop and do not do anything, this string is not an anagram of the processed one
              break;
           }
           //If all characters have been processed it can be anagram, but if it is shorter there is also mismatch
           ++processedCharCounter;
        }
        //If all characters have been processed it can be anagram, but if it is shorter there is also mismatch
        if (charCounter == processedCharCounter)
        {
           //FOUND
           //It is an anagram, act on this xD
           //This functionality should be wrapped in some other function
        }
      }
   }
}
