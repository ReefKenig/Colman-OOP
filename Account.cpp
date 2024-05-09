#include "Account.h"

// Default Constructor
Account::Account() :
	m_transactionList(nullptr),
	m_numberOfTransaction(0),
	m_persons(nullptr),
	m_totalPersons(0),
	m_accountNumber(0),
	m_balance(0.0) {}

// Constructor with array of Person pointers, count and inital balance
Account::Account(Person** persons, int count, double balance) :
	m_transactionList(nullptr),
	m_numberOfTransaction(0),
	m_totalPersons(count),
	m_balance(balance) {
	// TODO: set m_accountNumber
	SetPersons(persons, count);
}

// Constructor with a single Person reference and initial balance
Account::Account(const Person& person, double balance) : m_balance(balance) {
	Person* tempPersons = new Person[1];
	tempPersons[0] = person;
	SetPersons(&tempPersons, 1);
	int personId = person.GetId();
	int idDigits[9];
	for (int i = 8; i < 9; i += 2) {

	}
	delete[] tempPersons;
}

// Copy Constructor
Account::Account(const Account& other) {
	if (&other != this) {
		clearTransactions();
		clearPersons();
		
		this->m_balance = other.m_balance;
		this->m_numberOfTransaction = other.m_numberOfTransaction;
		this->m_totalPersons = other.m_totalPersons;
		this->m_accountNumber = other.m_accountNumber;

		this->m_transactionList = new Transaction * [this->m_numberOfTransaction];
		for (int i = 0; i < this->m_numberOfTransaction; i++) {
			this->m_transactionList[i] = new Transaction(*other.m_transactionList[i]);
		}

		this->m_persons = new Person * [this->m_totalPersons];
		for (int i = 0; i < this->m_totalPersons; i++) {
			this->m_persons[i] = new Person(*other.m_persons[i]);
		}
	}
}

// Destructor
Account::~Account() {
	clearTransactions();
	clearPersons();
}

// Set methods
void Account::SetPersons(Person** persons, int count) {
	clearPersons(); // Clear existing persons to avoid memory leaks
	m_persons = new Person*[count];
	for (int i = 0; i < count; i++) {
		m_persons[i] = new Person(*persons[i]); // Deep copy of each person
	}
	m_totalPersons = count;
}

void Account::SetAccountNumber(int number) { m_accountNumber = number; }

void Account::SetBalance(double balance) { m_balance = balance; }

void Account::SetTransactions(Transaction** newTransaction, int count) {
	clearTransactions(); // Clear existing transactions to avoid memory leaks
	m_transactionList = new Transaction*[count];
	for (int i = 0; i < count; i++) {
		m_transactionList[i] = new Transaction(*newTransaction[i]); // Deep copy of each transaction
	}
	m_numberOfTransaction = count;
}

// Get methods
Transaction** Account::GetTransactions() { return m_transactionList; }

int Account::GetNumOfTransactions() { return m_numberOfTransaction; }

Person** Account::GetPersons()const { return m_persons; }

int Account::GetTotalPersons()const { return m_totalPersons; }

int Account::GetAccountNumber()const { return m_accountNumber; }

double Account::GetBalance()const { return m_balance; }

void Account::Withdraw(double amount, const char* date) { // TODO
	m_balance -= amount;
	// Create new transaction record
}

void Account::Deposit(double amount, const char* date) {} // TODO

void Account::AddPerson(const Person& newPerson, double	amount) {
	Person** temp = new Person*[m_totalPersons + 1];
	for (int i = 0; i < m_totalPersons; i++) {
		temp[i] = m_persons[i];
	}
	temp[m_totalPersons] = new Person(newPerson);
	clearPersons();
	m_persons = temp;
	m_totalPersons++;
	m_balance += amount;
}

void Account::DeletePerson(const Person& oldPerson) {
}

void Account::AddTransaction(const Transaction& newTransaction) {}

void Account::clearPersons() {
	for (int i = 0; i < m_totalPersons; ++i) {
		delete m_persons[i];
	}
	delete[] m_persons;
}

void Account::clearTransactions() {
	for (int i = 0; i < m_numberOfTransaction; ++i) {
		delete m_transactionList[i];
	}
	delete[] m_transactionList;
}
