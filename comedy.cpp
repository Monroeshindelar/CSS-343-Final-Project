#include "comedy.h"

//-------------------------Comedy(1 arg)-----------------------------------
//Precondition: Nothing
//Postcondition: Movie constructed
/*
Comedy: Sets the command type
*/
Comedy::Comedy(char type){
	setMovieType(type);
}
//-------------------------Comedy----------------------------------
//Precondition: nothing
//Postcondition: Movie initialized
/*
Comedy: Just exists because there would be errors without it
*/
Comedy::Comedy(){}

//-------------------------Comedy(5 arg)-----------------------------------
//Precondition: Nothing
//Postcondition: Movie constructed
/*
Comedy: Constructs a movie by using the constructors arguments to intitialize
instance variables
*/
Comedy::Comedy(char type, int stk, int release, string dir, string t) {
	movieType = type; //set the type
	stock = stk; //set the stock
	releaseYear = release; //set the release year
	director = dir; //set the director
	title = t; //set the title
}

Comedy::~Comedy() {}

//-------------------------SetData-----------------------------------
//Precondition: Need an intialized movie object
//Postcondition: data in the movie object is set
/*
SetData: Takes in a file and uses that to set up the movie object.
First it reads into the stock, then it reads into director, then
the title, then the year, then uses that information to set 
instance level variables
*/
void Comedy::setData(ifstream& infile) {
	string stStk = "stock placeholder"; //string to hold stock
	int stk = 0; //int to hold stock
	int year = 0; //int to hold year
	string dir = "director placeholder"; //string to hold director
	string title = "title placeholder"; //string to hold title
	getline(infile, stStk, ','); //get the stock
	getline(infile, dir, ','); //get the director
	getline(infile, title, ','); //get the title
	infile >> year; //get the year

	stk = stoi(stStk); //get the stock 
	setStock(stk); //set the stock
	setDirector(dir); //set the director
	setTitle(title); //set the title
	setReleaseYear(year); //set the release year
	infile.ignore(1,'\n');
}
//-------------------------Operator==-----------------------------------
//Preconditon: Need two movies
//Postcondition: movies compared
/*
Equality Operator: Checks to see if two comedies are equal to eachother.
First checks to see if the titles are the same, then checks to see if
the release year is the same and if both of those are true we return true
otherwise we return fals. 
*/
bool Comedy::operator==(const Movie & right) {
	//check to see if the release year and the title are the same
	if (title == right.getTitle() && releaseYear == right.getReleaseYear())
		return true; //return true
	else
		return false; //return false
}
//-------------------------Operator>-----------------------------------
//Precondition Need two movies
//Postcondion: movies compared
/*
Operator>: Compares to see if one movie is bigger than the other. First
checks to see if their titles are the same, then if they are it checks 
to see what the difference is between their release years.
*/
bool Comedy::operator>(const Movie& toCompare) {
	if (getTitle() != toCompare.getTitle()) { //compare the titles
		return getTitle() > toCompare.getTitle();
	} else { //compare the release years
		return getReleaseYear() > toCompare.getReleaseYear();

	}
}
//-------------------------Operator>-----------------------------------
//Precondition Need two movies
//Postcondion: movies compared
/*
Operator>: Compares to see if one movie is bigger than the other. First
checks to see if their titles are the same, then if they are it checks 
to see what the difference is between their release years.
*/
bool Comedy::operator<(const Movie &toCompare) {
	//compare the titles
	if (getTitle() != toCompare.getTitle()) {
		return getTitle() < toCompare.getTitle();
	} else { //compare the release year
		return getReleaseYear() < toCompare.getReleaseYear();
	}
}