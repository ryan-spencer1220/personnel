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
    insertFront(*curr->data);
    curr = curr->next;
  }
}

void LinkedList::insertFront(Person per)
{
  Node *temp = new Node;
  temp->data = new Person;
  *temp->data = per;
  temp->next = head;
  head = temp;
  size++;
}

void LinkedList::printList()
{
  Node *curr = head;
  while (curr != NULL)
  {
    curr->data->print();
    curr = curr->next;
  }
}

Person *LinkedList::searchById(const char *id)
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

void LinkedList::removeById(const char *id)
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
  cout << "Person not found." << endl;
}