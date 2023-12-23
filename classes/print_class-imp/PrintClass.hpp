#pragma once
#include "../manager_class-imp/ManagerClass.hpp"

class PrintInfo {
public:
	static void print_main_menu();
	static void print_search_menu();
	static void print_update_menu();
	static void print_manager_menu();
	static void print_employee_menu();
	static void print_checkout_menu();
	static void print_signup_login_menu();

	static void print_error_msg();
	static void print_all_items(const std::unique_ptr<StorageManager>&) noexcept;
};