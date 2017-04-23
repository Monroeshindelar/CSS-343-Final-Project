#include "borrow.h"
//-------------------------Borrow-----------------------------------
//Precondition: Need to construct a borrow object
//Postcondition: Borrow Object constructed
/*
Borrow: Default constuctor for borrow. Only exists because there were
errors without it
*/

Borrow::Borrow() {}

//-------------------------Borrow(7 arg)-----------------------------------
//Precondition: Need to construct a borrow object
//Postcondition: Borrow object constructed
/*
Borrow(7 arg): This is a constructer which takes in what is necessary 
in order to construct a borrow object.
*/
Borrow::Borrow(int acc, int y, int d, char media, char movie, string t,
	string dir) {
	accountID = acc; //set the account id
	setReleaseYear(y); //set the release year
	setReleaseDay(d); //set the release month
	setMediaType(media); //set the media type
	setMovieType(movie); //set the movie type
	setTitle(t); //set the title
	setDirector(dir); //set the director
	setCommandType('B'); //set the command type
}

//-------------------------GetAccountID-----------------------------------
//Precondition: Need constructed borrow object with an accound ID
//Postcondition: int that represents account id returned
/*
GetAccountID: reurns the accountID for the account id stored in the command
*/

int Borrow::getAccountID() const {
	return accountID; //return the account id
}
//-------------------------SetAccountID-----------------------------------
//Precondition: Need a constructed borrow object
//Postcondition: AccountID in borrow object set
/*
SetAccountID: sets the accoundID in the object
*/
void Borrow::setAccountID(int acc) {
	if(acc > 0) accountID = acc; //set the accound id in the object
}
//-------------------------GetMediaType-----------------------------------
//Precondition: Need a constructed borrow object with a media type
//Postcondition: Media type returned
/*
GetMediaType: return the media type stored in the borrow object
*/
char Borrow::getMediaType() const {
	return mediaType; //return the mediatype
}
//-------------------------setMediaType-----------------------------------
//Precondition: Need a constructed borrow object
//Postcondition: Media type in the object is set 
/*
SetMediaType: sets the media type in the command object
*/
void  Borrow::setMediaType(char type) {
	if(type == 'D') mediaType = type; //set the media type
}
//-------------------------GetMovieType-----------------------------------
//Precondition: Need a constructed Borrow object with a movie type
//Postcondition: Movie Type returned
/*
GetMovieType: returns the type of the movie that is stored in the command
*/
char Borrow::getMovieType() const {
	return movieType; //return the movie type
}
//-------------------------SetMovieType-----------------------------------
//Precondition: Need a constructed Borrow object
//Postcondition: Movie type in borrow object is set
/*
SetMovieType: sets the movie type in the command object
*/
void Borrow::setMovieType(char type) {
	if(	type == 'c' || type == 'C' ||// check to see if the movie type is legal
		type == 'd' || type == 'D' ||
		type == 'f' || type == 'F') {
			movieType = type; //set the movie type
		}
}
//-------------------------GetTitle-----------------------------------
//Precondition: Need a constructed Borrow object with a title
//Postcondition: Movie title in borrow object is returned
/*
GetTitle: returns the title stored in the borrow object
*/
string Borrow::getTitle() const {
	return title; //return title
}
//-------------------------SetTitle-----------------------------------
//Precondition: Need a constructed Borrow objects
//Postcondition: Movie title is set
/*
SetTitle: sets the title in the command
*/
void Borrow::setTitle(string t) {
	title = t; //set the title
}
//-------------------------GetReleaseYear-----------------------------------
//Precondition: Need a constructed Borrow object with a year
//Postcondition: Release year is returned
/*
GetReleaseYear: returns the release year in the borrow object
*/
int Borrow::getReleaseYear() const {
	return year; //return the year
}
//-------------------------SetReleaseYear-----------------------------------
//Precondition: Need a constructed Borrow object
//Postcondition: Release year is set
/*
setReleaseYear: sets the release year in a the command object
*/
void Borrow::setReleaseYear(int y) {
	if(y > 1886) year = y; //set the year if its legal
}
//-------------------------GetReleaseDay-----------------------------------
//Precondition: Need a constructed command object with a day
//Postcondition: Release day returned
/*
GetReleaseDay: Returns the release day of an object
*/
int Borrow::getReleaseDay() const {
	return day; //return the release day
}
//-------------------------setReleaseDay-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: release day set
/*
SetReleaseDay: sets the release day in a command object
*/
void Borrow::setReleaseDay(int d) {
	if(d > 0 && d < 12) day = d; //set the day if it is legal
}
//-------------------------GetDirector----------------------------------
//Precondition: Need a constructed command obeject with a director
//Postcondition: Director returned
/*
GetDirector: Returns the director stored in the command object
*/
string Borrow::getDirector() const {
	return director; //return the director
}
//-------------------------SetDirector-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Director set
/*
SetDirector: sets the director in the command object
*/
void Borrow::setDirector(string dir) {
	director = dir; //set the director
} 
//-------------------------GetActorLast-----------------------------------
//Precondition: Need a constructed command object with an actor
//Postcondition: Returns the last name of the major actor
/*
GetActorLast: Returns the last name of the major actor
*/
string Borrow::getActorLast() const {
	return actorLast;
}
//-------------------------SetActorLast-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Actor last is set
/*
SetActorLast: Actor last name is set
*/
void Borrow::setActorLast(string last) {
	actorLast = last; //set the actors last name
}
//-------------------------GetActorFirst-----------------------------------
//Precondition: Need a constructed command object with an actors first name
//Postcondition: actor first name returned
/*
GetActorFirst: Returns the first name of the actor.
*/
string Borrow::getActorFirst() const {
	return actorFirst; //return the actors first name
}
//-------------------------SetActorFirst-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Actors first name is set
/*
SetActorFirst: sets the first name of the actor in the command object
*/
void Borrow::setActorFirst(string first) {
	actorFirst = first; //set the first name of the actor
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
bool Borrow::setData(ifstream& infile) {
	//read into the account id and the media type
	infile >> accountID >> mediaType; 
	if (mediaType != 'D') { //check the media type 
		//say that its invalid
		cout << "Unknown media type: " << mediaType << endl; 
		return false; //return false; 
	}
	infile >> movieType; // otherwise read into the movietype 
	switch (movieType) { //switch on the movie type
	case 'F': //comedy
		getline(infile, title, ','); //read the title
		infile >> year; //read the year
		infile.ignore(1, '\n');
		break;
	case 'D': //drama
		getline(infile, director, ','); //read the director
		getline(infile, title, ','); //read the title
		infile.ignore(1, '\n');
		break;
	case 'C': //classic
		//read the day, year, last name, first name
		infile >> day >> year >> actorFirst >> actorLast;
		infile.ignore(1, '\n');
		break;
	default: //otherwie
		cout << "Unknown movie type: " << movieType << endl;
		string skip;
		getline(infile,  skip); //skip the line
		return false; //return false
	}
	commandType = 'B'; //set the command type
	return true; //return true;
}
//-------------------------GetString-----------------------------------
//Precondition: Need a constructred command object
//Postcondition: String returned with contents of command
/*
GetString: Returns a string that represents the contents of the command.
For use with history.
*/
string Borrow::getString() const {
	return "Borrowed " + getTitle() +"."; //return a string that is the command
}