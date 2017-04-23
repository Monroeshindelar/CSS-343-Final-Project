//------------------------------class Return---------------------------------
//
// Class Return: Holds data for return transactions
//
// Implementation and assumptions:
//    -- Derived class from Command
//
// Authors:
//---------------------------------------------------------------------------

#ifndef RETURN_H_
#define RETURN_H_
#include "command.h"

class Return: public Command {

public:

   // Default constructor
   Return();
   Return(int, int, int, char, char, string, string);

   // Getters and Setters
   char getMediaType() const;
   void setMediaType(char);
   char getMovieType() const;
   void setMovieType(char);
   string getTitle() const;
   void setTitle(string);
   int getReleaseYear() const;
   void setYear(int);
   int getDay() const;
   void setDay(int);
   string getDirector() const;
   void setDirector(string);
   string getActorFirst() const;
   void setActorFirst(string);
   string getActorLast() const;
   void setActorLast(string);
   int getAccountID() const;
   void setAccountID(int);
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
   
   string actorFirst; 
   string actorLast;
};

#endif /* RETURN_H_ */
