#include <stdio.h>
#include "stack/stack_arr.h"

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