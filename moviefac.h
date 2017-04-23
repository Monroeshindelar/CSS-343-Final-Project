//------------------------------class MovieFac-------------------------------
//
// Class MovieFac: static helper class for object type selection
//
// Implementation and assumptions:
//    -- Static class
//
// Authors:
//---------------------------------------------------------------------------
#ifndef SRC_MOVIEFAC_H_
#define SRC_MOVIEFAC_H_
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
#include <iostream>

using namespace std;

class MovieFac {

public:
	MovieFac(); 
	~MovieFac();
	static Movie* createMovie(const char&);   // returns appropriate object

};

#endif /* SRC_MOVIEFAC_H_ */
