#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "customer.h"
#include <iostream>
#include <string>

class LinkedList {
	friend ostream& operator<<(ostream& out, const LinkedList& target) {
		Node* current = target.head;
		while(current != NULL) {
			out << *current->data;
			current = current->next;
		}
		return out;
	}
	public:
		LinkedList();
		~LinkedList();
		void insert(Customer*);
		bool remove(int);
		bool getItem(int, Customer*&);
		int getLength();
		void makeEmpty();
		void printList();
		
	private:
		struct Node {
			Node(Customer* d, Node* n) {
				data = d;
				next = n;
			};
			Customer* data;
			Node* next;
		};
		Node* head;
		int length;
		Node* makeEmpty(Node*);
		
};

#endif