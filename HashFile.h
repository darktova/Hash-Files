#pragma once
#include "HashEntry.h"

class HashFile
{
private:
	std::fstream file;
	std::string file_name;

	// Bias
	unsigned long b;

protected:
	unsigned long Hash(unsigned long key) const;

public:
	HashFile(std::string, unsigned long) 
		throw(OpenError, WriteError);
	~HashFile();
	void insert(HashEntry&) 
		throw(ReadError, WriteError);
	HashEntry* retrieve(unsigned long)
		throw(ReadError);
	void display();
};

