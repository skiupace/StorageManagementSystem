#include <array>
#include <iostream>
#include "../print_class-imp/PrintClass.hpp"
#include "../manager_class-imp/ManagerClass.hpp"

void PrintInfo::print_main_menu() {
    std::cout << "--- User Login Interface ---\n\n";
    std::cout << "1- Login as Manager\n";
    std::cout << "2- Login as Employee\n";
    std::cout << "3- Exit the program\n\n";
    std::cout << "Enter you choice here -> ";
}

void PrintInfo::print_search_menu() {
    std::cout << "--- Searching for Products Info ---\n\n";
    std::cout << "1- Search by Product Number\n";
    std::cout << "2- Search by Product Name\n";
    std::cout << "3- Search by Product Price\n";
    std::cout << "4- Search by Product Quantity\n";
    std::cout << "5- Return to the pervious menu\n\n";
    std::cout << "Enter you choice here -> ";
}

void PrintInfo::print_update_menu() {
    std::cout << "--- Updating Products Interface ---\n\n";
    std::cout << "1- Update Product Name\n";
    std::cout << "2- Update Product Price\n";
    std::cout << "3- Update Product Quantity\n";
    std::cout << "4- Return to the pervious menu\n\n";
    std::cout << "Enter you choice here -> ";
}

void PrintInfo::print_manager_menu() {
    std::cout << "--- Manager Interface ---\n\n";
    std::cout << "1- Add New Product\n";
    std::cout << "2- Search For Product\n";
    std::cout << "3- Update Product Info\n";
    std::cout << "4- Delete Product Info\n";
    std::cout << "5- Print Products Info\n";
    std::cout << "6- Return to Main Menu\n\n";
    std::cout << "Enter you choice here -> ";
}

void PrintInfo::print_employee_menu() {
    std::cout << "--- Employee Interface ---\n\n";
    std::cout << "1- Add Products to Cart\n";
    std::cout << "2- Search For Product\n";
    std::cout << "3- Checkout Products in Cart\n";
    std::cout << "4- Return to Main Menu\n\n";
    std::cout << "Enter you choice here -> ";
}

void PrintInfo::print_checkout_menu() {
    std::cout << "Choose an operation to perform:\n\n";
    std::cout << "1- Complete to checkout\n";
    std::cout << "2- Remove a product from cart\n";
    std::cout << "3- Return to the pervious menu\n\n";
    std::cout << "Enter your choice -> ";
}

void PrintInfo::print_signup_login_menu() {
    std::cout << "--- Signup/Login Interface ---\n\n";
    std::cout << "1- Login into exist account\n";
    std::cout << "2- Signup to new account\n";
    std::cout << "3- Return to Main Menu\n\n";
    std::cout << "Enter you choice here -> ";
}

void PrintInfo::print_error_msg() {
    std::cout << "Error: invalid input please try again later ...\n";
}

void PrintInfo::print_all_items(const std::unique_ptr<StorageManager>& manager_object) noexcept {

    std::cout << "--- Print Products Informations ---\n\n";

    if (manager_object->isEmpty())
        std::cout << "Sorry but the storage is empty ...\n";

    else {
        for (int i = 0; i < manager_object->array_size; i++) {
            std::cout << "Item No." << manager_object->products_numbers.at(i) << '\n';
            std::cout << "Item Name : " << manager_object->products_names.at(i) << '\n';
            std::cout << "Item Price : " << manager_object->products_prices.at(i) << '\n';
            std::cout << "Item Quantity : " << manager_object->products_quantities.at(i) << '\n';
            std::cout << std::string(35, '-') << '\n';
        }
    }
}