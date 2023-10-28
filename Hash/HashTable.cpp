#include "HashTable.h"



Hash::Hash(int tableSize) {
	this->tableSize = tableSize;
	this->arr = new Node*[tableSize];
	for (int i = 0; i < this->tableSize; i++) {
		arr[i] = nullptr;
	}

}

Hash::Node::Node() {
	this->hashCode = 0;
	this->value = "";
	this->next = nullptr;
}
Hash::Node::Node(int hashCode, std:: string value) {
	this->hashCode = hashCode;
	this->value = value;
	this->next = nullptr;

}


int createHash(std::string value, int tableSize) {
	int hash = 0;
	for (int i = 0; value[i] != '\0'; i++) {
		hash = (hash * 31 + static_cast<int>(value[i])) % tableSize;
	}
	return abs(hash);
}

void Hash::addHash(std::string value) {
	int hash = createHash(value, this->tableSize);
	Node* newNode = new Node(hash, value);
	for (int i = 0; i < this->tableSize; i++) {
		if (arr[i] == nullptr) {
			arr[i] = newNode;
			break;
		}
		Node* tmp = arr[i];
		if (arr[i]->hashCode == hash) {
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = newNode;
			break;
		}

	}
}

void Hash::getHash() {

	for (int i = 0; i < this->tableSize; i++) {
		Node* tmp = arr[i];
		if (arr[i] == nullptr) {
			break;
		}
		cout << "Hash Nodes " << i + 1 << ":\n";
		while (tmp != nullptr) {
			cout << tmp->value << " - ";
			cout << tmp->hashCode << "; ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}