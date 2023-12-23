#include <iostream>
#include "SearchingClass.hpp"
#include "../print_class-imp/PrintClass.hpp"
#include "../app_variables_struct/VariablesStruct.hpp"
#include "../input_handler_class-imp/InputHandlerClass.hpp"

void SearchingForInfo::search_by_product_number(const std::unique_ptr<StorageManager>& manager_object) noexcept {

	app_var.product_exist = false;
	std::cout << "Enter the product number : ";
	InputHandler::input_and_error_handler(app_var.product_number);

	for (int i = 0; i < manager_object->array_size; ++i) {
		if (manager_object->products_numbers.at(i) == app_var.product_number) {
			std::cout << "\nItem No." << manager_object->products_numbers.at(i) << '\n';
			std::cout << "Item Name : " << manager_object->products_names.at(i) << '\n';
			std::cout << "Item Price : " << manager_object->products_prices.at(i) << '\n';
			std::cout << "Item Quantity : " << manager_object->products_quantities.at(i) << '\n';
			std::cout << std::string(35, '-') << '\n';
			app_var.product_exist = true;
		}
	}

	if (!StorageManager::isExist(app_var.product_exist))
		return;
}

void SearchingForInfo::search_by_product_name(const std::unique_ptr<StorageManager>& manager_object) noexcept {

	app_var.product_exist = false;
	std::cout << "Enter the product name : ";
	std::getline(std::cin >> std::ws, app_var.product_name);

	for (int i = 0; i < manager_object->array_size; ++i) {
		if (manager_object->products_names.at(i) == app_var.product_name) {
			std::cout << "\nItem No." << manager_object->products_numbers.at(i) << '\n';
			std::cout << "Item Name : " << manager_object->products_names.at(i) << '\n';
			std::cout << "Item Price : " << manager_object->products_prices.at(i) << '\n';
			std::cout << "Item Quantity : " << manager_object->products_quantities.at(i) << '\n';
			std::cout << std::string(35, '-') << '\n';
			app_var.product_exist = true;
		}
	}

	if (!StorageManager::isExist(app_var.product_exist))
		return;
}

void SearchingForInfo::search_by_product_price(const std::unique_ptr<StorageManager>& manager_object) noexcept {

	app_var.product_exist = false;
	std::cout << "Enter the product price : ";
	InputHandler::input_and_error_handler(app_var.product_price);

	for (int i = 0; i < manager_object->array_size; ++i) {
		if (manager_object->products_prices.at(i) == app_var.product_price) {
			std::cout << "\nItem No." << manager_object->products_numbers.at(i) << '\n';
			std::cout << "Item Name : " << manager_object->products_names.at(i) << '\n';
			std::cout << "Item Price : " << manager_object->products_prices.at(i) << '\n';
			std::cout << "Item Quantity : " << manager_object->products_quantities.at(i) << '\n';
			std::cout << std::string(35, '-') << '\n';
			app_var.product_exist = true;
		}
	}

	if (!StorageManager::isExist(app_var.product_exist))
		return;
}

void SearchingForInfo::search_by_product_quantity(const std::unique_ptr<StorageManager>& manager_object) noexcept {

	app_var.product_exist = false;
	std::cout << "Enter the product quantity : ";
	InputHandler::input_and_error_handler(app_var.product_quantity);

	for (int i = 0; i < manager_object->array_size; ++i) {
		if (manager_object->products_quantities.at(i) == app_var.product_quantity) {
			std::cout << "\nItem No." << manager_object->products_numbers.at(i) << '\n';
			std::cout << "Item Name : " << manager_object->products_names.at(i) << '\n';
			std::cout << "Item Price : " << manager_object->products_prices.at(i) << '\n';
			std::cout << "Item Quantity : " << manager_object->products_quantities.at(i) << '\n';
			std::cout << std::string(35, '-') << '\n';
			app_var.product_exist = true;
		}
	}

	if (!StorageManager::isExist(app_var.product_exist))
		return;
}

void SearchingForInfo::search_for_existing_item(const std::unique_ptr<StorageManager>& manager_object) noexcept {

	if (manager_object->isEmpty())
		std::cout << "Sorry but the storage is empty ...\n";

	else {
		app_var.choice = 0;

		do {
			PrintInfo::print_search_menu();
			InputHandler::input_and_error_handler(app_var.choice);

			switch (app_var.choice) {
			case 1:
				system("cls");
				search_by_product_number(manager_object);
				break;

			case 2:
				system("cls");
				search_by_product_name(manager_object);
				break;

			case 3:
				system("cls");
				search_by_product_price(manager_object);
				break;

			case 4:
				system("cls");
				search_by_product_quantity(manager_object);
				break;

			case 5:
				return;

			default:
				PrintInfo::print_error_msg();
			}

			system("pause");
			system("cls");
		} while (app_var.choice != 3);
	}
}