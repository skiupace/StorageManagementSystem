#pragma once

class Signup {
public:
	Signup();
	Signup(std::string, int);
	void set_account_info(std::string, int) noexcept;

private:
	friend class Login;
	std::string username;
	int password;
};