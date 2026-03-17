#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;

enum class  CredType {
	WEBSITE,
	CARD
};

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

struct UnifiedCredentials {
	CredType type;
	WebsiteCredentials website;
	CardCredentials card;
};

class PasswordManager {
public:
	map<string, WebsiteCredentials> websites;
	map<string, CardCredentials> cards;
	PasswordManager();
	void addWebsite(WebsiteCredentials siteData);
	void addCard(CardCredentials cardData);
	vector<UnifiedCredentials> getAllCredentials();
	vector<UnifiedCredentials> searchCredentials(string query);
};

