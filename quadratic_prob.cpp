// 2. Quadratic Probing: index = (initialHash + i^2) % TableSize
void insertQuadraticProbing(const std::vector<std::string>& keys,
                            std::vector<std::string>& table,
                            int tableSize)
{
    for (const auto& key : keys)                    // (1) iterates over every key to inreser, in order
    {
        int initialHash = hashFunction(key, tableSize); // (2) computes h((k) = sum of ascii mod11 
        int i = 0;                                  // (3) probe counter, the initial hash
        int index = initialHash;                    // (4)starting slot

        while (table[index] != EMPTY)               // (5) keeping probing slot while the  current slot is occupied
        {
            ++i;                                    // (6) advance to next probe attempt
            index = (initialHash + i * i) % tableSize; // (7) quadratic stepo
            if (i >= tableSize)                     // (8) quadratic probe can cycle without hitting an empty slot if table size isnt prime or load factor is high
                break;                              // (9) bailout table full
        }

        if (table[index] == EMPTY)                  // (10) did we land on empty slot
            table[index] = key;                     // (11) insert there
        else
            std::cout << "Table full, cannot insert " << key << "\n"; // (12) failed to find a slow within tableSize probes
    }
}
