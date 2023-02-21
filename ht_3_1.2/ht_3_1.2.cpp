
#include <iostream>
#include <vector>
#include <variant>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
	}

int main()
{
	std::variant<int, std::string, std::vector<int>> val = get_variant();
	if (std::holds_alternative<int>(val)) { 
		auto val1 = std::get<int>(val);
		std::cout << val1 * 2;
	}
	else if (std::holds_alternative<std::string>(val)) {
		auto val1 = std::get<std::string>(val);
		std::cout << val1;
	}
	else {
		auto val1 = std::get<std::vector<int>>(val);
		std::for_each(val1.begin(), val1.end(), [](int n) {std::cout << n << " "; });
	}
	
}
