#include <iostream>
#include "SignupClass.hpp"

Signup::Signup() {
	username = "admin";
	password = 12345;
}

Signup::Signup(std::string username, int password) {
	this->username = username;
	this->password = password;
}

void Signup::set_account_info(std::string username, int password) noexcept {
	this->username = username;
	this->password = password;
}