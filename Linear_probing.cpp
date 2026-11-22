#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct NameItem{
    std::string name;
    int asciiSum;
    int initialHash; // stores the reemainder of sum to indicate the memory addresss
};

// calculate the sum of ascii values for a given string
int calculateAscii(const std::string & str){
    int sum = 0;
    for (char c : str){
        sum += static_cast<unsigned char>(c); 
    } //runs once for each for each char in str
    return sum;

}

//1. Linear Probing: index = (initalHash + i) % tablesize
// define a function that accpets a list of name with their precalculate has values and the total capacity of the hash table 
void insertLinear(const std::vector<NameItem> & items, int tableSize){
    //  intializes a fixed size vector of length 11 every slot being filled by empty string
    std::vector<std::string> table(tableSize, "");

    for(const auto& item : items) {// iterate through each item{
        int i = 0; // intialized the probe counter
        while ( i< tableSize){
            int index = (item.initialHash + i) % tableSize; // stops infinite cycle
            // when i = 0, index = initialHash % tablesize
            //if occupied i cinrements to 1,2,3 probing consecutive indiced
            if (table[index] == ""){
                table[index] = item.name;
                std::cout << " Inserted " << std::setw(3) << item.name
                          << " (hash=" << std::setw(2) << item.initialHash
                          << ", index=" << std::setw(2) << index << "]";
                if (i > 0) std::cout << " after " << i << " probe(S)";
                break;
            }
            i++; //collision deteacted increments probe ocunt
        }


    }  
    std::cout << "\nFinal Table (Linear Probing):" <<std::endl;
    for (int idx = 0; idx < tableSize; ++idx) {
        std::cout << "[" << std::setw(2) << idx << "]: " << table [idx] << std::endl;
    }
    std::cout << std::endl;

}
int main(){
    std::vector<std::string> names = {
          "Mia", "Tim", "Bea", "Zoe", "Sue",
          "Len", "Moe", "Lou", "Rae", "Max", "Tod"
    };
    int tableSize = 11;

    std::vector<NameItem> items;
    for(const auto& name : names) {
        int sum = calculateAscii(name);
        items.push_back({name, sum, sum% tableSize});
    }
    // run both open addressing techniques
    insertLinear(items, tableSize);

    return 0;
}
