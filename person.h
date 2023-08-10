#include <iostream>
#pragma once

using namespace std;

class Person
{
private:
  char *id;
  char *fname;
  char *lname;
  char *familyId;

public:
  Person();
  Person(const char *id, const char *fname, const char *lname, const char *familyId);
  ~Person();
  void operator=(const Person &per);

  char *getId();
  char *getFname();
  char *getLname();
  char *getFamilyId();

  void setId(char *id);
  void setFname(char *fname);
  void setLname(char *lname);
  void setFamilyId(char *familyId);

  void print();
};