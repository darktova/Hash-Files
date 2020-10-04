#include "HashFile.h"

int main()
{
    try
    {
        // Address space of length 7
        HashFile hash("customers.fle", 7); 

    	// Inserting the data
        std::cout << "\nInsert: \n";
        HashEntry kde(3UL, (char*)"Vivi");
        hash.insert(kde);
        kde.setID(10L); kde.setName((char*)"Peter");
        hash.insert(kde);
        kde.setID(17L); kde.setName((char*)"Alexa");
        hash.insert(kde);
        kde.setID(21L); kde.setName((char*)"Peter");
        hash.insert(kde);
        kde.setID(15L); kde.setName((char*)"Jeany");
        hash.insert(kde);
    	std::cout << "\nInsertion complete: \n";

        // Displaying data base
    	hash.display();

		// Testing Retreive method
    	unsigned long key;
        std::cout << "Key? "; std::cin >> key;
        HashEntry* temp = hash.retrieve(key);
        if (temp->getID() != 0L)
            temp->display();
        else
            std::cout << "Key " << key
            << " not found\n";
    }
    catch (OpenError& err)
    {
        std::cerr << "Error in opening the file:"
            << err.getName() << '\n';
        exit(1);
    }
    catch (WriteError& err)
    {
        std::cerr << "Error writing to file: "
            << err.getName() << '\n';
        exit(1);
    }
    catch (ReadError& err)
    {
        std::cerr << "Error reading from file: "
            << err.getName() << '\n';
        exit(1);
    }

    return 0;
}