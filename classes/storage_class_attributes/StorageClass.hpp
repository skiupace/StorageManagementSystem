#pragma once
#include <array>
#include <string>

class StorageAttributes {
protected:
	std::array<short, 100> products_numbers = {0};
	std::array<std::string, 100> products_names = {""};
	std::array<float, 100> products_prices = {0.0f};
	std::array<short, 100> products_quantities = {0};
};