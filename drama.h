//------------------------------class Drama----------------------------------
//
// Class Drama: Holds Drama Movie object data
//
// Implementation and assumptions:
//    -- Derived class of Movie
//
// Authors:
//---------------------------------------------------------------------------
/*
drama.h: This class is meant to be an extention of the movie class. It
represents
the drama genre of movies. It just exists to further define movies and doesnt 
add
any extra elements to the movie. There is a set data function which sets the 
data
of the movie from a file. The operators are overriden so that drama movies are 
comparable.
*/
#ifndef DRAMA_H_
#define DRAMA_H_
#include "movie.h"

class Drama: public Movie {
	
	virtual ~Drama();


public:
	Drama();
	Drama(char type);
	Drama(char, int, int, string, string );
	void setData(ifstream&);
	// Operator overloads
	bool operator<(const Movie&);
	bool operator>(const Movie&);
	bool operator==(const Movie&);


};

#endif /* DRAMA_H_ */
