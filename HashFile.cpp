#include "HashFile.h"

/* Transforms (int.) key into value
 * between 0 and b-1 */
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

    file.open(file_name, std::ios::in | std::ios::out);

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

    // Searching the entry' position
    unsigned int entrySize = sizeof(HashEntry),
        steps = Hash(e.getID());

    // Inserting entry
    e.write_at(file, entrySize * steps);
}

HashEntry* HashFile::retrieve(int key)
{
    file.clear();

    HashEntry* e = new HashEntry();
    unsigned int entrySize = sizeof(HashEntry),
        steps = Hash(key);

    if (!file)
        return nullptr;

    e->read_at(file, entrySize * steps);
    return e;
}
