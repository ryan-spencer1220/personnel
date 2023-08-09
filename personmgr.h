#include "person.h"

class PersonMgr
{
public:
  PersonMgr();
  void addPerson(Person per);
  void removePerson(char *id);
  Person *findPerson(char *id);
};