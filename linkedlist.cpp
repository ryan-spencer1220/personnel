#include "linkedlist.h"

LinkedList::LinkedList()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

LinkedList::LinkedList(Person *per)
{
  head = new Node;
  head->data = per;
  head->next = NULL;
  tail = head;
  size = 1;
}

LinkedList::~LinkedList()
{
  Node *curr = head;
  while (curr != NULL)
  {
    Node *temp = curr;
    curr = curr->next;
    delete temp->data;
    delete temp;
  }
}

void LinkedList::operator=(const LinkedList &list)
{
  Node *curr = list.head;
  while (curr != NULL)
  {
    add(curr->data);
    curr = curr->next;
  }
}

void LinkedList::add(Person *per)
{
  Node *node = new Node;
  node->data = per;
  node->next = NULL;
  if (head == NULL)
  {
    head = node;
    tail = node;
  }
  else
  {
    tail->next = node;
    tail = node;
  }
  size++;
}

void LinkedList::remove(char *id)
{
  Node *curr = head;
  Node *prev = NULL;
  while (curr != NULL)
  {
    if (strcmp(curr->data->getId(), id) == 0)
    {
      if (prev == NULL)
      {
        head = curr->next;
      }
      else
      {
        prev->next = curr->next;
      }
      delete curr->data;
      delete curr;
      size--;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

Person *LinkedList::find(char *id)
{
  Node *curr = head;
  while (curr != NULL)
  {
    if (strcmp(curr->data->getId(), id) == 0)
    {
      return curr->data;
    }
    curr = curr->next;
  }
  return NULL;
}