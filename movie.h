//------------------------------class Movie----------------------------------
//
// Class Movie: Holds movie object data
//
// Implementation and assumptions:
//    -- Base class for movie inheritance hierarchy
//
// Authors:
//---------------------------------------------------------------------------

#ifndef MOVIE_H_
#define MOVIE_H_

#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include "stdio.h"

using namespace std;

class Movie {
	friend ostream& operator<<(ostream &, const Movie &);
public:

   Movie(char, int, int, string, string); // Constructor
   Movie();
   ~Movie();                              // Destructor

   // Getters and Setters
   char getMovieType() const;
   void setMovieType(char);
   int getStock() const;
   void setStock(int);
   int getReleaseYear() const;
   void setReleaseYear(int);
   string getDirector() const;
   void setDirector(string);
   string getTitle() const;
   void setTitle(string);
   string getActorFirst() const;
   void setActorFirst();
   string getActorLast() const;
   void setActorLast();
   int getReleaseDay() const;
   void setReleaseDay();
   virtual void setData(ifstream&);
   virtual string getActor() const;
   // Operators
   virtual bool operator<(const Movie&) = 0;
   virtual bool operator>(const Movie&) = 0;
   virtual bool operator==(const Movie&) = 0;

   virtual void print(ostream&) const;
protected:

   char movieType;   // Holds movie type (C,D,F)
   int stock;        // Stock (number of movies avaliable)
   string director;  // Directors name
   string title;     // Movie title's name
   int releaseYear;  // Movie release year

};

#endif /* MOVIE_H_ */
