//------------------------------class Borrow---------------------------------
//
// Class Borrow: Holds data for borrow transactions
//
// Implementation and assumptions:
//    -- Derived class from Command
//
// Authors:
//---------------------------------------------------------------------------

#ifndef BORROW_H_
#define BORROW_H_
#include "command.h"

class Borrow: public Command {
	
public:

   // Default constructor
   Borrow();
   Borrow(int, int, int, char, char, string, string);

   // Getters and Setters
   int getAccountID() const;
   void setAccountID(int);
   char getMediaType() const;
   void setMediaType(char);
   char getMovieType() const;
   void setMovieType(char);
   string getTitle() const;
   void setTitle(string);
   int getReleaseYear() const;
   void setReleaseYear(int);
   int getReleaseDay() const;
   void setReleaseDay(int);
   string getDirector() const;
   string getActorLast() const;
   void setActorLast(string);
   string getActorFirst() const;
   void setActorFirst(string);
   void setDirector(string);
   bool setData(ifstream&);
   string getString() const;


private:

   int accountID;    // Holds account number
   char mediaType;   // Type of media (eg 'D' = DVD)
   char movieType;   // Movie Type (C, D, F)
   string title;     // Title of the movie
   int year;         // Year of release
   int day;          // Day of release (classics only)
   string director;  // Director of movie
   string actorLast;
   string actorFirst;

};

#endif /* BORROW_H_ */
