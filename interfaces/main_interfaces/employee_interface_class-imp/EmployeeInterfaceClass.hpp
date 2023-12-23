#pragma once
#include "../../../classes/employee_class-imp/EmployeeClass.hpp"

class EmployeeInterface : public ManagerInterface {
public:
	void employee_interface() noexcept {
		do {
			PrintInfo::print_employee_menu();
			InputHandler::input_and_error_handler(app_var.choice);

			switch (app_var.choice) {
			case 1:
				system("cls");
				employee.add_items_to_cart(manager);
				break;

			case 2:
				system("cls");
				search.search_for_existing_item(manager);
				break;

			case 3:
				system("cls");
				employee.checkout_products_in_cart();
				break;

			case 4:
				return;

			default:
				PrintInfo::print_error_msg();
			}

			system("pause");
			system("cls");
		} while (app_var.choice != 4);
	}

private:
	StorageEmployee employee;
};