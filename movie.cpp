#include "movie.h"
//-------------------------Movie(5 arg)-----------------------------------
//Precondition: Nothing
//Postcondition: Movie constructed
/*
Movie: Constructs a movie by using the constructors arguments to intitialize
instance variables
*/
Movie::Movie(char type, int stk, int release, string dir, string t) {
	setMovieType(type); //set movie type
	setStock(stk); //set the stock
	setReleaseYear(release); //set the release year
	setDirector(dir); //set the director
	setTitle(t); //set the title
	
}
//-------------------------Movie-----------------------------------
//Precondition: nothing
//Postcondition: Movie initialized
/*
Movie: Just exists because there would be errors without it
*/
Movie::Movie(){}
//-------------------------~Movie-----------------------------------
//Precondition: Need an initialized movie object
//Postcondition: movie object delted and memory managed
/*
~Movie: manages the memory of a movie object
*/
Movie::~Movie() {}
//-------------------------SetData-----------------------------------
//Precondition: Need an intialized movie object
//Postcondition: data in the movie object is set
/*
SetData: Takes in a file and uses that to set up the movie object.
First it reads into the stock, then it reads into director, then
the title, then the year, then uses that information to set 
instance level variables
*/
void Movie::setData(ifstream& infile) {
	int stk = 0; //int to hold stock
	int year = 0; //to hold year
	string dir = "director placeholder"; //hold the director
	string title = "title placeholder"; //hold the title 
	infile >> stk; //read into the stock
	infile.ignore(',');
	getline(infile, dir, ','); //read into the director
	getline(infile, title, ','); //read into the title
	infile >> year; //read into the year
	
	setStock(stk); //set the stock
	setDirector(dir); //set the director
	setTitle(title); //set the title
	setReleaseYear(year); //set the year
}
//-------------------------GetActor-----------------------------------
//Precondition: Need an intialized movie
//Postcondition: actor returned
/*
GetActor: Return the major actor in a classic movie
*/
string Movie::getActor() const {
	return string(); //override please
}
//-------------------------GetMovieType-----------------------------------
//Precondition: Need a constructed movie object with a movie type
//Postcondition: Movie Type returned
/*
GetMovieType: returns the type of the movie that is stored in the command
*/
char Movie::getMovieType() const {
	return movieType; //return the movie object
}
//-------------------------SetMovieType-----------------------------------
//Precondition: Need a constructed movie object
//Postcondition: Movie type in movie object is set
/*
SetMovieType: sets the movie type in the movie object
*/
void Movie::setMovieType(char type) {
	if(	type == 'c' || type == 'C' || //check if legal
		type == 'd' || type == 'D' ||
		type == 'f' || type == 'F') {
			movieType = type; //set the movie type
		} 
}
//-------------------------GetStock-----------------------------------
//Preconditon: need a constructed movie object
//Postcondition: stock of movie returned
/*
GetStock: returns the stock of the movie
*/
int Movie::getStock() const {
	return stock; //return sthe stock of the movie
}
//-------------------------SetStock-----------------------------------
//Preconditon: need a constructed movie object
//Postcondition: stock of movie set
/*
SetStock: sets the stock of a movie object
*/
void Movie::setStock(int stk) {
	if(stk > 0) stock = stk; //if legal, set the stock
}
//-------------------------GetReleaseYear-----------------------------------
//Precondition: Need a constructed movie object with a year
//Postcondition: Release year is returned
/*
GetReleaseYear: returns the release year in the borrow object
*/
int Movie::getReleaseYear() const {
	return releaseYear;
}
//-------------------------SetReleaseYear-----------------------------------
//Precondition: Need a constructed  object
//Postcondition: Release year is set
/*
setReleaseYear: sets the release year in a the movie object object
*/
void Movie::setReleaseYear(int year) {
	if(year > 1885) { // check if its legal
		releaseYear = year; //set the year
	}
}
//-------------------------GetDirector----------------------------------
//Precondition: Need a constructed movie obeject with a director
//Postcondition: Director returned
/*
GetDirector: Returns the director stored in the movie object
*/
string Movie::getDirector() const {
	return director; //return the director
}
//-------------------------SetDirector-----------------------------------
//Precondition: Need a constructed movie object
//Postcondition: Director set
/*
SetDirector: sets the director in the movie object
*/
void Movie::setDirector(string dir) {
	director = dir; //set the director
}
//-------------------------GetTitle-----------------------------------
//Precondition: Need a constructed movie object with a title
//Postcondition: Movie title in movie object is returned
/*
GetTitle: returns the title stored in the movie object
*/
string Movie::getTitle() const {
	return title; //return the title
}
//-------------------------SetTitle-----------------------------------
//Precondition: Need a constructed movie objects
//Postcondition: Movie title is set
/*
SetTitle: sets the title in the command
*/
void Movie::setTitle(string t) {
	title = t; //set the title
}

string Movie::getActorFirst() const {
	return " "; //please override
}

void Movie::setActorFirst() {
	
}
//-------------------------GetActorLast-----------------------------------
//Precondition: Need a constructed movie object with an actor
//Postcondition: Returns the last name of the major actor
/*
GetActorLast: Returns the last name of the major actor
*/
string Movie::getActorLast() const {
	return " "; //please override
}
//-------------------------SetActorLast-----------------------------------
//Precondition: Need a constructed movie object
//Postcondition: Actor last is set
/*
SetActorLast: Actor last name is set
*/
void Movie::setActorLast() {
	//please override 
}
//-------------------------GetReleaseDay-----------------------------------
//Precondition: Need a constructed movie object with a day
//Postcondition: Release day returned
/*
GetReleaseDay: Returns the release day of an object
*/
int Movie::getReleaseDay() const {
	return 0;//please override
}
//-------------------------setReleaseDay-----------------------------------
//Precondition: Need a constructed movie object
//Postcondition: release day set
/*
SetReleaseDay: sets the release day in a movie object
*/
void Movie::setReleaseDay() {
	//please override
}
//-------------------------Print-----------------------------------
//Precondition: need a constructed movie object
//Postcondition: prints the contents of the movie
/*
Print: prints the contents of the movie
*/
void Movie::print(ostream & a) const {
	a << getStock() << ", " << getDirector() << ", " << getTitle() << ", " <<
		getReleaseYear() << endl; //print the contents of the movie

}

ostream& operator<<(ostream &output, const Movie &a) {
	a.print(output);
	return output;                      
}

