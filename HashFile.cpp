#include "HashFile.h"

HashFile::HashFile(std::string file_name, unsigned long b)
    throw(OpenError, WriteError)
{
    // File' openmode 
    std::ios::openmode file_mode = 
        std::ios::in | std::ios::out | std::ios::binary;

    // Open already existed file.
    file.open(file_name, file_mode);
    
    // File doesn't exist?
    if (!file.good())
    {
        // Reset file' status
        file.clear();
        
        // Create suitable file
        file_mode |= std::ios::trunc;
        file.open(file_name, file_mode);

        // If it's not good, throwing error
        if (!file.good())
            throw OpenError(file_name);
    }

    // Setup private data members
    this->file_name = file_name;
    this->b = b;

    // Temporary initializer record
    HashEntry rec(0UL, "");
    
    // Set begin position
    file.seekp(0L);
    
    /* Initialize
    * the address space */
    for (unsigned long i = 0UL; i < b; ++i)
    { 
        rec.write(file);
        if (!file.good())
            throw WriteError(file_name);
    }
}

HashFile::~HashFile()
{
    file.close();
}

/* Transforms (int.) key into value
 * between 0 and b-1 */
unsigned long HashFile::Hash(unsigned long key) const
{
    /* Example
    * 4713123434 % 7 = 5
    * 5 is a number of a record */
    return (key % b);
}

void HashFile::insert(HashEntry& e)
throw(ReadError, WriteError)
{
    HashEntry temp;
	
    // Searching the entry' position
    unsigned long entrySize = temp.getRecordSize(),
        steps = Hash(e.getID());

    temp.read_at(file, steps * entrySize); // Read a slot.
    if (!file.good())
        throw ReadError(file_name);

    /* Slot free
    * Yes => Add
    * to the file.
    * Inserting entry */
    if (temp.getID() == 0L)
        e.write_at(file, entrySize * steps);

    // No => Searching for a free slot.
    else
    {
        // Flag
        bool found = false;
        // Position of next slot from previous
        unsigned long p = (entrySize * steps + entrySize) % (b * entrySize);
        // Number of available entries;
        unsigned long capacity = entrySize * steps;

        while (!found && p != capacity)
        {
            // Read current entry
            temp.read_at(file, p);

            // Reading failed
            if (!file.good())
                throw ReadError(file_name);
            
            // Free slot found
            if (temp.getID() == 0L)
                found = true;
            // Or proceed to the next slot
            else
                p = (p + entrySize) % (b * entrySize);
        }

        // Address space full.
        if (p == capacity)
            throw WriteError(file_name);

        // Add to file.
        if (found) 
            e.write_at(file, p);
    }
    
    if (!file.good())
        throw WriteError(file_name);
}

HashEntry* HashFile::retrieve(unsigned long key)
    throw(ReadError)
{
    static HashEntry* e = new HashEntry(0UL, "");
    unsigned long entrySize = e->getRecordSize(),
        steps = Hash(key);

    // Read a slot
    e->read_at(file, entrySize * steps);
   
    // Reading failed
    if (!file.good())
        throw ReadError(file_name);

    // Found.
    if (e->getID() == key)
        return e;

    // Searching for a record
    for (unsigned long i = (entrySize * steps + entrySize) % (b * entrySize);
        (i != entrySize * steps);
        i = (i + entrySize) % (b * entrySize))
    {
        // Read current entry
        e->read_at(file, i);

        // Reading failed
        if (!file.good())
            throw ReadError(file_name);

        // Record found
        if (e->getID() == 0UL)
            return e;
    }

    e->setID(0UL);
    e->setName("");
    return e;
}

void HashFile::display()
{
    HashEntry slot;

    // Setup begin
    file.seekg(0UL);
    
    // Displaying all slots
    for (unsigned int i = 0; i < b; ++i)
    {
        // Reading a slot
        slot.read(file);
        
        // Reading failed
        if (!file.good())
            throw ReadError(file_name);
        
        // Displaying current slot
        slot.display();
    }
 
    // Reset current status
    file.clear();
}
