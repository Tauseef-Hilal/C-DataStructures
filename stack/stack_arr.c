#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct stack
{
  int length;
  int capacity;
  int arr[];
} Stack;

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

Stack *get_new_stack(int capacity)
{
  Stack *s = (Stack *)malloc(sizeof(Stack) + capacity * sizeof(int));
  s->capacity = capacity;
  s->length = 0;

  return s;
}

void print_stack(Stack *stack)
{
  int max_num = max(stack->arr, stack->length);
  int max_digit_count = digit_count(max_num);
  int dash_count = max_digit_count + 2;

  draw_border(dash_count);
  for (int i = stack->length - 1; i >= 0; i--)
  {
    printf("|%*d |\n", dash_count - 1, stack->arr[i]);
    draw_border(dash_count);
  }
}

void push(int value, Stack *stack)
{
  if (stack->length == stack->capacity)
  {
    printf("Stack already full\n");
    return;
  }

  stack->arr[stack->length] = value;
  stack->length++;
}

void pop(Stack *stack)
{
  if (stack->length == 0)
  {
    printf("Stack already empty\n");
    return;
  }

  stack->length--;
}

int main()
{
  Stack *s = get_new_stack(10);
  for (int i = 0; i < 10; i++)
  {
    push(i + 1, s);
  }

  printf("BEFORE DELETING\n");
  print_stack(s);

  pop(s);
  pop(s);
  printf("AFTER DELETING\n");
  print_stack(s);

  return 0;
}