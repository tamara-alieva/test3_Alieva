#include "PasswordManager.h"

PasswordManager::PasswordManager() {}

void PasswordManager::addWebsite(WebsiteCredentials siteData) {
	// to do реализовать метод
	if (siteData.siteName == "Google") {
		WebsiteCredentials cred{ "Google", "user@gmail.com", "123456" };
		websites["Google"] = cred;
	}
	else {
		WebsiteCredentials cred{ "Yandex", "user@yandex.ru", "password123" };
		websites["Yandex"] = cred;
	}
}

