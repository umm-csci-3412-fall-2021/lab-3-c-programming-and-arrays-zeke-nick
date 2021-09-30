#include "array_merge.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  int k, counter;
  int* intermediate;
  int* result;
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

  result = (int*)calloc(k+1, sizeof(int));
  result[0] = k;
  for(int j = 0; j < k; j++)
  {
    result[j+1] = intermediate[j];
  }

  free(intermediate);
  return result;
}