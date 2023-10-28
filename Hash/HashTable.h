#pragma once
#include<iostream>
#define zero -1
using namespace std;
class Hash
{
private:
	int tableSize;
	class Node {
	public:
		int hashCode;
		string value;
		Node* next;
		Node();
		Node(int hashCode, std::string value);

		
	};
	Node** arr;
	public:

	Hash(int tableSize);
	void addHash(std:: string value);
	void getHash();


};

