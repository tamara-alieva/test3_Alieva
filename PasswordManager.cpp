#include "PasswordManager.h"

PasswordManager::PasswordManager() {}

/**
 * Add website credentials
 * 
 * @param siteData the website credentials
 */
void PasswordManager::addWebsite(WebsiteCredentials siteData) {
	websites[siteData.siteName] = siteData;
}

/**
 * Add card credentials
 *
 * @param cardData the card credentials
 */
void PasswordManager::addCard(CardCredentials cardData) {
	cards[cardData.bank] = cardData;
}

/**
 * Get all credential entries
 *
 * @return vector of unified website and card credentials
 */
vector<UnifiedCredentials> PasswordManager::getAllCredentials() {
	vector<UnifiedCredentials> result;
	for (const auto& entry : websites)
		result.push_back(UnifiedCredentials{ CredType::WEBSITE, entry.second });
	for (const auto& entry : cards) {
		UnifiedCredentials cred; 
		cred.type = CredType::CARD;
		cred.card = entry.second;
		result.push_back(cred);
	}
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
	vector<UnifiedCredentials> result;
	for (const auto& entry : websites)
		if (entry.first.find(query) != string::npos)
			result.push_back(UnifiedCredentials{ CredType::WEBSITE, entry.second });
	for (const auto& entry : cards) {
		if (entry.first.find(query) != string::npos) {
			UnifiedCredentials cred;
			cred.type = CredType::CARD;
			cred.card = entry.second;
			result.push_back(cred);
		}
	}
	return result;
}