#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "personmgr.h"
#include "person.h"

using namespace std;

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " <datafile>" << endl;
    exit(0);
  }

  PersonMgr personMgr;

  char *datafile = argv[1];
  ifstream infile(datafile);

  if (infile.is_open())
  {
    cout << "======= Loading personnel data =======" << endl;
    int count = 0;
    bool done = false;
    while (!done)
    {
      char id[100];
      char fname[100];
      char lname[100];
      char familyId[100];

      infile >> id;
      infile >> fname;
      infile >> lname;
      infile >> familyId;

      if (strcmp(id, "=======") == 0)
      {
        done = true;
      }
      else
      {
        Person per(id, fname, lname, familyId);
        personMgr.addPerson(per);
        count++;
      }
    }
    cout << "Added " << count << " persons to the person manager." << endl
         << endl;
    ;

    done = false;
    count = 0;
    while (!done)
    {
      char id[100];

      infile >> id;

      if (strcmp(id, "=======") == 0)
      {
        done = true;
      }
      else
      {
        personMgr.removePerson(id);
        count++;
      }
    }
    cout << "Removed " << count << " persons from the person manager." << endl
         << endl;
    ;

    cout << "======= Exercising lookups ===========" << endl;

    // To exercise lookups and make sure that they are fast enough, we are going
    // to read the lookup requests out of the data file. We will print the results
    // from the first NUM_PRINTS records. We will look up the same ID NUM_LOOKUPS
    // times so that we are evaluating the lookup time of the hashtable, not the
    // IO time of reading the file.

    const int NUM_PRINTS = 10;
    const int NUM_LOOKUPS = 100;

    cout << "Showing the first " << NUM_PRINTS << " records." << endl
         << endl;

    int printCount = 0;
    while (!infile.eof())
    {
      char id[100];
      infile >> id;
      if (!infile.eof())
      {
        for (int i = 0; i < NUM_LOOKUPS; i++)
        {
          Person *perPtr = personMgr.findPerson(id);

          // If this is the first lookup for this person and we
          // haven't printed NUM_PRINTS persons yet, then print
          // this person.
          if (perPtr != nullptr)
          {
            if (i == 0 && printCount < NUM_PRINTS)
            {
              printCount++;
            // cout << *perPtr << endl;
            alternative:
              perPtr->print();
            }
          }
        }
      }
    }
    infile.close();
  }

  return (0);
}
