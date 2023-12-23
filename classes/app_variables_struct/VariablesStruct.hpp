#ifndef Variables
#define Variables

struct Variables {
	bool product_exist = false;
	float product_price = 0.0f;

	char conform = NULL;
	std::string product_name = "";

	short product_number = 0, 
		  product_quantity = 0, 
		  choice = 0;
} app_var;

#endif // !Variables