#include "HashFile.h"

int main()
{
    HashFile data_base("customers.txt", 7);

    unsigned long id = 20,
        bob_id = 10,
        mike_id = 5;
    char* name = new char[]{ "Arkadiy" },
        *bob_name = new char[] {"Bob"},
        *mike_name = new char[] {"Mike"};
    

    HashEntry Arkadiy(id, name);
    HashEntry Bob(bob_id, bob_name);
    HashEntry Mike(mike_id, mike_name);

    data_base.insert(Arkadiy);
    data_base.insert(Bob);
    data_base.insert(Mike);

    HashEntry* BobFromBase = data_base.retrieve(bob_id);
    HashEntry* Fake19 = data_base.retrieve(19UL);
    HashEntry* Fake3 = data_base.retrieve(3UL);
    HashEntry* Fake5 = data_base.retrieve(5UL);
}
