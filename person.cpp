#include "person.h"

Person::Person()
{
  id = new char[100];
  fname = new char[100];
  lname = new char[100];
  familyId = new char[100];
}

Person::Person(const char *id, const char *fname, const char *lname, const char *familyId)
{
  this->id = new char[100];
  this->fname = new char[100];
  this->lname = new char[100];
  this->familyId = new char[100];

  strcpy(this->id, id);
  strcpy(this->fname, fname);
  strcpy(this->lname, lname);
  strcpy(this->familyId, familyId);
}

Person::~Person()
{
  delete[] id;
  delete[] fname;
  delete[] lname;
  delete[] familyId;
}

void Person::operator=(const Person &per)
{
  strcpy(id, per.id);
  strcpy(fname, per.fname);
  strcpy(lname, per.lname);
  strcpy(familyId, per.familyId);
}

void Person::print()
{
  cout << "ID: " << id << endl;
  cout << "First Name: " << fname << endl;
  cout << "Last Name: " << lname << endl;
  cout << "Family ID: " << familyId << endl;
}

char *Person::getId()
{
  return id;
}

char *Person::getFname()
{
  return fname;
}

char *Person::getLname()
{
  return lname;
}

char *Person::getFamilyId()
{
  return familyId;
}

void Person::setId(char *id)
{
  strcpy(this->id, id);
}

void Person::setFname(char *fname)
{
  strcpy(this->fname, fname);
}

void Person::setLname(char *lname)
{
  strcpy(this->lname, lname);
}

void Person::setFamilyId(char *familyId)
{
  strcpy(this->familyId, familyId);
}
