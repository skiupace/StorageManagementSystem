#include <iostream>
#include "EmployeeClass.hpp"
#include "../print_class-imp/PrintClass.hpp"
#include "../app_variables_struct/VariablesStruct.hpp"
#include "../input_handler_class-imp/InputHandlerClass.hpp"

inline constexpr bool StorageEmployee::isEmpty() const noexcept {
	return array_size == 0;
}

void StorageEmployee::add_items_to_cart(const std::unique_ptr<StorageManager>& manager) {

	app_var.product_exist = false;
	PrintInfo::print_all_items(manager);

	if (!manager->isEmpty()) {
		std::cout << "Enter the product number or 0 to return -> ";
		std::cin >> app_var.product_number;

		if (app_var.product_number == 0)
			return;

		std::cout << "Enter the product quantity -> ";
		std::cin >> app_var.product_quantity;

		for (int i = app_var.product_number - 1; i < manager->array_size; ++i) {
			if (manager->products_numbers.at(i) == app_var.product_number)
				app_var.product_exist = true;
		}

		if (StorageManager::isExist(app_var.product_exist)) {
			picked_products_numbers.at(array_size) = manager->products_numbers.at(app_var.product_number - 1);
			picked_products_names.at(array_size) = manager->products_names.at(app_var.product_number - 1);
			picked_products_prices.at(array_size) = manager->products_prices.at(app_var.product_number - 1);
			picked_products_quantities.at(array_size) = app_var.product_quantity;
			array_size++;
		}
		
		if (manager->products_quantities.at(app_var.product_number - 1) > 0) {
			checkout_products_in_cart(manager, app_var.product_quantity, app_var.product_number);
			manager->products_quantities.at(app_var.product_number - 1) -= app_var.product_quantity;
		} else
			PrintInfo::print_error_msg();
	}
}

void StorageEmployee::create_invoick() const noexcept {

	std::cout << "--- Print Invoick Informations ---\n\n";

	if (isEmpty())
		std::cout << "Sorry but the cart is empty ...\n";

	else {
		for (int i = 0; i < array_size; i++) {
			std::cout << "Item No." << picked_products_numbers.at(i) << '\n';
			std::cout << "Item Name : " << picked_products_names.at(i) << '\n';
			std::cout << "Item Price : " << picked_products_prices.at(i) << '\n';
			std::cout << "Item Quantity : " << picked_products_quantities.at(i) << '\n';
			std::cout << std::string(35, '-') << '\n';
		}
	}
}

void StorageEmployee::remove_from_cart() {
	for (int i = 0; i < array_size; ++i) {
		picked_products_numbers.at(i) = 0;
		picked_products_names.at(i) = "";
		picked_products_prices.at(i) = 0.0f;
		picked_products_quantities.at(i) = 0;
	} array_size = 0;
}

void StorageEmployee::remove_from_cart(const int product_number) {
	for (int i = product_number - 1; i < array_size; ++i) {
		picked_products_numbers.at(i) = picked_products_numbers.at(i + 1);
		picked_products_names.at(i) = picked_products_names.at(i + 1);
		picked_products_prices.at(i) = picked_products_prices.at(i + 1);
		picked_products_quantities.at(i) = picked_products_quantities.at(i + 1);
	} array_size--;

	for (int i = 0; i < array_size; i++)
		picked_products_numbers.at(i) = i + 1;
	app_var.product_number--;
}

void StorageEmployee::checkout_products_in_cart(
	const std::unique_ptr<StorageManager>& manager = nullptr, 
	const short appVar_products_quantities = 0,
	const short appVar_product_number = 0
) {
	create_invoick();
	if (!isEmpty()) {
		PrintInfo::print_checkout_menu();
		InputHandler::input_and_error_handler(app_var.choice);

		switch (app_var.choice) {
		case 1:
			std::cout << "Are sure you want to make a payment? ";
			InputHandler::input_and_error_handler(app_var.conform);

			if (app_var.conform == 'y' || app_var.conform == 'Y') {
				// Maybe i'll add a payment methods menu here!
				std::cout << "The operation has been completed ...\n";
				remove_from_cart();
			}

			else {
				// It's fixed "I Guess"
				manager->products_quantities.at(appVar_product_number - 1) += appVar_products_quantities;
				std::cout << "The operation has been cancelled ...\n";
			} break;

		case 2:
			std::cout << "\nEnter the product number to remove from cart: ";
			InputHandler::input_and_error_handler(app_var.product_number);
			remove_from_cart(app_var.product_number);
			break;

		case 3:
			return;

		default:
			PrintInfo::print_error_msg();
		}
	}
}