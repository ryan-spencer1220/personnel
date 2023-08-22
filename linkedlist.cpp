#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList()
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}

LinkedList::LinkedList(Person *per)
{
  head = nullptr;
  tail = nullptr;
  size = 0;
  insertFront(*per);
}

LinkedList::~LinkedList()
{
  Node *temp = head;
  while (temp != nullptr)
  {
    head = head->next;
    delete temp;
    temp = head;
  }
}

void LinkedList::operator=(const LinkedList &list)
{
  Node *temp = list.head;
  while (temp != nullptr)
  {
    insertFront(temp->data);
    temp = temp->next;
  }
}

void LinkedList::insertFront(Person per)
{
  Node *newNode = new Node;
  newNode->data = per;
  newNode->next = nullptr;

  if (head == nullptr)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }
  size++;
}

void LinkedList::printList()
{
  Node *temp = head;
  while (temp != nullptr)
  {
    temp->data.print();
    temp = temp->next;
  }
}

Person *LinkedList::searchById(const char *id)
{
  Node *current = head;
  Person *per = nullptr;
  for (int i = 0; i < size; i++)
  {
    if (strcmp(current->data.getId(), id) == 0)
    {
      per = &current->data;
    }
    current = current->next;
  }
  return per;
}

void LinkedList::removeById(const char *id)
{
  Node *temp = head;
  Node *prev = nullptr;
  bool found = false;
  while (temp != nullptr && !found)
  {
    if (strcmp(temp->data.getId(), id) == 0)
    {
      if (prev == nullptr)
      {
        head = temp->next;
      }
      else
      {
        prev->next = temp->next;
      }
      delete temp;
      found = true;
    }
    else
    {
      prev = temp;
      temp = temp->next;
    }
  }
  if (found)
  {
    size--;
  }
}

int LinkedList::getSize()
{
  return size;
}