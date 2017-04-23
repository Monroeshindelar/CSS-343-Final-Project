#include "store.h"

// ------------------------ Store ---------------------------------------
// Default constructor for store
Store::Store() {
	comedies = new BSTree();
	dramas = new BSTree();
	classics = new BSTree();
	customers = new HashTable(103);
	numCustomers = 0;
	numCommands = 0;
}

// ------------------------ ~Store ---------------------------------------
// destructor
Store::~Store() {}

// ------------------------ initializeCustomers -----------------------------
// puts all customers into hash table
void Store::initializeCustomers(ifstream& infile) {
	int acc = 0;
	string last = "";
	string first = "";
	//while customers exist
	while (infile >> acc >> last >> first) {
		//create new customer
		Customer* current = new Customer(acc, last, first);
		//insert into hashtable
		customers->insert(current);
		numCustomers++;
	}
}

// ------------------------ initializeCommands ----------------------------
// put all commands into command queue
void Store::initializeCommands(ifstream& infile) {
	CommandFac factory;
	char type;
	infile >> type;
	while (!infile.eof()) {
		//call command factory
		Command* currentCommand = factory.createCommand(type);
		//if incorrect command skip line
		if (currentCommand == NULL) {
			string skip;
			getline(infile, skip);
		}
		else {
			if (!currentCommand->setData(infile)) {
				//if setData retuns null then drop command
				cout << "Invalid Command" << endl;
				delete currentCommand;
				currentCommand = NULL;
			}
			else
				//add to queue
				commands.push(currentCommand);
		}
		if (!infile.eof()) infile >> type;
	}
}

// ------------------------ initializeMovies ----------------------------
// put movies into their bsTrees
void Store::initializeMovies(ifstream& infile) {
	MovieFac factory;
	string type;
	getline(infile, type, ',');
	while (!infile.eof()) {
		//create Movie
		Movie* currentMovie = factory.createMovie(type.at(0));
		//skip if current Movie is a null
		if (currentMovie == NULL) {
			string skip;
			getline(infile, skip);
		}
		else {
			currentMovie->setData(infile);
			//insert into BSTree based on genre
			switch (type.at(0)) {
			case 'F':
				comedies->insert(currentMovie);
				break;
			case 'D':
				dramas->insert(currentMovie);
				break;
			case 'C':
				classics->insert(currentMovie);
				break;
			default:
				break;
			}
		}
		if (!infile.eof()) getline(infile, type, ',');
	}
}

// ------------------------ processTransactions ----------------------------
// execute all commands
void Store::processTransactions() {
	Command* current = commands.front();

	while (!commands.empty()) {
		current = commands.front();
		Customer* theCustomer;
		History* h;
		Borrow* b;
		Return* r;
		Movie* newMovie;
		Movie* tempMovie;
		//check for command type
		switch (current->getCommandType()) {
		case 'I':
			//display all BSTrees
			comedies->display();
			dramas->display();
			classics->display();
			break;
		case 'H':
			//DisplayCustomerHistory
			customers->getItemByKey(current->getAccountID(), theCustomer);
			theCustomer->displayHistory();
			break;
		case 'B':
			customers->getItemByKey(current->getAccountID(), theCustomer);
			switch (current->getMovieType()) {
			case 'C':
				newMovie = new Classic(current->getMediaType(), 0, 
					current->getReleaseYear(), current->getDirector(), 
					current->getTitle(), current->getActorFirst(), 
					current->getActorLast(), current->getReleaseDay());
				tempMovie = new Classic();
				classics->retrieve(newMovie, *&tempMovie);
				if (tempMovie->getStock() <= 0) {
					cout << "There are no classic movies avaliable" << endl;
				}
				else {
					tempMovie->setStock(tempMovie->getStock() - 1);
					theCustomer->insertHistory("Borrowed " + 
						tempMovie->getTitle() + ".");
				}
				delete newMovie;
				newMovie = NULL;
				break;
			case 'D':
				newMovie = new Drama(current->getMediaType(), 0, 
					current->getReleaseYear(), current->getDirector(),
					current->getTitle());
				tempMovie = new Drama();
				dramas->retrieve(newMovie, *&tempMovie);
				if (tempMovie->getStock() <= 0)
				{
					cout << "There are no drama movies avaliable" << endl;
				}
				else {
					tempMovie->setStock(tempMovie->getStock() - 1);
					theCustomer->insertHistory("Borrowed " + 
						tempMovie->getTitle() + ".");
				}
				delete newMovie;
				newMovie = NULL;
				break;
			case 'F':
				newMovie = new Comedy(current->getMediaType(), 0, 
					current->getReleaseYear(), current->getDirector(), 
					current->getTitle());
				tempMovie = new Comedy();
				comedies->retrieve(newMovie, *&tempMovie);
				if (tempMovie->getStock() <= 0) {
					cout << "There are no comedy movies avaliable"<< endl;
				}
				else {
					tempMovie->setStock(tempMovie->getStock() - 1);
					theCustomer->insertHistory("Borrowed " + 
						tempMovie->getTitle() + ".");
				}
				delete newMovie;
				newMovie = NULL;
				break;
			default:
				cout << "Invalid Movie Type" << endl;
			}
			break;
		case 'R':
			customers->getItemByKey(current->getAccountID(), theCustomer);

			switch (current->getMovieType()) {
			case 'C':
				newMovie = new Classic(current->getMediaType(), 0, 
					current->getReleaseYear(), current->getDirector(), 
					current->getTitle(), current->getActorFirst(), 
					current->getActorLast(), current->getReleaseDay());
				tempMovie = new Classic();
				classics->retrieve(newMovie, *&tempMovie);
				theCustomer->insertHistory("Returned " + tempMovie->getTitle() 
					+ ".");
				tempMovie->setStock(tempMovie->getStock() + 1);
				delete newMovie;
				newMovie = NULL;
				break;
			case 'D':
				newMovie = new Drama(current->getMediaType(), 0, 
					current->getReleaseYear(), current->getDirector(), 
					current->getTitle());
				tempMovie = new Drama();
				dramas->retrieve(newMovie, *&tempMovie);
				theCustomer->insertHistory("Returned " + tempMovie->getTitle()
					+ ".");
				tempMovie->setStock(tempMovie->getStock() + 1);
				delete newMovie;
				newMovie = NULL;
				break;
			case 'F':
				newMovie = new Comedy(current->getMediaType(), 0, 
					current->getReleaseYear(), current->getDirector(), 
					current->getTitle());
				tempMovie = new Comedy();
				comedies->retrieve(newMovie, *&tempMovie);
				theCustomer->insertHistory("Returned " + tempMovie->getTitle()
					+ ".");
				tempMovie->setStock(tempMovie->getStock() + 1);
				delete newMovie;
				newMovie = NULL;
				break;
				

			default:
				cout << "Invalid Movie Type" << endl;
			}

			break;
		default:
			cout << "Entered invalid command" << endl;
			break;
		}
		delete current;
		current = NULL;
		commands.pop();
	}
}

int Store::run() {
	ifstream infile1("data4customers.txt");
	if (!infile1) {
		cout << "File could not be opened" << endl;
		return 1;
	}
	initializeCustomers(infile1);
	infile1.close();
	ifstream infile2("data4movies.txt");
	if (!infile2) {
		cout << "File could not be opened" << endl;
		return 1;
	}
	initializeMovies(infile2);
	infile2.close();
	ifstream infile3("data4commands.txt");
	if (!infile3) {
		cout << "File could not be opened" << endl;
		return 1;
	}
	initializeCommands(infile3);
	infile3.close();
	processTransactions();

}