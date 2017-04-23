//------------------------------class CommandFac-----------------------------
//
// Class CommandFac: static helper class for object type selection
//
// Implementation and assumptions:
//    -- Static class
//
// Authors:
//---------------------------------------------------------------------------
#ifndef SRC_COMMANDFAC_H_
#define SRC_COMMANDFAC_H_
#include "command.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"
#include <iostream>

using namespace std;

class CommandFac {

public:
	CommandFac();
	~CommandFac();
	static Command* createCommand(const char&);   // returns appropriate object

};

#endif /* SRC_COMMANDFAC_H_ */
