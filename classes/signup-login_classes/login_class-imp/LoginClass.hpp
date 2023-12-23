#pragma once
#include "../signup_class-imp/SignupClass.hpp"

class Login {
public:
	Login();
	Login(std::string, int);
	bool is_account_exist(const Signup&) noexcept;
	void set_account_info(std::string, int) noexcept;

private:
	std::string username;
	int password;
};