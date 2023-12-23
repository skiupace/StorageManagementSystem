#pragma once

class EmployeeSignupLoginInterface {
public:
	void employee_signup_login_interface() {
		do {
			PrintInfo::print_signup_login_menu();
			InputHandler::input_and_error_handler(app_var.choice);

			switch (app_var.choice) {
			case 1:
				system("cls");
				std::cout << "Enter your username: ";
				std::cin >> username;

				std::cout << "Enter your password: ";
				std::cin >> password;

				access_account.set_account_info(username, password);
				if (access_account.is_account_exist(create_account)) {
					system("cls");
					employee.employee_interface();
				} break;

			case 2:
				system("cls");
				std::cout << "Enter a new username: ";
				std::cin >> username;

				std::cout << "Enter a new password: ";
				std::cin >> password;

				system("cls");
				create_account.set_account_info(username, password);
				employee.employee_interface();
				break;

			case 3:
				app_var.choice = 0;
				return;

			default:
				PrintInfo::print_error_msg();
			}

			system("pause");
			system("cls");
		} while (app_var.choice != 3);
	}

private:
	std::string username;
	int password;

private:
	Signup create_account;
	Login access_account;
	EmployeeInterface employee;
};