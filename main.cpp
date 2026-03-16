#include "PasswordManager.h"
#include <iostream>
#include <string>
using namespace std;

void printMenu() {
	cout << "--- PASSWORD MANAGER ---" << endl;
	cout << "1. Add website credentials" << endl;
	cout << "2. Add card credentials" << endl;
	cout << "3. Exit" << endl;
	cout << "Choose option: ";
}

void addWebsite(PasswordManager& manager) {
	WebsiteCredentials cred;
	cout << "- Enter site name: ";
	getline(cin, cred.siteName);
	cout << "- Enter login: ";
	getline(cin, cred.login);
	cout << "- Enter password: ";
	getline(cin, cred.password);
	manager.addWebsite(cred);
	cout << cred.siteName << " site credentials added!" << endl << endl;
}

void addCard(PasswordManager& manager) {
	CardCredentials cred;
	cout << "- Enter bank: ";
	getline(cin, cred.bank);
	cout << "- Enter number: ";
	getline(cin, cred.number);
	cout << "- Enter expiration date: ";
	getline(cin, cred.expirationDate);
	cout << "- Enter CVC code: ";
	getline(cin, cred.cvcCode);
	manager.addCard(cred);
	cout << cred.bank << " card credentials added!" << endl << endl;
}

int main() {
	PasswordManager manager;
	int option = 1;

	while (true) {
		printMenu();
		cin >> option; cin.get();
		switch (option) {
		case 1:
			addWebsite(manager);
			break;
		case 2:
			addCard(manager);
			break;
		case 3:
			cout << "Goodbye!" << endl;
			return 0;
		default:
			cout << "Invalid option. Try again!" << endl << endl;
		}
	}
	return 0;
}