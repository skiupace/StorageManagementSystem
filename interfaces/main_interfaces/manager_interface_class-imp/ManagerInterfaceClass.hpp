#pragma once
#include "../../../classes/print_class-imp/PrintClass.hpp"
#include "../../../classes/manager_class-imp/ManagerClass.hpp"
#include "../../../classes/search_class-imp/SearchingClass.hpp"
#include "../../../classes/app_variables_struct/VariablesStruct.hpp"
#include "../../../classes/input_handler_class-imp/InputHandlerClass.hpp"

class ManagerInterface {
public:
	void manager_interface() {
		do {
			PrintInfo::print_manager_menu();
			InputHandler::input_and_error_handler(app_var.choice);

			switch (app_var.choice) {
			case 1:
				system("cls");
				manager->add_item_to_stock();
				break;

			case 2:
				system("cls");
				search.search_for_existing_item(manager);
				break;

			case 3:
				system("cls");
				manager->update_existing_item();
				break;

			case 4:
				system("cls");
				manager->remove_item_from_stock();
				break;

			case 5:
				system("cls");
				PrintInfo::print_all_items(manager);
				break;

			case 6:
				return;

			default:
				PrintInfo::print_error_msg();
			}

			system("pause");
			system("cls");
		} while (app_var.choice != 6);
	}

protected:
	SearchingForInfo search;
	static std::unique_ptr<StorageManager> manager;
}; std::unique_ptr<StorageManager> ManagerInterface::manager(new StorageManager());