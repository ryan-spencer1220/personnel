#include "person.h"

Person::Person()
{
  id = new char[100];
  fname = new char[100];
  lname = new char[100];
  familyId = new char[100];
}

Person::Person(char *id, char *fname, char *lname, char *familyId)
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