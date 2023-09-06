typedef struct stack
{
  int length;
  int capacity;
  int arr[];
} Stack;

Stack *get_new_stack(int);
void push(int, Stack *);
void pop(Stack *);
void print_stack(Stack *);