#include "inventory.h"

Inventory::Inventory() {
	setCommandType('I');
}

bool Inventory::setData(ifstream& infile) {
	setCommandType('I');
	return true;
}

string Inventory::getString() const {

	return "Viewed store inventory.";
}