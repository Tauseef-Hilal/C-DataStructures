#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "abc.h"

int digit_count(int num)
{
  int count = 0;
  while (num != 0)
  {
    count++;
    num /= 10;
  }

  return count;
}

int max(int arr[], int size)
{
  if (size == 0)
  {
    throw("Error: Cannot determine max from empty array\n");
  }

  int current_max = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (arr[i] > current_max)
    {
      current_max = arr[i];
    }
  }

  return current_max;
}
void draw_border(int dash_count)
{
  printf("+");
  for (int i = 0; i < dash_count; i++)
  {
    printf("-");
  }
  printf("+\n");
}

void throw(const char *error_msg)
{
  fprintf(stderr, "%s", error_msg);
  exit(EXIT_FAILURE);
}