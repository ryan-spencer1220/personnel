#include <iostream>
#include "linkedlist.h"
#include "person.h"

using namespace std;

int main()
{
    const char* id1 = "MC001";
    const char* id2 = "MC002";
    const char* id3 = "MC003";

    // Test inserts
    Person p1(id1,"fnameone","lnameone","famid001");
    Person p2(id2,"fnametwo","lnametwo","famid001");
    Person p3(id3,"fnamethree","lnamethree","famid002");


    LinkedList ll;

    ll.insertFront(p1);
    ll.printList();
    ll.insertFront(p2);
    ll.insertFront(p3);
    ll.printList();


    // Test searches
    const Person* foundPerson;
    foundPerson = ll.searchById(id1);
    if (foundPerson == nullptr)
	cout << "ERROR searching for ID " << id1 << endl;
    foundPerson = ll.searchById(id2);
    if (foundPerson == nullptr)
	cout << "ERROR searching for ID " << id2 << endl;
    foundPerson = ll.searchById("MC999"); // not-there
    if (foundPerson != nullptr)
	cout << "ERROR searching for ID MC999 (shouldn't be there)" << endl;
    // Test removes
    ll.removeById(id1);
    ll.printList();

    ll.removeById(id2);
    ll.printList();

    ll.removeById(id3);
    ll.printList();


    return(0);
}
