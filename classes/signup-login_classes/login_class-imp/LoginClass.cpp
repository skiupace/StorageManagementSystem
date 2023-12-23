#include <iostream>
#include "LoginClass.hpp"

Login::Login() {
	username = "admin";
	password = 12345;
}

Login::Login(std::string username, int password) {
	this->username = username;
	this->password = password;
}

void Login::set_account_info(std::string username, int password) noexcept {
	this->username = username;
	this->password = password;
}

bool Login::is_account_exist(const Signup& signup) {

	int counter = 1;
	while (counter <= 3) {

		if (this->username == signup.username && this->password == signup.password)
			return true;

		else {
			system("cls");
			std::cout << "Wrong username or password try again ...\n\n";
			std::cout << "Re-Enter your username: ";
			std::cin >> this->username;

			std::cout << "Re-Enter your password: ";
			std::cin >> this->password;
			counter++;
		}
	}

	if (counter == 4)
		std::cout << "Sorry but you've reached your limit, try again later ...\n";
	return false;
}