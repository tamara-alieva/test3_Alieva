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

