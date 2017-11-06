#include <iostream>

int main()
{
	int yzs_int1 = 0, yzs_int2 = 0;
	std::cin >> yzs_int1 >> yzs_int2;
	while (yzs_int1 <= yzs_int2)
	{
		std::cout << yzs_int1 << " ";
		yzs_int1++;
	}
	std::cout << std::endl;
	return 0;

}
