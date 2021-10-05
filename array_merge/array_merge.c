#include "array_merge.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"

int* removeDuplicates(int size, int* sortedValues)
{
  int counter = 0;
  int* noDuplicates;
  int* final;
  noDuplicates = (int*)calloc(size, sizeof(int));
  noDuplicates[0] = sortedValues[0];
  int j = 1;
  for(int i = 1; i < size; i++){
    if(sortedValues[i] != noDuplicates[j-1])
      {
        noDuplicates[j] = sortedValues[i];
        counter++;
        j++;
      }
  }
  final = (int*)calloc(counter+1, sizeof(int));
  final[0] = counter+1;
  for(int i = 1; i <= counter + 1; i++)
  {
      final[i] = noDuplicates[i-1];
  }
  free(noDuplicates);
  return final;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  int k, counter;
  int* intermediate;
  int* final;
  for(int i = 0; i<num_arrays; i++)
  {
    k = k + sizes[i];
  }

  intermediate = (int*)calloc(k, sizeof(int));
  counter = 0;
  for(int p = 0; p < num_arrays; p++)
  {
    int* temp = values[p];
    for(int q = 0; q < sizes[p]; q++)
    {
      intermediate[counter] = temp[q];
      counter++;
    }
  }
  mergesort(k, intermediate);

  final = removeDuplicates(k, intermediate);
  
  free(intermediate);
  return final;
}