#include <iostream>

int main()
{
	int yzs_int1 = 0;
	int yzs_int2 = 0;
	while (std::cin >> yzs_int1)
	{
		yzs_int2 += yzs_int1;
	}
	std::cout << yzs_int2;
	return 0;
}
