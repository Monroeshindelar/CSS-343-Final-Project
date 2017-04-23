//------------------------------class Inventory------------------------------
//
// Class Inventory: Holds data for command transactions
//
// Implementation and assumptions:
//    -- Derived class from command
//
// Authors:
//---------------------------------------------------------------------------

#ifndef INVENTORY_H_
#define INVENTORY_H_
#include "command.h"


class Inventory: public Command {
		
	public: 
		
		Inventory();
		bool setData(ifstream&);
		string getString() const;
};

#endif /* INVENTORY_H_ */
