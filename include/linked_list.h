typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} Node;

typedef struct linked_list
{
  Node *head;
  Node *tail;
  int length;
} LinkedList;

LinkedList *new_linked_list();
void append(int, LinkedList*);
void prepend(int, LinkedList*);
void insert_before(int, int, LinkedList*);
void insert_after(int, int, LinkedList*);
void delete(int, LinkedList*);
void print_linked_list(LinkedList *);
void delete_linked_list(LinkedList *);