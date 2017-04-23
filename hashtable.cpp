#include "hashtable.h"
//-------------------------HashTable-------------------------
//Precondition: Nothing
//Postcondition: Hashtable initialized
/*
HashTable: constructor for the hash table. First checks to see
if the table length was valid. Then makes a new array of linked
lists and sets length equal to the table length
*/
HashTable::HashTable(int tableLength) {
	if(tableLength <= 0) tableLength = 13; //saftey check
	table = new LinkedList[tableLength]; //make a new linked list arrya
	length = tableLength; //set the length equal to table length
}
//-------------------------~HashTable-------------------------
//Precondition: Need an instantiated hash table
//Postcondition: Hash table memory deleted
/*
~HashTable: Destructor for hash table. First loops through all the
linked lists and emptys them, then it deletes the array
*/
HashTable::~HashTable() {
	//loop through the whole array
	for(int i = 0; i < length; i++) {
		table[i].makeEmpty(); //delete everything in the arrya
	}
	delete[] table; //delete the array
}
//-------------------------HashFunc-------------------------
//Precondition: Need an instantiated Hash Table
//Postcondition: Items able to be hashed into the array
/*
HashFunc: Determines where items go in the array. Returns
the key of the item %'d by the length of the table.
*/
int HashTable::hashFunc(int key) {
	return key % length; //return the key % the table length
}
//-------------------------Insert-------------------------
//Precondition: Need an item to insert into the hash table
//Postcondition: item inserted into the hash table
/*
Insert: Inserts an item into the hash table. First hashes the
item based on its key and then inserts it into the array.
*/
void HashTable::insert(Customer* in) {
	int index = hashFunc(in->getAccountNum()); //hash the key
	table[index].insert(in); //inset the item into the hash bucket
}
//-------------------------Remove-------------------------
//Precondition: Need an item to remove from the index
//Postcondition: Item removed from the hash table.
/*
Remove: gets the index of the item and then calls the
linked list remove function on that item
*/
bool HashTable::remove(int key) {
	int index = hashFunc(key); //get the index of the item to remove
	return table[index].remove(key); //remove the item
}
//-------------------------GetItemByKey-------------------------
//Precondition: Need items in an instantiated hash table
//Postcondition: item retrieved from like
/*
GetItemByKey: takes in a key to search for an item, and then it
searches the linked list in that index for the item and if it
exists then we put it in to store
*/
bool HashTable::getItemByKey(int key, Customer*& toStore) {
	int index = hashFunc(key); //get the index
	//
	return table[index].getItem(key, toStore);
}
//-------------------------GetLength-------------------------
//Precondition: Need a hash table
//Postcondition: length of hash table returned
/*
GetLength: returns the length of the hash table
*/
int HashTable::getLength() {
	return length; //return length
}
//-------------------------GetNumberofItems-------------------------
//Precondition: Need a hash table
//Postcondition: number of items returned
/*
GetNumberOfItems: Gets the number of items in the hash table. Loops
through every linked list and gets the count of the items in the
linked list
*/
int HashTable::getNumberOfItems() {
		int count = 0; //start the cont at 0
		for(int i = 0; i < length; i++) { //loop throug all buckets
			count += table[i].getLength(); //add one to the count
		}
		return count; //return the count
}
//-------------------------PrintTable-------------------------
//Precondition: Need a hash table
//Postcondition: table printed
/*
PrintTable: Prints the contents of each bucket. Loops through 
each bucket and calls print list on each bucket.
*/
void HashTable::printTable() {
	//loop through all the buckets
	for(int i = 0; i < length; i++) {
		cout << "Bucket" << i + 1 <<": ";
		table[i].printList(); //print the data
	}
}
