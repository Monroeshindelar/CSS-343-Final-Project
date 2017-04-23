//------------------------------class Comedy---------------------------------
//
// Class Comedy: Holds Comedy Movie object data
//
// Implementation and assumptions:
//    -- Derived class of Movie
//
// Authors: Monroe Shindelar and Mark Belyak 
//---------------------------------------------------------------------------
/*
comedy.h: This class is meant to be an extention of the movie class. It 
represents
the comedy genre of movies. It just exists to further define movies and doesnt 
add
any extra elements to the movie. There is a set data function which sets the
data
of the movie from a file. The operators are overriden so that comedy movies are 
comparable.
*/
#ifndef COMEDY_H_
#define COMEDY_H_
#include "movie.h"


class Comedy: public Movie {

   virtual ~Comedy();

public:
	Comedy(char);
	Comedy();
	Comedy(char, int, int, string, string);
	void setData(ifstream&);

	// Operator overloads
   bool operator<(const Movie&);
   bool operator>(const Movie&);
   bool operator==(const Movie&);

};

#endif /* COMEDY_H_ */
