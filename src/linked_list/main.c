#include <stdio.h>
#include <stdlib.h>
#include "../../include/linked_list.h"
#include "../../include/abc.h"

LinkedList *new_linked_list()
{
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  if (list == NULL)
  {
    throw("Unable to allocate memory");
  }

  list->length = 0;
  return list;
}

void append(int value, LinkedList *list)
{
  Node *n = (Node *)malloc(sizeof(Node));
  if (n == NULL)
  {
    throw("Unable to allocate memory");
  }

  n->data = value;

  if (list->length == 0)
  {
    list->head = n;
    list->tail = n;
    list->length++;
    return;
  }

  // Link node
  n->prev = list->tail;
  list->tail->next = n;

  // Update tail and length
  list->tail = n;
  list->length++;
}

void prepend(int value, LinkedList *list)
{
  Node *n = (Node *)malloc(sizeof(Node));
  if (n == NULL)
  {
    throw("Unable to allocate memory");
  }

  n->data = value;

  if (list->length == 0)
  {
    list->head = n;
    list->tail = n;
    list->length++;
    return;
  }

  // Link node
  n->next = list->head;
  list->head->prev = n;

  // Update tail and length
  list->head = n;
  list->length++;
}

void insert_after(int target, int value, LinkedList *list)
{
  Node *curr = list->head;

  while (curr != NULL)
  {
    if (curr->data == target)
    {
      break;
    }

    curr = curr->next;
  }

  if (curr == NULL)
  {
    printf("Error: %d not in list\n", target);
    return;
  }

  Node *n = (Node *)malloc(sizeof(Node));
  if (n == NULL)
  {
    throw("Unable to allocate memory");
  }

  n->data = value;
  n->next = curr->next;
  n->prev = curr;
  curr->next = n;
  list->length++;

  if (curr == list->tail)
  {
    list->tail = n;
  }
}

void insert_before(int target, int value, LinkedList *list)
{
  Node *curr = list->head;

  while (curr != NULL)
  {
    if (curr->data == target)
    {
      break;
    }

    curr = curr->next;
  }

  if (curr == NULL)
  {
    printf("Error: %d not in list\n", target);
    return;
  }

  Node *n = (Node *)malloc(sizeof(Node));
  if (n == NULL)
  {
    throw("Unable to allocate memory");
  }

  n->data = value;

  // Edge case - insert before head
  if (curr == list->head)
  {
    n->next = curr;
    list->head = n;
    list->length++;
    return;
  }

  n->next = curr;
  n->prev = curr->prev;
  curr->prev->next = n;
  list->length++;
}

void print_linked_list(LinkedList *list)
{
  for (Node *temp = list->head; temp->next != NULL; temp = temp->next)
  {
    printf("%d -> ", temp->data);
  }

  printf("%d\n", list->tail->data);
}

void delete_linked_list(LinkedList *list)
{
  for (Node *temp = list->tail; temp != NULL; temp = temp->prev)
  {
    free(temp);
  }
}