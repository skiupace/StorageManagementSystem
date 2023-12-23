#pragma once

class InputHandler {
public:
	template<typename T>
	static void input_and_error_handler(T& variable) noexcept {
		std::cin >> variable;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << '\a';
		}
	}
};