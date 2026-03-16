#include "PasswordManager.h"

PasswordManager::PasswordManager() {}

/**
 * Add website credentials
 * 
 * @param siteData the website credentials
 */
void PasswordManager::addWebsite(WebsiteCredentials siteData) {
	// to do full method implementation
	if (siteData.siteName == "Google") {
		WebsiteCredentials cred{ "Google", "user@gmail.com", "123456" };
		websites["Google"] = cred;
	}
	else {
		WebsiteCredentials cred{ "Yandex", "user@yandex.ru", "password123" };
		websites["Yandex"] = cred;
	}
}

void PasswordManager::addCard(CardCredentials cardData) {
	// to do full method implementation
	CardCredentials cred{ "Sberbank", "1234 5678 9012 3456", "08/28", "123" };
	cards["Sberbank"] = cred;
}