#include "bstree.h"
//------------------------------BinTree Constructor------------------------------
//Precondition: None
//Postcondition: Binary tree constructed
/*
BinTree Constructor: This is the defualt constructor for a binary tree. All we do here is 
set the root to NULL. Nothing else needs to be initialized.
*/
BSTree::BSTree() {
	root = NULL;
}
//------------------------------BinTree Destructor------------------------------
//Precondition: Binary Tree to destruct
//Postcondition: All the dynamic memory in a binary tree is deleted
/*
BinTree Destructor: This is the destructor for the binarysearchtree. It calls the 
makeEmpty method to delete all of the nodes in the tree, which are dynamically allocated. 
*/
BSTree::~BSTree() {
	makeEmpty();
	root = NULL;
}
//------------------------------ Insert (Facade)------------------------------
//Precondition: Need an instantiated tree, and an item to insert
//Postcondition: Item inserted into the tree
/*
Insert: This is a method that inserts an item in to the tree. It calls
the private insert method, hands it the data the user wanted to insert as well
as the root of the tree. Then it returns the status of the mission.
*/
bool BSTree::insert(Movie* in) {
	root = insertHelper(in, root); //call the helper
	return true; //return true
}
//------------------------------ Insert ------------------------------
//Precondition: Need an instantiated tree, and an item to insert
//Postcondition:  Item inserted in to the tree
/*
Insert: The goal of this function is to insert an item into its correctly sorted
place in the tree. First it checks to see if the current node(which starts at root)
if NULL, if it is we have found the spot in the tree where we need to insert
so we will make a new node here and pass it the data we wanted to insert, as well as
NULL for the left and right pointers in the node. If we have not found the NULL node
we will check to see if the data we are trying to insert is less than the data of the
current node we are looking at. If so we will set the left pointer of the current node
to whatever is returned by recalling this method with the node that is stored in the left
pointer of the current node. Otherwise we will set the right pointer of the current node
equal to whatever is returned by recalling this fucntion with whatever is present in the
right pointer in the current node. Then we return the node we are working on, which should 
bubble up to the root node.
*/
BSTree::Node* BSTree::insertHelper(Movie* in, Node* subtree) {
	if (subtree == NULL) { //check to see if we have hit NULL 
		subtree = new Node(in, NULL, NULL); //if we have, we make a new node here
	} else if (*in < *subtree->data) { //do we go left?
		subtree->left = insertHelper(in, subtree->left); //go left
	} else if(*in >  *subtree->data){ //do we go right?
		subtree->right = insertHelper(in, subtree->right); //go right
	} else if(*in == *subtree->data) { //do we already have this in the tree?
		subtree->data->setStock(subtree->data->getStock() + in->getStock());  //add the stocks
	}
	return subtree; //return the current node
}
//------------------------------ Retrieve (Facade)------------------------------
//Precondition: Need instantiated tree, an item to search for, and an item to store the found item
//Postcondition: toStore returned empty if it didnt find the element, or containing the element if it was found
/*
Retrieve: Takes in a Movie object reference and a Movie reference pointer. Attempts to find
the object in the tree. If the object is found it is stored in toStore.
*/
bool BSTree::retrieve(Movie* toFind, Movie*& toStore) const {
	return retrieveHelper(toFind, toStore, root); //call the helper
}
//------------------------------ Retrieve ------------------------------
//Precondition: Need instantiated tree, an item to search for, and an item to store the found item
//Postcondition: toStore returned empty if it didnt find the element, or containing the element if it was found
/*
Retrieve: the goal of this function is to find an element in the list and grant access to that element
through the second parameter. First we check to see if we have hit NULL. If we have we didnt 
find the element so we will return false. Next we check to see if the current nodes data is what we 
are looking for, if so then we set toStore equal to a reference to the subtrees data, and returns true. 
Otherwise we check to see if the data in the node is greater than the data we are looking for, if so 
then we recall this function with the node to the left of the current subtree. Otherwise we go right.
*/
bool BSTree::retrieveHelper(Movie* toFind, Movie*& toStore, Node* subtree) const {
	if (subtree == NULL) return false; //check to see if we have hit the end of the list
	if (*subtree->data == *toFind) { ///check to see if we have hit the item we are looking for
		toStore = subtree->data; //if so store it
		return true; //return true
	}
	else if (*toFind > *subtree->data) { //do we go to the right?
		return retrieveHelper(toFind, toStore, subtree->right); //keep going to the right
	} else { //do we go to the left?
		return retrieveHelper(toFind, toStore, subtree->left); //keep going to the left
	}
}

//------------------------------ Display (Facade) ------------------------------
//Precondition: Need an existing tree
//Postcondition: Contents of tree printed
/*
Display: Prints the contents of the tree
*/
void BSTree::display() const {
	cout << displayHelper(root) << endl;
}
//------------------------------ Display ------------------------------
//Precondition: Need an existing tree
//Postcondition: String returned that contains the contents of the tree inorder
/*
Display: Creates a string that holds the contents of the tree inorder. A string
stream is made that will store the contents of the tree. Then we check to see
if the current subtree isnt NULL. If it isnt NULL, then we will add whatever is
returned by this method being recalled with the current nodes left pointer to the
string stream. Next we add the data that is in the current subtree to the string
stream follwed by a space for formatting, then we add whatever is returned by
calling this method again with the right pointer of the current node to the
string stream. Then the string stream is turned into a string and it is returned.
*/
string BSTree::displayHelper(Node* subtree) const {
	stringstream ss; //string stream to store contents
	if (subtree != NULL) { //while there are items inthe subtree
		ss << displayHelper(subtree->left); //go to the left
		ss << *subtree->data; //add the data to the subtree
		ss << " "; 
		ss << displayHelper(subtree->right); //go the the right
	}
	return ss.str(); //make a stirng
}
//------------------------------ Make Empty (Facade) ------------------------------
//Precondition: Need an existing tree with elements to delete
//Postcondition: Tree emptied and memory deleted
/*
Make Empty: Deletes all of the elements in the tree.
*/
void BSTree::makeEmpty() {
	root = makeEmptyHelper(root); //change root
}
//------------------------------ Make Empty ------------------------------
//Precondition: Need an existing tree with elements to delete
//Postcondition: Tree emptied and memory deleted
/*
Make Empty: Deletes all of the elements in the tree. Checks to see if the current 
subtree is NULL. If its not, then call this function again twice with the left
and the right node, then delete the current subtree,
*/
BSTree::Node* BSTree::makeEmptyHelper(Node* subtree) {
	if (subtree != NULL) { //check if there is tree
		makeEmptyHelper(subtree->left); //go to the left
		makeEmptyHelper(subtree->right); //go to the right
		subtree = NULL; //set subtree equal to NULL
		delete subtree; //delete the subtree
	}
	return subtree; //return the subtree
}

bool BSTree::isEmpty() const {
	return root == NULL;
}
