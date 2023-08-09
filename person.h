#include <iostream>

using namespace std;

class Person
{
public:
  Person();
  Person(char *id, char *fname, char *lname, char *familyId);
  ~Person();
  void operator=(const Person &per);

  char *getId();
  char *getFirstName();
  char *getLastName();
  char *getFamilyId();

  void setId(char *id);
  void setFirstName(char *fname);
  void setLastName(char *lname);
  void setFamilyId(char *familyId);

  void print();

private:
  char *id;
  char *fname;
  char *lname;
  char *familyId;
};