#include "customer.h"

// ------------------------ Customer ----------------------------
//constructor
Customer::Customer(int acc, string last, string first) {
	setAccountNum(acc);
	setFirstName(first);
	setLastName(last);
	commandHistory = new Command[100];
	commandHistoryIndex = 0;
	commandHistoryArrayLength = 0;
}

// ------------------------ Customer ----------------------------
// default constructor
Customer::Customer()
{
	setAccountNum(0);
}

// ------------------------ destructor ----------------------------
// 
Customer::~Customer() {
	delete[] commandHistory;

	commandHistory = NULL;
}

// ------------------------ getAccountNum ----------------------------
// returns account number
int Customer::getAccountNum() const {
	return accountNum;
}

// ------------------------ setAccountNum ----------------------------
// set account number
void Customer::setAccountNum(int acc) {
	if(acc > 0 && acc < 10000) {
		accountNum = acc;
	}
}

// ------------------------ getFirstName ----------------------------
// return first name
string Customer::getFirstName() const {
		return firstName;
}

// ------------------------ setFirstName ----------------------------
// set first name
void Customer::setFirstName(string first) {
	firstName = first;
}

// ------------------------ getLastName ----------------------------
// returns last name
string Customer::getLastName() const {
	return lastName;
}

// ------------------------ setLastName ----------------------------
// set last name
void Customer::setLastName(string last) {
	lastName = last;
}

// ------------------------ addCommandHistoryElement -------------------------
//
void Customer::addCommandHistoryElement(Command* in) {
	commandHistory[commandHistoryIndex++] = *in;
}

// ------------------------ displayHistory ----------------------------
// display history of customer
void Customer::displayHistory() {

	queue<string> queue;
	string temp;

	cout << endl;

	//print a heading line
	cout << firstName << " " << lastName << "'s borrowing"
		" history:" << endl;

	//if there's things to print, aka the Customer has performed transactions
	if (!borrowingHistory.empty()) {

		//while there's transactions to print
		while (!borrowingHistory.empty()) {

			//pop the transaction
			temp = borrowingHistory.top();
			borrowingHistory.pop();

			//print the transaction
			cout << " * " << temp << endl;

			//push it onto the queue
			queue.push(temp);
		}

		//once we've printed all the transactions, put them back in the queue
		while (!queue.empty()) {

			temp = queue.front();

			borrowingHistory.push(temp);
			queue.pop();
		}

		cout << endl;

	}
	else {

		//if the customer has nothing in their history, just print an "error"
		cout << " * " << firstName << " " << lastName
			<< " has not visited the store yet." << endl << endl;

	}
}

// ------------------------ insertHistory ----------------------------
// insert customer history
void Customer::insertHistory(string historyToInsert) {
	//push history string into history queue
	borrowingHistory.push(historyToInsert);
}