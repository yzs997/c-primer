#include <iostream>
#include <string>

int main()
{	
	std::string yzs_string1, yzs_string2;
	while (std::cin >> yzs_string2)
		yzs_string1 += yzs_string2 + " ";
	std::cout << yzs_string1 << std::endl;
}
