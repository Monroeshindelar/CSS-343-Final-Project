#include "history.h"

// ------------------------ History ----------------------------
// default constructor
History::History() {}

// ------------------------ History ----------------------------
// constructor
History::History(int ID) {
	accountID = ID;
	setCommandType('H');
}

// ------------------------ getAccountID ----------------------------
// returns account id
int History::getAccountID() const {
	return accountID;
}

// ------------------------ setAccountID ----------------------------
// setAccountID
void History::setAccountID(int ID) {
	accountID = ID;
}

bool History::setData(ifstream& infile) {
	int acc = 0;
	infile >> acc;
	setCommandType('H');
	setAccountID(acc);
	return true;
}

