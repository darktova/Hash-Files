#pragma once
#include <iostream>

class HashEntry
{
private:
	unsigned long id;
	char* name = new char[30];

public:
	HashEntry(unsigned long = NULL, char* = nullptr);
	unsigned long getID() const;
	char* getName() const;
	void read_at(std::fstream&, long);
	void write_at(std::fstream&, long);

};
