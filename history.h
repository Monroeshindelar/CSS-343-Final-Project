//------------------------------class History--------------------------------
//
// Class History: Holds data for command transactions
//
// Implementation and assumptions:
//    -- Derived class from Command
//
// Authors:
//---------------------------------------------------------------------------

#ifndef HISTORY_H_
#define HISTORY_H_
#include "command.h"
#include <sstream>
class History: public Command {

public:
	History();
	History(int);  // Constructor

	// Getters and Setters
	int getAccountID() const;
	void setAccountID(int);
	bool setData(ifstream&);
	string getString() const;
private:
   int accountID; // Holds account ID

};



#endif /* HISTORY_H_ */
