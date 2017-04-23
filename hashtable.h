//------------------------------class HashTable--------------------------------
//
// Class HashTable wrapper data structure  class to hold clients.
//
//
// Implementation and assumptions:
//    -- Clients are sorted by account number.
//    -- All functions are implemented recursively.
//    -- display() displays tree data in order.
//
// Authors:
//-----------------------------------------------------------------------------
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include "customer.h"

class HashTable {
	private:
		LinkedList* table;			//holds clients
		int hashFunc(int);			//hash function
		int length;
	public:
		HashTable(int = 13);		//hash table
		~HashTable();				//destructor
		void insert(Customer*);		//inserts customers into hash table
		bool remove(int);			//remove from hash table
		bool getItemByKey(int, Customer*&);	//returns item by key
		int getNumberOfItems();		//returns number of items
		int getLength();			//returns length
		void printTable();			//prints hashtable
};

#endif