 //------------------------------class bstree-----------------------------------
// ADT BSTree: wrapper data structure  class to hold clients.
//
//
// Implementation and assumptions:
//    -- Clients are sorted by account number.
//    -- All functions are implemented recursively.
//    -- display() displays tree data in order.
//
// Authors:
//-----------------------------------------------------------------------------
/*
This class is a representation of a binary search tree. It
is made up of nodes which have a Customer data item, as well
as pointers to nodes on their left and on their right. This
class has only one private instance variable, which a node
that represents the start of the tree. This class has one
constructors. Users can insert a Customer item into the 
tree with the insert method, gain access to an element in the 
tree with the retrieve method, check if the tree contains an element with the
contains method, get the contents of the tree inorder in a string with
the display method, clear all of the nodes in a tree with the makeEmpty function
The output operator is also overriden so that it outputs the contents of the 
tree.
*/
#ifndef BSTREE_H_
#define BSTREE_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include "movie.h"
using namespace std;

class BSTree {

	public:
		BSTree();                                    // Constructor
		virtual ~BSTree();                                   // Destructor
		virtual bool insert(Movie*);

		// Insert into tree
		bool retrieve(Movie*, Movie*&)const;   // Retrieve object (no delete)
//		bool retrieveByID(const int, Movie*&) const; // Overload for retrieving
                                                // via client Number
		void display()const;                         // display Tree
		void makeEmpty();                            // Destroy tree
		bool isEmpty()const;                         // Check if tree is null

		// Checks if tree contains client by ClientID
//		bool contains(const int) const;
	private:
		struct Node{
			Node(Movie* neoData, Node* neoRight, Node* neoLeft) {
			data = neoData;
			right = neoRight;
			left = neoLeft;
		}
			Movie* data;
			Node* right;
			Node* left;
		};
		Node* root;                                  // Root of tree

   //Recursive helpers
		Node* insertHelper(Movie*, Node*);
		Node* makeEmptyHelper(Node*);
		string displayHelper(Node*) const;
		bool retrieveHelper(Movie*, Movie*&, Node*) const;
//		bool retrieveByIDHelper(const int, Movie*&, Node*) const;
//		bool containsHelper(const int, Node*) const;

};
#endif /* BSTREE_H_ */


