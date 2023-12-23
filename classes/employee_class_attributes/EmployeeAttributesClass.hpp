#pragma once
#include <array>
#include <string>

class EmployeeAttributes {
protected:
	std::array<short, 100> picked_products_numbers = {0};
	std::array<std::string, 100> picked_products_names = {""};
	std::array<float, 100> picked_products_prices = {0.0f};
	std::array<short, 100> picked_products_quantities = {0};
};