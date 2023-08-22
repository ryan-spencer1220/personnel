#include "hashtable.h"

Hashtable::Hashtable()
{
  table = new LinkedList[MaxTableSize];
}

Hashtable::Hashtable(const Hashtable &newTable)
{
  this->table = new LinkedList[MaxTableSize];
  for (int i = 0; i < MaxTableSize; i++)
  {
    this->table[i] = newTable.table[i];
  }
}

Hashtable::~Hashtable()
{
  delete[] table;
  table = nullptr;
}

void Hashtable::operator=(Hashtable &table)
{
  if (this->table != nullptr)
  {
    delete[] this->table;
  }
  for (int i = 0; i < MaxTableSize; i++)
  {
    this->table[i] = table.table[i];
  }
}

void Hashtable::insert(char id[], Person per)
{
  int index = hash(id);
  table[index].insertFront(per);
}

void Hashtable::remove(const char *id)
{
  int index = hash(id);
  table[index].removeById(id);
}

int Hashtable::hash(const char *id)
{
  const int x = 32;
  int idLength = 17;
  size_t hashValue = id[idLength - 4];

  for (int i = idLength - 1; i >= 4; i--)
  {
    int temp = id[i];
    hashValue = hashValue * x + id[i];
  }
  return hashValue % MaxTableSize;
}

Person *Hashtable::locate(const char *id)
{
  int index = hash(id);
  return table[index].searchById(id);
}