//------------------------------class Command--------------------------------
//
// Class Command: Holds data for movie transactions
//
// Implementation and assumptions:
//    -- Base class in inheritance hierarchy
//
// Authors:
//---------------------------------------------------------------------------

#ifndef COMMAND_H_
#define COMMAND_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Command {

	friend ostream& operator<<(ostream& output, const Command& thisCommand);
   

public:
	Command();
	Command(char); // Default constructor
	~Command();    // Destructor

   // Getters and Setters
   char getCommandType() const;
   void setCommandType(char);
   virtual int getAccountID() const;
   virtual char getMediaType() const;
   virtual char getMovieType() const;
   virtual string getTitle() const;
   virtual int getReleaseYear() const;
   virtual int getReleaseDay() const;
   virtual string getDirector() const;
   virtual string getActorFirst() const;
   virtual string getActorLast() const;
   virtual bool setData(ifstream&);

protected:

   char commandType; // Holds command type

};


#endif /* COMMAND_H_ */
