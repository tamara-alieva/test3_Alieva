#pragma once
#include <map>
#include <string>
using namespace std;

struct WebsiteCredentials {
	string siteName;
	string login;
	string password;
};

class PasswordManager {
public:
	map<string, WebsiteCredentials> websites;
	PasswordManager();
	void addWebsite(WebsiteCredentials siteData);
};

