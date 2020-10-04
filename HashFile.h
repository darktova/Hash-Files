#pragma once
#include "HashEntry.h"

class HashFile
{
private:
	std::fstream file;
	std::string file_name;

	// Bias
	int b;

	int Hash(int);

public:
	HashFile(std::string, int);
	~HashFile();
	void insert(HashEntry&);
	HashEntry* retrieve(int);
};

