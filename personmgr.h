#ifndef PERSONMGR_H
#define PERSONMGR_H

#include "person.h"
#include "hashtable.h"

class PersonMgr
{
private:
  Hashtable table;

public:
  void addPerson(Person per);
  void removePerson(char *id);
  Person *findPerson(char *id);
};

#endif