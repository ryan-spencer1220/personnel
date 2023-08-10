#include "person.h"

class LinkedList
{
private:
  struct Node
  {
    Person *data;
    Node *next;
  };
  Node *head;
  Node *tail;
  int size;

public:
  LinkedList();
  LinkedList(Person *per);
  ~LinkedList();
  void operator=(const LinkedList &list);
  void insertFront(Person per);
  void printList();
  Person *searchById(const char *id);
  void removeById(const char *id);
};