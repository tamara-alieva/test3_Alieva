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

/**
 * Add card credentials
 *
 * @param cardData the card credentials
 */
void PasswordManager::addCard(CardCredentials cardData) {
	// to do full method implementation
	if (cardData.bank == "VTB") {
		CardCredentials cred{ "VTB", "9876 5432 1098 7654", "10/29", "456" };
		cards["VTB"] = cred;
	}
	else {
		CardCredentials cred{ "Sberbank", "1234 5678 9012 3456", "08/28", "123" };
		cards["Sberbank"] = cred;
	}
}

/**
 * Get all credential entries
 *
 * @return vector of unified website and card credentials
 */
vector<UnifiedCredentials> PasswordManager::getAllCredentials() {
	// to do full method implementation
	vector<UnifiedCredentials> result;

	WebsiteCredentials siteYandex{ "Yandex", "user@yandex.ru", "password123" };
	WebsiteCredentials siteGoogle{ "Google", "user@gmail.com", "123456" };
	CardCredentials cardSber{ "Sberbank", "1234 5678 9012 3456", "08/28", "123" };
	CardCredentials cardVTB{ "VTB", "9876 5432 1098 7654", "10/29", "456" };

	UnifiedCredentials credYandex; credYandex.type = CredType::WEBSITE; credYandex.website = siteYandex;
	UnifiedCredentials credGoogle; credGoogle.type = CredType::WEBSITE; credGoogle.website = siteGoogle;
	UnifiedCredentials credSber; credSber.type = CredType::CARD; credSber.card = cardSber;
	UnifiedCredentials credVTB; credVTB.type = CredType::CARD; credVTB.card = cardVTB;

	result.push_back(credYandex);
	result.push_back(credGoogle);
	result.push_back(credSber);
	result.push_back(credVTB);

	return result;
}

/**
 * Find credential entries by substring
 *
 * @param query the substring for searching
 *
 * @return vector of found website and card credentials
 */
vector<UnifiedCredentials> PasswordManager::searchCredentials(string query) {
	// to do full method implementation
	vector<UnifiedCredentials> result;
	WebsiteCredentials siteYandex{ "Yandex", "user@yandex.ru", "password123" };
	WebsiteCredentials siteApex{ "Oracle Apex", "username@gmail.com", "123654" };

	result.push_back(UnifiedCredentials{ CredType::WEBSITE, siteYandex });
	result.push_back(UnifiedCredentials{ CredType::WEBSITE, siteApex });

	return result;
}