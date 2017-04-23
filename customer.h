//------------------------------class Customer-------------------------------
//
// Class Customer: Holds customer data and command transactions
//
// Implementation and assumptions:
//    -- Commands are stored in an array.
//    -- commandHistory array doubles in size when resize is needed.
//
// Authors:
//---------------------------------------------------------------------------

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include <iomanip>
#include <fstream>
#include "command.h"
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include "movie.h"
using namespace std;

class Customer {

// ------------------------ Operator<< ----------------------------
// output operator
friend ostream& operator<<(ostream& out, const Customer& thisCustomer) {
	out << thisCustomer.accountNum << "	" << thisCustomer.lastName << "	" <<
		thisCustomer.firstName << endl;
	return out;
}

public:

   Customer(int, string, string);    // Default constructor
   Customer();						 // constructor
   ~Customer();                      // Destructor

   // Getters and Setters
   int getAccountNum() const;
   void setAccountNum(int);
   string getFirstName() const;
   void setFirstName(string);
   string getLastName() const;
   void setLastName(string);

   // Adds a command object to history
   void addCommandHistoryElement(Command*);

   //stack for history
   stack<string> borrowingHistory;

   //queue of customer's borrowed movies
   queue<Movie*> borrowedMovies;

   void displayHistory();		//display customer history

   void insertHistory(string historyToInsert);		//insert customer history

private:

   Command* commandHistory;      // Holds command objects
   int commandHistoryIndex;      // Index of next history object
   int commandHistoryArrayLength;// length of array
   int accountNum;               // Account number
   string firstName;             // First name
   string lastName;              // Last name

};


#endif /* CUSTOMER_H_ */
