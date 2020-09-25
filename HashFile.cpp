#include "HashFile.h"

int HashFile::Hash(int key)
{
    /* Example
    * 4713123434 % 7 = 5 
    * 5 is a number of a record */
    return (key % b);
}

HashFile::HashFile(std::string file_name, int b)
    : file_name(file_name), b(b) 
{
    if (!this->file_name.size())
        return;

    file.open(file_name, std::ios::in | std::ios::in);

    if (!file.good())
        return;
}

HashFile::~HashFile()
{
    file.close();
}

void HashFile::insert(HashEntry& e)
{
    file.clear();

    unsigned int entrySize = sizeof(HashEntry),
        steps = Hash(e.getID());
    e.write_at(file, entrySize * steps);
}

HashEntry* HashFile::retrieve(int key)
{
    file.clear();

    HashEntry e;
    unsigned int entrySize = sizeof(HashEntry),
        steps = Hash(key);

    if (!file)
        return;

    e.read_at(file, entrySize * steps);
}
