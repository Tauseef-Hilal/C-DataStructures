#include <stdio.h>
#include <stdint.h>

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
    printf("Error: Empty array");
    return INT16_MIN;
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