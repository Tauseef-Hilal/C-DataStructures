#include <stdio.h>
#include <stdlib.h>

#include "./stack_arr.h"
#include "../utils/abc.h"

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

