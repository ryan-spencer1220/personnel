#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
#pragma once

using namespace std;

const int MAX = 100;

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
  Person(const Person &per);
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

#endif