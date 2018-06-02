
int GetIndexOfElemInRotatedArray(int* array, int lower, int upper, int searchedNumber)
{
   while (lower <= upper)
   {
      int middle = (lower + upper) / 2;
      
      // If middle element is the searched value, return the index of that value in array
      if (searchedNumber == array[middle])
      {
         return middle;
      }

      // If there is no pivot rotation point in [lower, middle]
      else if (array[middle] >= array[lower])
      {
         // The searched number is in the second half, it is in [middle, upper]
         if (searchedNumber > array[middle])
         {
            lower = middle + 1;
         }

         // Searched number is in this half, it is in [lower, middle]
         else if (searchedNumber >= array[lower])
         {
            upper = middle - 1;
         }

         // Can be in the second half, it is not bigger than array[middle] and it is not bigger or equal to array[lower]
         else 
         {
            lower = middle + 1;
         }
      }

      // If the number we are searching is smaller than selected middle point
      else if (searchedNumber < array[middle])
      {
         upper = middle - 1;
      }

      // The searched  number is clearly less or equal to upper band
      else if (searchedNumber <= array[upper])
      {
         lower = middle + 1;
      }
      
      // Here be dragons
      else
      {
         upper = middle - 1;
      }
   }
   return -1;
}

int GetIndexOfElemInRotatedArray(int* array, int searchedNumber, int length)
{
   return GetIndexOfElemInRotatedArray(array, 0, length - 1, searchedNumber)
}

int main()
{
   return 0;
}
