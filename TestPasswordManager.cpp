#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PasswordManager.h"
using namespace std;

TEST_CASE("PasswordManager creation test") {
	PasswordManager manager;
	REQUIRE(true);
}

