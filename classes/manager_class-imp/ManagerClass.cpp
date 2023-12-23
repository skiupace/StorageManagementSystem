#include <iostream>
#include "../print_class-imp/PrintClass.hpp"
#include "../manager_class-imp/ManagerClass.hpp"
#include "../app_variables_struct/VariablesStruct.hpp"
#include "../input_handler_class-imp/InputHandlerClass.hpp"

inline constexpr bool StorageManager::isEmpty() const noexcept {
	return array_size == 0;
}

inline constexpr bool StorageManager::isFull() const noexcept {
	return array_size == 99;
}

constexpr bool StorageManager::isExist(bool product_exist) noexcept {
	if (!product_exist) {
		std::cout << "The value isn't valid, please try again ...\n";
		return false;
	} else
		return true;
}

void StorageManager::add_item_to_stock() {

	if (isFull())
		std::cout << "Sorry but the storage is full ...\n";

	else {
		std::cout << "Enter the product name : ";
		std::getline(std::cin >> std::ws, app_var.product_name);

		std::cout << "Enter the product price : ";
		InputHandler::input_and_error_handler(app_var.product_price);

		std::cout << "Enter the product quantity : ";
		InputHandler::input_and_error_handler(app_var.product_quantity);

		products_numbers[array_size] = ++app_var.product_number;
		products_names[array_size] = app_var.product_name;
		products_prices[array_size] = app_var.product_price;
		products_quantities[array_size] = app_var.product_quantity;
		array_size++;
	}
}

void StorageManager::update_existing_item() {
	
	if (isEmpty())
		std::cout << "Sorry but the storage is empty ...\n";

	else {
		app_var.product_exist = false;
		std::cout << "Enter the product number : ";
		InputHandler::input_and_error_handler(app_var.product_number);

		for (int i = 0; i < products_numbers.size(); ++i) {
			if (products_numbers.at(i) == app_var.product_number)
				app_var.product_exist = true;
		}
		
		if (!StorageManager::isExist(app_var.product_exist))
			return;

		do {
			system("cls");
			PrintInfo::print_update_menu();
			InputHandler::input_and_error_handler(app_var.choice);

			switch (app_var.choice) {
			case 1:
				system("cls");
				std::cout << "Enter the updated name : ";
				std::getline(std::cin >> std::ws, app_var.product_name);
				products_names[app_var.product_number - 1] = app_var.product_name;
				break;

			case 2:
				system("cls");
				std::cout << "Enter the updated price : ";
				InputHandler::input_and_error_handler(app_var.product_price);
				products_prices[app_var.product_number - 1] = app_var.product_price;
				break;

			case 3:
				system("cls");
				std::cout << "Enter the updated quantity : ";
				InputHandler::input_and_error_handler(app_var.product_quantity);
				products_quantities[app_var.product_number - 1] = app_var.product_quantity;
				break;

			case 4:
				return;

			default:
				PrintInfo::print_error_msg();
			}

			system("pause");
			system("cls");
		} while (app_var.choice != 3);
	}
}

void StorageManager::remove_item_from_stock() {

	std::cout << "--- Remove Products Informations ---\n\n";
	std::cout << "Enter the product number : ";
	InputHandler::input_and_error_handler(app_var.product_number);

	for (int i = 0; i < products_numbers.size(); ++i) {
		if (products_numbers.at(i) == app_var.product_number)
			app_var.product_exist = true;
	}

	if (!StorageManager::isExist(app_var.product_exist))
		return;

	for (int i = app_var.product_number - 1; i < array_size; ++i) {
		products_numbers.at(i) = products_numbers.at(i + 1);
		products_names.at(i) = products_names.at(i + 1);
		products_prices.at(i) = products_prices.at(i + 1);
		products_quantities.at(i) = products_quantities.at(i + 1);
	} array_size--;

	for (int i = 0; i < array_size; ++i)
		products_numbers.at(i) = i + 1;
}