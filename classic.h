//------------------------------class Classic--------------------------------
//
// Class Classic: Holds Comedy Movie object data
//
// Implementation and assumptions:
//    -- Derived class of Movie
//
// Authors: Monroe Shindelar and Mark Belyak
//---------------------------------------------------------------------------
/*
classic.h: This class is meant to be an extension of the movie class. It 
represents the classic style of movie. It inherits from the movie class and adds
onto it. It adds a month of release as well as a major actor, represented by two 
strings, a first and a last name. This class has getters and setters for each of 
the data items that were added by classic, as well as a function to set the data
of the movie from a file. The < and > operators as well as the == operater have
been overwritten as well in order to properly compare classic movies. There is
also a print method that prints out the data of the movie.
*/
#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "movie.h"

class Classic: public Movie {
	friend ostream& operator<<(ostream &, const Classic &);
public:
	Classic();
   Classic(char, int, int, string, string, string, string, int);
   Classic(char type);
   virtual ~Classic();
   void setData(ifstream&);

   string getActor() const;

   void setActor(string af);

   // Getters and Setters
   string getActorFirst() const;
   void setActorFirst(string);
   string getActorLast() const;
   void setActorLast(string);
   int getReleaseDay() const;
   void setReleaseDay(int);

   // Operator overloads
   bool operator<(const Movie&);
   bool operator>(const Movie&);
   bool operator==(const Movie&);

   virtual void print(ostream&) const;
private:

   string actorFirst; // First name of actor
   string actorLast;  // Last name of actor
   int releaseDay;    // release day of movie.
   string actor;
};


#endif /* CLASSIC_H_ */
