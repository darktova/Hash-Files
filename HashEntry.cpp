#include "HashEntry.h"

HashEntry::HashEntry(unsigned long id, char* name)
	: id(id), name(name) { }

unsigned long HashEntry::getID() const
{
	return id;
}

char* HashEntry::getName() const
{
	return name;
}

void HashEntry::read_at(std::fstream& file, long pos)
{

}

void HashEntry::write_at(std::fstream& file, long pos)
{

}
