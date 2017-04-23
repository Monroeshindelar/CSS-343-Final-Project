//------------------------------class Store----------------------------------
//
// Class Store: main class for movie rental program.
//
// Implementation and assumptions:
//    -- Input files must be correctly formatted
//    -- Commands are stored in a queue
//    -- Movies are stored in a Binary Tree. One for each type
//    -- Customers are stored in a hash table
//    -- negative numbers or unexpected characters in input file are treated
//       as errors and discarded
//    -- dupicate movie file entries are discarded
//
// Authors:
//---------------------------------------------------------------------------

#ifndef STORE_H_
#define STORE_H_
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <queue>
#include "bstree.h"
#include "customer.h"
#include "command.h"
#include "movie.h"
#include "commandfac.h"
#include "moviefac.h"
#include <string>
#include "classic.h"
#include "borrow.h"
#include "comedy.h"
#include "drama.h"
#include "history.h"
#include "inventory.h"
#include "return.h"
#include "hashtable.h"

using namespace std;

class Store {

public:
	//const int ARRAY_SIZE = 103;
	Store();    // Constructor
	~Store();   // Destructor
	int run(); // Starts program flow, top level method.

private:

   int numCustomers; // holds number of customers objects created
   int numCommands;  // holds number of command objects created

   // Initializes customer data from file into hash table
   void initializeCustomers(ifstream&);
   // Initializes command data from file into queue
   void initializeCommands(ifstream&);
   // Initializes movie data from file int BSTree<type>
   void initializeMovies(ifstream&);

   void processTransactions(); // processes commands from queue

   
   // Data structures
   queue<Command*> commands;
   BSTree* comedies;    // Holds comedies movie objects
   BSTree* dramas;      // Holds drama movie objects
   BSTree* classics;    // Holds classic movie objects
   HashTable* customers;

};

#endif /* STORE_H_ */
