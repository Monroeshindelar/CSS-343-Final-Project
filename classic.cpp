#include "classic.h"
//-------------------------Movie-----------------------------------
//Precondition: nothing
//Postcondition: Movie initialized
/*
Movie: Just exists because there would be errors without it
*/
Classic::Classic(){}
//-------------------------Classic(8 arg)-----------------------------------
//Precondition: Nothing
//Postcondition: Movie constructed
/*
Movie: Constructs a movie by using the constructors arguments to intitialize
instance variables
*/
Classic::Classic(char type, int stk, int release, string dir, string t, string
	first, string last, int day) {
	//Movie(type, stk, release, dir, t);
	movieType = type;
	stock = stk;
	releaseYear = release;
	director = dir;
	title = t;
	setActorFirst(first);
	setActorLast(last);
	setReleaseDay(day);
	setActor(first + " " + last);
}

Classic::Classic(char type) {
	setMovieType(type);
}
//-------------------------~Movie-----------------------------------
//Precondition: Need an initialized movie object
//Postcondition: movie object delted and memory managed
/*
~Movie: manages the memory of a movie object
*/
Classic::~Classic() {}
//-------------------------SetData-----------------------------------
//Precondition: Need an intialized movie object
//Postcondition: data in the movie object is set
/*
SetData: Takes in a file and uses that to set up the movie object.
First it reads into the stock, then it reads into director, then
the title, then the actor first name, then the actor last namethen the 
year, then uses that information to set  instance level variables.
*/
void Classic::setData(ifstream& infile) {
	string stStk = ""; //string to store stock
	int stk = 0; //int to store stock
	int day = 0; //to store day
	int year = 0; //to store year
	string dir = "director placeholder"; //to store director
	string title = "title placeholder"; //to store title
	string actorFirst = "Mark"; //to store the actor first
	string actorLast = "Belyak"; //to store the actor last
	getline(infile, stStk, ','); //get the stock in a string
	getline(infile, dir, ','); //set the director
	getline(infile, title, ','); //set the title
	//get the actor first, last, day and year
	infile >> actorFirst >> actorLast >> day >> year;
	infile.ignore(1, '\n');
	//make the major actor string
	setActor(actorFirst + " " + actorLast);
	stk = stoi(stStk); //change the string to an int
	setStock(stk); //set the stock
	setDirector(dir); //set the director
	setTitle(title); //set the title
	setActorFirst(actorFirst); //set the actor first name
	setActorLast(actorLast); //set the actor last name
	setReleaseDay(day); //set the release day
	setReleaseYear(year); //set the release year
}
//-------------------------GetActor-----------------------------------
//Precondition: Need an intialized movie
//Postcondition: actor returned
/*
GetActor: Return the major actor in a classic movie
*/
string Classic::getActor() const {
	return actor; //return the actor
}

void Classic::setActor(string af) {
	actor = af;
}
//-------------------------GetActorFirst-----------------------------------
//Precondition: Need a constructed movie object with an actor
//Postcondition: Returns the first name of the major actor
/*
GetActorLast: Returns the first name of the major actor
*/
string Classic::getActorFirst() const {
	return actorFirst; //get the actor first name
}
//-------------------------SetActorFirst-----------------------------------
//Precondition: Need a constructed movie object
//Postcondition: Actor first is set
/*
SetActorLast: Actor last name is set
*/
void Classic::setActorFirst(string af) {
	actorFirst = af; //set the actor first name
}
//-------------------------GetActorLast-----------------------------------
//Precondition: Need a constructed movie object with an actor
//Postcondition: Returns the last name of the major actor
/*
GetActorLast: Returns the last name of the major actor
*/
string Classic::getActorLast() const {
	return actorLast; //get the actor last name
}
//-------------------------SetActorLast-----------------------------------
//Precondition: Need a constructed command object
//Postcondition: Actor last is set
/*
SetActorLast: Actor last name is set
*/
void Classic::setActorLast(string al) {
	actorLast = al; //set the actor last name
}
//-------------------------GetReleaseDay-----------------------------------
//Precondition: Need a constructed movie object with a day
//Postcondition: Release day returned
/*
GetReleaseDay: Returns the release day of an object
*/
int Classic::getReleaseDay() const {
	return releaseDay; //get release day
}
//-------------------------setReleaseDay-----------------------------------
//Precondition: Need a constructed movie object
//Postcondition: release day set
/*
SetReleaseDay: sets the release day in a movie object
*/
void Classic::setReleaseDay(int rel) {
	if(rel > 0) {
		releaseDay = rel; //set the release day
	}
}
//-------------------------Print-----------------------------------
//Precondition: need a constructed movie object
//Postcondition: prints the contents of the movie
/*
Print: prints the contents of the movie
*/
void Classic::print(ostream & a) const
{
	//print the contents of the movie
	a << getStock() << ", " << getDirector() << ", " << getTitle() << ", " <<
		getActorFirst()<< ", " << getActorLast() << ", " << getReleaseDay() << 
		", "
		<< getReleaseYear() << endl;

}

ostream& operator<<(ostream &output, const Classic &a) {
	a.print(output);
	return output;
}
bool Classic::operator==(const Movie &toCompare) {

	return (getActor() == toCompare.getActor() &&
		getReleaseYear() == toCompare.getReleaseYear() &&
		getReleaseDay() == getReleaseDay());
}

bool Classic::operator>(const Movie &toCompare) {

	if (getReleaseYear() != toCompare.getReleaseYear()) {

		return getReleaseYear() > toCompare.getReleaseYear();

	}
	else {

		return getActor() > toCompare.getActor();

	}
}

bool Classic::operator<(const Movie &toCompare) {

	if (getReleaseYear() != toCompare.getReleaseYear()) {

		return getReleaseYear() < toCompare.getReleaseYear();

	}
	else {

		return getActor() < toCompare.getActor();

	}
}
