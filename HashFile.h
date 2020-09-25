#pragma once
#include <fstream>
#include "HashEntry.h"

class HashFile
{
private:
	std::fstream file;
	std::string file_name;
	int b;

	/* Transforms (int.) key into value
	* between 0 and b-1 */
	int Hash(int);

public:
	HashFile(std::string, int);
	~HashFile();
	void insert(HashEntry&);
	HashEntry* retrieve(int);
};

