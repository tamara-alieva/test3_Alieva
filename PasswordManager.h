#pragma once
#include <map>
#include <string>
using namespace std;

struct WebsiteCredentials {
	string siteName;
	string login;
	string password;
};

struct CardCredentials {
	string bank;
	string number;
	string expirationDate;
	string cvcCode;
};

class PasswordManager {
public:
	map<string, WebsiteCredentials> websites;
	map<string, CardCredentials> cards;
	PasswordManager();
	void addWebsite(WebsiteCredentials siteData);
	void addCard(CardCredentials cardData);
};

