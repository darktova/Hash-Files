#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "exceptio.h"

class HashEntry
{
private:
	unsigned long id;
	char name[30];

public:
	HashEntry(unsigned long = 0UL, const std::string & = "");
	
	void setID(unsigned long);
	void setName(const std::string&);
	
	unsigned long getID() const;
	std::string getName() const;
	unsigned long getRecordSize() const;

	std::fstream& read(std::fstream&);
	std::fstream& write(std::fstream&);
	
	std::fstream& read_at(std::fstream&, unsigned long);
	std::fstream& write_at(std::fstream&, unsigned long);
	
	virtual void display();
};
