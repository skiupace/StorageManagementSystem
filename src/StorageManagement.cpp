#include <iostream>
#include <string>
#include <array>
#include "../classes/signup-login_classes/signup_class-imp/SignupClass.hpp"
#include "../classes/signup-login_classes/login_class-imp/LoginClass.hpp"
#include "../interfaces/main_interfaces/manager_interface_class-imp/ManagerInterfaceClass.hpp"
#include "../interfaces/main_interfaces/employee_interface_class-imp/EmployeeInterfaceClass.hpp"
#include "../interfaces/signup-login_interfaces/manager_signup-login_class-imp/ManagerSignupLoginClass.hpp"
#include "../interfaces/signup-login_interfaces/employee_signup-login_class-imp/EmployeeSignupLoginClass.hpp"

int main(int argc, char** argv) {

	ManagerSignupLoginInterface manager;
	EmployeeSignupLoginInterface employee;

	do {
		PrintInfo::print_main_menu();
		InputHandler::input_and_error_handler(app_var.choice);

		switch (app_var.choice) {
		case 1:
			system("cls");
			manager.manager_signup_login_interface();
			break;

		case 2:
			system("cls");
			employee.employee_signup_login_interface();
			break;

		case 3:
			return EXIT_SUCCESS;

		default:
			PrintInfo::print_error_msg();
		}

		system("pause");
		system("cls");
	} while (app_var.choice != 3);

	std::cin.get();
	return EXIT_SUCCESS;
}