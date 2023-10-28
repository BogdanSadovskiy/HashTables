using namespace std;
#include <iostream>
#include "HashTable.h"
int main()
{

	int tableSize;
	cout << "Input table size : "; cin >> tableSize;
	Hash hash(tableSize);
	string value;
	while (true) {
		
		cout << "0 - exit\n";
		cout << "Input word - "; cin >> value;
		if (value == "0") {
			break;
		}
		hash.addHash(value);
	}
	cout << endl;
	hash.getHash();

}
