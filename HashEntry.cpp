#include "HashEntry.h"

HashEntry::HashEntry(unsigned long id, const std::string& name)
{
	this->id = id;
	strcpy_s(this->name, name.c_str());
	this->name[30] = '\0';
}

void HashEntry::setID(unsigned long id)
{
	this->id = id;
}

void HashEntry::setName(const std::string& name)
{
	strcpy_s(this->name, name.c_str());
}

unsigned long HashEntry::getID() const
{
	return id;
}

std::string HashEntry::getName() const
{
	return name;
}

unsigned long HashEntry::getRecordSize() const
{
	return sizeof(unsigned long) + sizeof(name);
}

std::fstream& HashEntry::read(std::fstream& file)
{
	file.read(reinterpret_cast<char*>(&id), sizeof(id));
	file.read(name, sizeof(name));
	return file;
}

std::fstream& HashEntry::write(std::fstream& file)
{
	file.write(reinterpret_cast<char*>(&id), sizeof(id));
	file.write(name, sizeof(name));
	return file;
}

std::fstream& HashEntry::read_at(std::fstream& file, unsigned long pos)
{	
	file.seekp(pos);
	file.read(reinterpret_cast<char*>(&id), sizeof(id));
	file.read(name, sizeof(name));
	return file;
}

std::fstream& HashEntry::write_at(std::fstream& file, unsigned long pos)
{
	file.seekp(pos);
	file.write(reinterpret_cast<char*>(&id), sizeof(id));
	file.write(name, sizeof(name));
	return file;
}

void HashEntry::display()
{
	std::cout << std::fixed << std::setprecision(2)
		<< "----------------------------------"
		<< "\nClient number: " << id
		<< "\nClient: " << name
		<< "\n----------------------------------\n\n";
	std::cin.get();
}
