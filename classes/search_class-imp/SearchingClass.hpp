#pragma once
#include "../manager_class-imp/ManagerClass.hpp"

class SearchingForInfo {
public:
	static void search_by_product_number(const std::unique_ptr<StorageManager>&) noexcept;
	static void search_by_product_name(const std::unique_ptr<StorageManager>&) noexcept;
	static void search_by_product_price(const std::unique_ptr<StorageManager>&) noexcept;
	static void search_by_product_quantity(const std::unique_ptr<StorageManager>&) noexcept;
	static void search_for_existing_item(const std::unique_ptr<StorageManager>&) noexcept;
};