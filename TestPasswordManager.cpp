#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PasswordManager.h"
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