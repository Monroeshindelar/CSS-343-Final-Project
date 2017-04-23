#include "return.h"

//-------------------------Return-----------------------------------
//Precondition: Need to construct a command object
//Postcondition: command Object constructed
/*
Borrow: Default constuctor for return. Only exists because there were
errors without it
*/
Return::Return() {}
//-------------------------Return(7 arg)-----------------------------------
//Precondition: Need to construct a command object
//Postcondition: Borrow object constructed
/*
Return(7 arg): This is a constructer which takes in what is necessary 
in order to construct a command object.
*/
Return::Return(int acc, int y, int d, char media, char movie, string t, 
	string dir) {
	accountID = acc;
	setYear(y);
	setDay(d);
	setMediaType(media);
	setMovieType(movie);
	setTitle(t);
	setDirector(dir);
	setCommandType('R');
}

//-------------------------GetAccountID-----------------------------------
//Precondition: Need constructed return object with an accound ID
//Postcondition: int that represents account id returned
/*
GetAccountID: reurns the accountID for the account id stored in the command
*/
int Return::getAccountID() const {
	return accountID; //return the account id
}
//-------------------------SetAccountID-----------------------------------
//Precondition: Need a constructed return object
//Postcondition: AccountID in return object set
/*
SetAccountID: sets the accoundID in the object
*/
void Return::setAccountID(int acc) {
	if(acc > 0) accountID = acc; //set the accound id in the object
}
//-------------------------GetMediaType-----------------------------------
//Precondition: Need a constructed borrow object with a media type
//Postcondition: Media type returned
/*
GetMediaType: return the media type stored in the borrow object
*/
char Return::getMediaType() const {
	return mediaType; //return the media type
}
//-------------------------setMediaType-----------------------------------
//Precondition: Need a constructed return object
//Postcondition: Media type in the object is set 
/*
SetMediaType: sets the media type in the command object
*/
void  Return::setMediaType(char type) {
	mediaType = type; //set the media type
}
//-------------------------GetMovieType-----------------------------------
//Precondition: Need a constructed return object with a movie type
//Postcondition: Movie Type returned
/*
GetMovieType: returns the type of the movie that is stored in the command
*/
char Return::getMovieType() const {
	return movieType; //return the movie type
}
//-------------------------SetMovieType-----------------------------------
//Precondition: Need a constructed Return object
//Postcondition: Movie type in borrow object is set
/*
SetMovieType: sets the movie type in the command object
*/
void Return::setMovieType(char type) {
	if(	type == 'c' || type == 'C' || //check if its legal
		type == 'd' || type == 'D' ||
		type == 'f' || type == 'F') {
			movieType = type; //set the movie type
		}
}
//-------------------------GetTitle-----------------------------------
//Precondition: Need a constructed command object with a title
//Postcondition: Movie title in command object is returned
/*
GetTitle: returns the title stored in the command object
*/
string Return::getTitle() const {
	return title; //return the title
}
//-------------------------SetTitle-----------------------------------
//Precondition: Need a constructed command objects
//Postcondition: Movie title is set
/*
SetTitle: sets the title in the command
*/
void Return::setTitle(string t) {
	title = t; //set the title
}
//-------------------------GetReleaseYear-----------------------------------
//Precondition: Need a constructed command object with a year
//Postcondition: Release year is returned
/*
GetReleaseYear: returns the release year in the borrow object
*/
int Return::getReleaseYear() const {
	return year; //get the release year
}
//-------------------------SetReleaseYear-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Release year is set
/*
setReleaseYear: sets the release year in a the command object
*/
void Return::setYear(int y) {
	if(y > 1886) year = y; //set the release year
}
//-------------------------GetReleaseDay-----------------------------------
//Precondition: Need a constructed command object with a day
//Postcondition: Release day returned
/*
GetReleaseDay: Returns the release day of an object
*/
int Return::getDay() const {
	return day; //return the day
}
//-------------------------setReleaseDay-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: release day set
/*
SetReleaseDay: sets the release day in a command object
*/
void Return::setDay(int d) {
	if(d > 0 && d < 31) day = d; //set the day
}
//-------------------------GetDirector----------------------------------
//Precondition: Need a constructed command obeject with a director
//Postcondition: Director returned
/*
GetDirector: Returns the director stored in the command object
*/
string Return::getDirector() const {
	return director; //return the director
}
//-------------------------SetDirector-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Director set
/*
SetDirector: sets the director in the command object
*/
void Return::setDirector(string dir) {
	director = dir; //set the director
}
//-------------------------GetActorLast-----------------------------------
//Precondition: Need a constructed command object with an actor
//Postcondition: Returns the last name of the major actor
/*
GetActorLast: Returns the last name of the major actor
*/
string Return::getActorLast() const {
	return actorLast; //return the last name of the actor
}
//-------------------------SetActorLast-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Actor last is set
/*
SetActorLast: Actor last name is set
*/
void Return::setActorLast(string last) {
	actorLast = last; //set the last name of the actor
}
//-------------------------GetActorFirst-----------------------------------
//Precondition: Need a constructed command object with an actors first name
//Postcondition: actor first name returned
/*
GetActorFirst: Returns the first name of the actor.
*/
string Return::getActorFirst() const {
	return actorFirst; //get the actors first name
}
//-------------------------SetActorFirst-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Actors first name is set
/*
SetActorFirst: sets the first name of the actor in the command object
*/
void Return::setActorFirst(string first) {
	actorFirst = first; //set actors first name
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
bool Return::setData(ifstream& infile) {
	infile >> accountID >> mediaType; //read the accound and the media type
	if (mediaType != 'D') { //check if the media type is legal
		cout << "Unknown media type: " << mediaType << endl;
		return false; //return false
	}
	infile >> movieType; //read the movie type in 
	switch (movieType) { //switch on the movie type
	case 'F': //comedy
		getline(infile, title, ','); //read title
		infile >> year; //read year
		infile.ignore(1, '\n');
		break;
	case 'D': //drama
		getline(infile, director, ','); //read director
		getline(infile, title, ','); //read year
		infile.ignore(1, '\n');
		break;
	case 'C': //classic
		//read release day, year, actor first, actor last.
		infile >> day >> year >> actorFirst >> actorLast;
		infile.ignore(1, '\n');
		break;
	default: //otherwise
		cout << "Unknown movie type: " << movieType << endl;
		string skip;
		getline(infile, skip); //skip it
		return false; //return false
	}
	commandType = 'R'; //set the command type 
	return true; //return true.
}
//-------------------------GetString-----------------------------------
//Precondition: Need a constructred command object
//Postcondition: String returned with contents of command
/*
GetString: Returns a string that represents the contents of the command.
For use with history.
*/
string Return::getString() const {

	return "Returned " + getTitle() + "."; //return contents of the command
}