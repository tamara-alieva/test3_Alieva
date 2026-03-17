#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PasswordManager.h"
#include <vector>
using namespace std;

TEST_CASE("PasswordManager creation test") {
	PasswordManager manager;
	REQUIRE(true);
}

TEST_CASE("Add Yandex website credentials test") {
	PasswordManager manager;
	WebsiteCredentials siteData{ "Yandex", "user@yandex.ru", "password123" };
	manager.addWebsite(siteData);
	REQUIRE(manager.websites["Yandex"].siteName == "Yandex");
	REQUIRE(manager.websites["Yandex"].login == "user@yandex.ru");
	REQUIRE(manager.websites["Yandex"].password == "password123");
}

TEST_CASE("Add Google website credentials test") {
	PasswordManager manager;
	WebsiteCredentials siteData{ "Google", "user@gmail.com", "123456" };
	manager.addWebsite(siteData);
	REQUIRE(manager.websites["Google"].siteName == "Google");
	REQUIRE(manager.websites["Google"].login == "user@gmail.com");
	REQUIRE(manager.websites["Google"].password == "123456");
}

TEST_CASE("Add Sberbank card credentials test") {
	PasswordManager manager;
	CardCredentials cardData{ "Sberbank", "1234 5678 9012 3456", "08/28", "123"};
	manager.addCard(cardData);
	REQUIRE(manager.cards["Sberbank"].bank == "Sberbank");
	REQUIRE(manager.cards["Sberbank"].number == "1234 5678 9012 3456");
	REQUIRE(manager.cards["Sberbank"].expirationDate == "08/28");
	REQUIRE(manager.cards["Sberbank"].cvcCode == "123");
}

TEST_CASE("Add VTB card credentials test") {
	PasswordManager manager;
	CardCredentials cardData{ "VTB", "9876 5432 1098 7654", "10/29", "456" };
	manager.addCard(cardData);
	REQUIRE(manager.cards["VTB"].bank == "VTB");
	REQUIRE(manager.cards["VTB"].number == "9876 5432 1098 7654");
	REQUIRE(manager.cards["VTB"].expirationDate == "10/29");
	REQUIRE(manager.cards["VTB"].cvcCode == "456");
}

TEST_CASE("Get all credentials test") {
	PasswordManager manager;
	WebsiteCredentials siteData1{ "Yandex", "user@yandex.ru", "password123" };
	WebsiteCredentials siteData2{ "Google", "user@gmail.com", "123456" };
	CardCredentials cardData1{ "Sberbank", "1234 5678 9012 3456", "08/28", "123" };
	CardCredentials cardData2{ "VTB", "9876 5432 1098 7654", "10/29", "456" };
	manager.addWebsite(siteData1);
	manager.addWebsite(siteData2);
	manager.addCard(cardData1);
	manager.addCard(cardData1);
	vector<UnifiedCredentials> result = manager.getAllCredentials();
	REQUIRE(result.size() == 4);
	bool foundYandex = false,
		foundGoogle = false,
		foundSberbank = false,
		foundVTB = false;
	for (int i = 0; i < result.size(); i++) {
		if (result[i].type == CredType::WEBSITE && result[i].website.siteName == "Yandex")
			foundYandex = true;
		if (result[i].type == CredType::WEBSITE && result[i].website.siteName == "Google")
			foundGoogle = true;
		if (result[i].type == CredType::CARD && result[i].card.bank == "Sberbank")
			foundSberbank = true;
		if (result[i].type == CredType::CARD && result[i].card.bank == "VTB")
			foundVTB = true;
	}
	REQUIRE(foundYandex);
	REQUIRE(foundGoogle);
	REQUIRE(foundSberbank);
	REQUIRE(foundVTB);
}