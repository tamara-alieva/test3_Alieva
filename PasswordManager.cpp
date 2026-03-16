#include "PasswordManager.h"

PasswordManager::PasswordManager() {}

void PasswordManager::addWebsite(WebsiteCredentials siteData) {
	// to do реализовать метод
	WebsiteCredentials cred{ "Yandex", "user@yandex.ru", "password123" };
	websites["Yandex"] = cred;
}

