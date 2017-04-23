#include "command.h"
//-------------------------Command-----------------------------------
//Precondition: Need to construct a command object
//Postcondition: command Object constructed
/*
Borrow: Default constuctor for return. Only exists because there were
errors without it
*/
Command::Command() {}
//-------------------------Command(1 arg)-----------------------------------
//Precondition: Need to construct a command object
//Postcondition: Command object constructed
/*
Command1 arg): This is a constructer which takes in what is necessary 
in order to construct a command object.
*/
Command::Command(char type) {
	setCommandType(type);
}
//-------------------------~Command-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Command object deleted
/*
~Command: Manages the dynamic memory of a command.
*/
Command::~Command() {}
//-------------------------GetCommandType-----------------------------------
//Precondition: Need a constucted command object
//Postcondition: returns the command type
/*
GetCommandType: Returns the command type of the command object
*/
char Command::getCommandType() const {
		return commandType; //return the commandtype
}
//-------------------------SetCommandType-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: sets the command type 
/*
SetCommandType: Sets the command type of a command object
*/
void Command::setCommandType(char type){
	commandType = type; //set the command type
}
//-------------------------GetAccountID-----------------------------------
//Precondition: Need constructed return object with an accound ID
//Postcondition: int that represents account id returned
/*
GetAccountID: reurns the accountID for the account id stored in the command
*/
int Command::getAccountID() const{
	return -1; //override please
}
//-------------------------GetMediaType-----------------------------------
//Precondition: Need a constructed borrow object with a media type
//Postcondition: Media type returned
/*
GetMediaType: return the media type stored in the borrow object
*/
char Command::getMediaType() const{
	return 'x'; //override please
}
//-------------------------GetMovieType-----------------------------------
//Precondition: Need a constructed return object with a movie type
//Postcondition: Movie Type returned
/*
GetMovieType: returns the type of the movie that is stored in the command
*/
char Command::getMovieType() const{
	return 'x'; //override please
}
//-------------------------GetTitle-----------------------------------
//Precondition: Need a constructed command object with a title
//Postcondition: Movie title in command object is returned
/*
GetTitle: returns the title stored in the borrow object
*/
string Command::getTitle() const{
	return "Title placeholder";  //override please
}
//-------------------------GetReleaseYear-----------------------------------
//Precondition: Need a constructed command object with a year
//Postcondition: Release year is returned
/*
GetReleaseYear: returns the release year in the borrow object
*/
int Command::getReleaseYear() const{
	return -1; //override please
}
//-------------------------GetReleaseDay-----------------------------------
//Precondition: Need a constructed command object with a day
//Postcondition: Release day returned
/*
GetReleaseDay: Returns the release day of an object
*/
int Command::getReleaseDay() const{
	return -1; //override please
}
//-------------------------GetDirector----------------------------------
//Precondition: Need a constructed command obeject with a director
//Postcondition: Director returned
/*
GetDirector: Returns the director stored in the command object
*/
string Command::getDirector() const{
	return "Director placeholder"; //override please
}
//-------------------------GetActorLast-----------------------------------
//Precondition: Need a constructed command object with an actor
//Postcondition: Returns the last name of the major actor
/*
GetActorLast: Returns the last name of the major actor
*/
string Command::getActorFirst() const {
    return "Firstname placholder"; //override please
}
//-------------------------GetActorFirst-----------------------------------
//Precondition: Need a constructed command object with an actors first name
//Postcondition: actor first name returned
/*
GetActorFirst: Returns the first name of the actor.
*/
string Command::getActorLast() const
{
    return "Lastname placholder";
}
//-------------------------SetData----------------------------------
//Precondition: Need a constructed command obejct and a file
//Postcondition: File read and made into a command object
/*
SetData: Reads data from the file and inserts it into a command object
First it reads in the account id and the media type. Then it checks
to see if the media type is legal, if its not then its skips the line
and returns false, otherwise we read in the movie type and switch on
the movie type, if its f then we read in the title and the year, if its
d then we read the director and the title, and if its c then we read
in the day, year, actor first, and actor last. Then we set the command
type is returned true.
*/
bool Command::setData(ifstream& infile){
	return false; //override please
}

ostream& operator<<(ostream &output, const Command &a) {

	return output;
}