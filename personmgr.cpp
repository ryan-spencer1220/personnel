#include "personmgr.h"

void PersonMgr::addPerson(Person per)
{
  table.insert(per.getId(), per);
}

void PersonMgr::removePerson(char *id)
{
  table.remove(id);
}

Person *PersonMgr::findPerson(char *id)
{
  return table.locate(id);
}