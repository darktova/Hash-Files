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
	file.seekp(pos);
	file.read((char*)&id, sizeof(id));
	file.read((char*)&name, sizeof(name));
}

void HashEntry::write_at(std::fstream& file, long pos)
{
	file.seekp(pos);
	file.write((char*)&id, sizeof(id));
	file.write((char*)&name, sizeof(name));
}
