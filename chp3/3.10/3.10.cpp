#include <string>
#include <cctype>
#include <iostream>

int main()
{
	std::string yzs_string;
	if (std::cin >> yzs_string)
		for (char &c : yzs_string)
			if (!ispunct(c))
				std::cout << c;
	std::cout << std::endl;
	return 0;
}
