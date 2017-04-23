#include "commandfac.h"

// ------------------------ CommandFac ----------------------------
// default constructor
CommandFac::CommandFac() {}

// ------------------------ CommandFac ----------------------------
// destructor
CommandFac::~CommandFac() {}

// ------------------------ createCommand ----------------------------
// createCommand object based on type
Command* CommandFac::createCommand(const char& op) {
	switch(op) {
		case 'I':
			return new Inventory();
			break;
		case 'H':
			return new History();
			break;
		case 'B':
			return new Borrow();
			break;
		case 'R':
			return new Return();
			break;
		default:
			cout << "Unrecognized Command" << endl;
			return NULL;
			break;
	}
	
}