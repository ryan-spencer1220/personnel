#include <iostream>
#include <cstring>
#include "person.h"

using namespace std;

int main()
{
    const char* id = "MC00ABC";
    const char* fname = "bob";
    const char* lname = "smith";
    const char* familyId = "smith1234";

    Person p1(id,fname,lname,familyId);

    if (strcmp(p1.getId(),id)!=0)
    {
	cout << "ERROR: wrong id" << endl;
    }

    if (strcmp(p1.getFname(),fname)!=0)
    {
	cout << "ERROR: wrong fname" << endl;
    }

    if (strcmp(p1.getLname(),lname)!=0)
    {
	cout << "ERROR: wrong lname" << endl;
    }

    if (strcmp(p1.getFamilyId(),familyId)!=0)
    {
	cout << "ERROR: wrong familyId" << endl;
    }


    return 0;
}
