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
  void add(Person *per);
  void remove(char *id);
  Person *find(char *id);
};