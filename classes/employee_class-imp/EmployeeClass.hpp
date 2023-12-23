#pragma once
#include "../manager_class-imp/ManagerClass.hpp"
#include "../employee_class_attributes/EmployeeAttributesClass.hpp"

class StorageEmployee : public EmployeeAttributes {
public:
	StorageEmployee() : array_size(0) {}
	void add_items_to_cart(const std::unique_ptr<StorageManager>&) noexcept;
	void checkout_products_in_cart() noexcept;
	// static void send_sales_report_to_manager();

private:
	inline constexpr bool isEmpty() const noexcept;
	void create_invoick() const noexcept;
	void remove_from_cart() noexcept;
	void remove_from_cart(const int) noexcept;
	// --------------------------------------------
	short array_size;
};