#include "PasswordManager.h"
#include <iostream>
#include <string>
using namespace std;

void printMenu() {
	cout << "--- PASSWORD MANAGER ---" << endl;
	cout << "1. Add website credentials" << endl;
	cout << "2. Add card credentials" << endl;
	cout << "3. Show all credentials" << endl;
	cout << "4. Search credentials" << endl;
	cout << "5. Exit" << endl;
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

void showAllCredentials(PasswordManager manager) {
	vector<UnifiedCredentials> credentials = manager.getAllCredentials();
	if (credentials.empty())
		cout << "No credentials found!" << endl << endl;
	else {
		cout << "--- ALL CREDENTIALS ---" << endl;
		for (int i = 0; i < credentials.size(); i++) {
			if (credentials[i].type == CredType::WEBSITE) {
				cout << "- Website " << credentials[i].website.siteName << endl
					<< "\tLogin: " << credentials[i].website.login << endl
					<< "\tPassword: " << credentials[i].website.password << endl << endl;
			}
			else if (credentials[i].type == CredType::CARD) {
				cout << "- Card " << credentials[i].card.bank << endl
					<< "\tNumber: " << credentials[i].card.number << endl
					<< "\tExpiration date: " << credentials[i].card.expirationDate << endl
					<< "\tCVC code: " << credentials[i].card.cvcCode << endl << endl;
			}
		}
	}
}

void searchCredentials(PasswordManager manager) {
	string query;
	cout << "- Enter search query: "; getline(cin, query);
	vector<UnifiedCredentials> credentials = manager.searchCredentials(query);
	if (credentials.empty())
		cout << "No credentials found for query \"" << query << "\"!" << endl << endl;
	else {
		cout << "--- SEARCH RESULTS ---" << endl;
		for (int i = 0; i < credentials.size(); i++) {
			if (credentials[i].type == CredType::WEBSITE) {
				cout << "- Website " << credentials[i].website.siteName << endl
					<< "\tLogin: " << credentials[i].website.login << endl
					<< "\tPassword: " << credentials[i].website.password << endl << endl;
			}
			else if (credentials[i].type == CredType::CARD) {
				cout << "- Card " << credentials[i].card.bank << endl
					<< "\tNumber: " << credentials[i].card.number << endl
					<< "\tExpiration date: " << credentials[i].card.expirationDate << endl
					<< "\tCVC code: " << credentials[i].card.cvcCode << endl << endl;
			}
		}
	}
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
				showAllCredentials(manager);
				break;
			case 4:
				searchCredentials(manager);
				break;
			case 5:
				cout << "Goodbye!" << endl;
				return 0;
			default:
				cout << "Invalid option. Try again!" << endl << endl;
			}
		}
		return 0;
}