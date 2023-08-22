#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include <iostream>

const int MaxTableSize = 9973;

class Hashtable
{
private:
  LinkedList *table;
  int hash(const char *id);

public:
  Hashtable();
  ~Hashtable();
  Hashtable(const Hashtable &table);
  void operator=(Hashtable &table);
  void insert(char id[], Person per);
  void remove(const char *id);
  Person *locate(const char *id);
};

#endif