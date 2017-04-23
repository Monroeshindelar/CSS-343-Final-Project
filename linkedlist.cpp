#include "linkedlist.h"
//-------------------------LinkedList-------------------------
//Precondition: Nothing
//Postconditon: linked list instantiated
/*
LinkedList: constructs a linked list. Sets the head equal to NULL
and sets the length equal to 0.
*/
LinkedList::LinkedList() {
	head = NULL; //head is NULL
 	length = 0; //set the length to 0
}
//-------------------------~LinkedList-------------------------
//Precondition: Need a linked list
//Postcondition: Linked List deleted
/*
~LinkedList: deletes the memory in a linked list by calling the
make empty funciton
*/
LinkedList::~LinkedList() {
	makeEmpty(); //call make empty
}
//-------------------------Insert-------------------------
//Precondition: Need to insert item into linked list
//Postcondition: Item inserted into linked list
/*
Insert: Inserts an item into the linked list. Checks to 
see if the head is null, if its not we will insert there,
then checks to see if the head->next is null and if it is
we will insert there. If neither of those were true then
we will walk the list until the next node is NULL and we
will insert there.
*/
void LinkedList::insert(Customer* in) {
	//check to see if the list is empty
	if(head == NULL) head = new Node(in, NULL);
	//if there is one item in the list
	if(head->next == NULL) {
		//make a new node and attach to head
		head->next = new Node(in, NULL);
		length++;
		return;
	}
	//make nodes to walk the list
	Node* current = head;
	Node* previous = head;
	while(current != NULL) {
		//walk the list till we hit th end
		previous = current;
		current = current->next;
	}
	//stitch the node at the end
	current->next = new Node(in, NULL);
	length++;
}
//-------------------------Remove-------------------------
//Precondition: Need item to remove from tree
//Postcondition: Item removed from tree
/*
Remove: First checks to see if there are items to remove
from the tree. Then it starts two nodes that walk the list 
and walk until we hit the thing we want to delete and we
take it out of the list and delete it.
*/
bool LinkedList::remove(int key) {
	if(head == NULL) return false; //check if we have elements
	Node* current = head; //nodes to walk the list
	Node* previous = head;
	//loop until we find the item/hit the end
	while(current != NULL) {
		Customer* temp = current->data; //make a customer
		if(temp->getAccountNum() == key) { //get its account
			previous->next = current->next; //stich
			delete current; //delete current
			length--;
			return true;  //we are done
		}
		previous = current; 
		current = current->next;
	}
	return false; //we didnt find it 
}
//-------------------------GetItem-------------------------
//Precondition: Need to get item from the list
//Postcondition: Item retrieved from the list
/*
GetItem: searches the list for an item. If its found its stored
in a reference. Otherwise we return false.
*/
bool LinkedList::getItem(int key, Customer*& toStore) {
	Node* current = head; //nodes to walk the list
	Node* previous = head;
	//walk the lsit
	while(current != NULL) {
		previous = current;
		Customer* temp = previous->data;
		//check if we found the item
		if((previous != head) && (temp->getAccountNum() == key)) { 
			toStore = temp; //store it
			return true; //return true
		}
		current = current->next;
	}
	return false; //we didnt find it
}
//-------------------------GetLength-------------------------
//Precondition: Need a linked list
//Postcondition: length of linked list returned
/*
GetLength: returns the lenght of the linked list
*/
int LinkedList::getLength() {
	return length; //return the length
}
//-------------------------MakeEmpty-------------------------
//Precondition: Need a linked list
//Postcondition: Memory in a linked list deleted
/*
MakeEmtpy: Deletes all the memory in a linked list. Calls helper
*/
void LinkedList::makeEmpty() {
	head = makeEmpty(head);
}
//-------------------------MakeEmpty-------------------------
//Precondition: Need a linked List
//Postcondition: Memory in a link list deleted
/*
MakeEmpty: Traverses down to the bottom of the linked list and
bubbles up. Deletes items as it bubbles up
*/
LinkedList::Node* LinkedList::makeEmpty(Node* current) {
	if(current->next == NULL) { //when we hit the bottom
		delete current->data;  //delete shit
		current->data = NULL;
		delete current;
		//otherwise keep going down
	} else makeEmpty(current->next);
	return current;
}
//-------------------------PrintList-------------------------
//Precondition: Need a linked list
//Postcondition: Contents of kiled list printed
/*
PrintList: Walks through the list and prints all the items inside
*/
void LinkedList::printList() {
	if(length == 0) {
		cout << "\n{}\n" << endl;
		return;
	}
	//walk the list
	Node* current = head;
	Node* previous = head;
	while(current != NULL) {
		previous = current;
		if(previous != head) {
			//print the data
			cout << *previous->data << endl;
		}
		current = current->next;
	}
}