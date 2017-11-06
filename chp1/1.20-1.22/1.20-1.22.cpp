#include "Sales_item.h"
#include <iostream>

int main()
{
	Sales_item item;
	while (std::cin >> item)
		std::cout << item << std::endl;

	Sales_item item1, item2;
	std::cin >> item1 >> item2;
	std::cout << item1 + item2;

	return 0;
}
