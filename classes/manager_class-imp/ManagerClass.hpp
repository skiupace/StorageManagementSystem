#pragma once
#include "../storage_class_attributes/StorageClass.hpp"

class StorageManager : public StorageAttributes {
public:
	StorageManager() : array_size(0) {}
	void add_item_to_stock();
	void update_existing_item();
	void remove_item_from_stock();
	// ------------------------------------------
	static constexpr bool isExist(bool) noexcept;

private:
	inline constexpr bool isEmpty() const noexcept;
	inline constexpr bool isFull() const noexcept;

private:
	short array_size;
	friend class PrintInfo;
	friend class StorageEmployee;
	friend class SearchingForInfo;
};