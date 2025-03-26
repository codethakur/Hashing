// #pragma once
#include <iostream>
#include <list>
#include <cstring>
#include <string>
#include <cassert>
#include <format> // Requires C++20+
#include <optional>

class HashTable
{
private:
	static constexpr int hashGroups = 10;
	std::list<std::pair<int, std::string>> table[hashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int key)const;
	void insertItem(int key, std::string value);
	void removeItem(int key);
    std::optional<std::string> searchTable(int key) const;
	void printTable() const;
};

bool HashTable::isEmpty() const
{
	int sum{};
	for (int i{}; i < hashGroups; i++)
	{
		sum += table[i].size();
	}
	if (!sum)
	{
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key) const
{
	return key % hashGroups;
}

void HashTable::insertItem(int key, std::string value)
{
	int hashValue = hashFunction(key);
	auto &cell = table[hashValue];
	//Check if key already exists and update value
	for (auto& [existingKey, existingValue] : cell) {
        if (existingKey == key) {
            existingValue = value;
            std::clog << std::format("[INFO] Key {} updated with value '{}'.\n", key, value);
            return;
        }
    }

    //  If key does not exist, insert it
    cell.emplace_back(key, value);
    std::clog << std::format("[INFO] Key {} inserted with value '{}'.\n", key, value);

}

void HashTable::removeItem(int key)
{
	int hashValue = hashFunction(key);
	auto &cell = table[hashValue];
	for (auto it = cell.begin(); it != cell.end(); ++it) {
        if (it->first == key) {
            cell.erase(it);
            std::clog << std::format("[INFO] Key {} removed.\n", key);
            return;
        }
    }

    std::cerr << std::format("[WARNING] Key {} not found. Cannot remove.\n", key);
}



//  Print the entire hash table
void HashTable::printTable() const {
    std::clog << "\n--- Hash Table ---\n";
    for (int i = 0; i < hashGroups; ++i) {
        if (table[i].empty()) continue;
        std::clog << std::format("Bucket {}: ", i);
        for (const auto& [key, value] : table[i]) {
            std::clog << std::format("[{}: {}] ", key, value);
        }
        std::clog << "\n";
    }
    std::clog << "-------------------\n";
}

// Search for a key in the table and return its value
std::optional<std::string> HashTable::searchTable(int key) const {
    int hashValue = hashFunction(key);
    const auto& cell = table[hashValue];

    for (const auto& [existingKey, existingValue] : cell) {
        if (existingKey == key) {
            std::clog << std::format("[INFO] Key {} found with value '{}'.\n", key, existingValue);
            return existingValue;
        }
    }

    std::cerr << std::format("[WARNING] Key {} not found.\n", key);
    return std::nullopt;
}











#if 0
int main() {
    HashTable HT;

    if (HT.isEmpty()) {
        std::clog << "[Correct]: Table is Empty.\n";
    } else {
        std::cerr << "[ERROR]: Table should be empty initially!\n";
    }

    HT.insertItem(101, "Shyam");
    HT.insertItem(101, "Madhav"); // Should update key 101
    HT.insertItem(103, "Vinod");
    HT.insertItem(405, "Vikash");
    HT.insertItem(505, "Ricky");

    HT.printTable();

    HT.removeItem(103);
    HT.removeItem(505);

    std::cout << "\n------------------------------------\n";
    HT.printTable();

    //  Searching for an existing and a non-existing key
    if (auto result = HT.searchTable(101)) {
        std::cout << std::format("Search Result: {}\n", *result);
    } else {
        std::cout << "Key not found.\n";
    }

    if (auto result = HT.searchTable(999)) {
        std::cout << std::format("Search Result: {}\n", *result);
    } else {
        std::cout << "Key not found.\n";
    }

    return 0;
}
#endif

#if 0
std::tuple<int, std::string> data = {101, "Madhav"};

std::stringstream ss;
ss << "[INFO] Key " << std::get<0>(data) 
   << " inserted with value '" << std::get<1>(data) << "'.\n";

std::cout << ss.str(); // Output: [INFO] Key 101 inserted with value 'Madhav'.
#endif
// g++ -std=c++20 problem.cpp -o problem.exe -lstdc++
// PS A:\Sorting\problem> .\problem.exe
