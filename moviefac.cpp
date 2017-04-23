#include "moviefac.h"

// ------------------------ MovieFac ----------------------------
// default constructor
MovieFac::MovieFac() {}

// ------------------------ MovieFac ----------------------------
// destructor
MovieFac::~MovieFac() {}

// ------------------------ createMovie ----------------------------
// create movie object based on type
Movie* MovieFac::createMovie(const char& type) {
	switch(type) {
		case 'F':
			return new Comedy(type);
		case 'D':
			return new Drama(type);
		case 'C':
			return new Classic(type);
		default:
			cout << "Unrecognized Genre" << endl;
			return NULL;
	}
}