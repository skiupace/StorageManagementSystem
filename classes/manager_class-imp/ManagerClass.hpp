#pragma once
#include "../storage_class_attributes/StorageClass.hpp"

class StorageManager : public StorageAttributes {
public:
	StorageManager() : array_size(0) {}
	void add_item_to_stock() noexcept;
	void update_existing_item() noexcept;
	void remove_item_from_stock() noexcept;
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