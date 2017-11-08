#include <iostream>

using namespace std;

int main()
{	
	
	int ia[3][4] = {};

	for (auto &row : ia)
		for (auto i : row)
			std::cout << i << " ";
	cout << endl;

	for (int i = 0; i != 3; i++)
		for (int j = 0; j != 4; j++)
			std::cout << ia[i][j] << " ";
	cout << endl;

	for (auto p = ia; p != ia + 3; p++)
		for (auto q = *p; q != *p + 4; q++)
			std::cout << *q << " ";
	cout << endl;


	using int_array1 = int[4];
	typedef int int_array2[4];

	for (int_array1 *p = ia; p != ia + 3; p++)
		for (int *q = *p; q != *p + 4; q++)
			std::cout << *q << " ";
	cout << endl;
	
}
