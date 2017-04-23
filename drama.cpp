#include "drama.h"
//-------------------------Movie-----------------------------------
//Precondition: nothing
//Postcondition: Movie initialized
/*
Drama: Just exists because there would be errors without it
*/
Drama::Drama(){}

Drama::Drama(char type) {
	setMovieType(type);
}
//-------------------------Drama(5 arg)-----------------------------------
//Precondition: Nothing
//Postcondition: Movie constructed
/*
Drama: Constructs a movie by using the constructors arguments to intitialize
instance variables
*/
Drama::Drama(char type, int stk, int release, string dir, string t) {
	movieType = type; //set the type
 	stock = stk; //set the stock
	releaseYear = release; //set the release year
	director = dir; //set the director
	title = t; //set the title
}

Drama::~Drama() {}
//-------------------------SetData-----------------------------------
//Precondition: Need an intialized movie object
//Postcondition: data in the movie object is set
/*
SetData: Takes in a file and uses that to set up the movie object.
First it reads into the stock, then it reads into director, then
the title, then the year, then uses that information to set 
instance level variables
*/
void Drama::setData(ifstream& infile) {
	string stStk = "stock placeholder"; //int to hold stock
	int stk = 0; //to hold stk
	int year = 0; //to hold year
	string dir = "director placeholder"; //to hold director
	string title = "title placeholder"; //to hold title 
	getline(infile, stStk, ','); //get the stock
	getline(infile, dir, ','); //get the director
	getline(infile, title, ','); //get the title
	infile >> year; //get the year

	stk = stoi(stStk); //stock to string
	setStock(stk); //set the stock
	setDirector(dir); //set the director
	setTitle(title); //set the title
	setReleaseYear(year); //set the release year
	infile.ignore(1,'\n');
}


bool Drama::operator==(const Movie& right) {
	//check to see if the direcor and the title are the same
	if (director == right.getDirector() && title == right.getTitle())
		return true; //return true
	else
		return false; //otherwise return false
}
//-------------------------Operator>-----------------------------------
//Precondition Need two movies
//Postcondion: movies compared
/*
Operator>: Compares to see if one movie is bigger than the other. First
checks to see if their directors are the same, then if they are it checks 
to see what the difference is between their titles.
*/
bool Drama::operator>(const Movie &toCompare) {
	//compare the directors
	if (getDirector() != toCompare.getDirector()) {
		return getDirector() > toCompare.getDirector();
 	} else { //if they are the same compare titles.
		return getTitle() > toCompare.getTitle();
	}
}
//-------------------------Operator<-----------------------------------
//Precondition Need two movies
//Postcondion: movies compared
/*
Operator>: Compares to see if one movie is bigger than the other. First
checks to see if their directors are the same, then if they are it checks 
to see what the difference is between their titles.
*/
bool Drama::operator<(const Movie &toCompare) {
	//compare the directors
	if (getDirector() != toCompare.getDirector()) {
		return getDirector() < toCompare.getDirector();
	} else { //compare the titles
		return getTitle() < toCompare.getTitle();
	}
}