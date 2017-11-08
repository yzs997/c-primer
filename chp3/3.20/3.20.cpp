#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	if (vec.size() == 1)
		std::cout << vec[0] << " does not have any adjacent elements" << std::endl;
	else
		for (int i = 0; i != vec.size() -1; i++)
			cout << vec[i] + vec[i + 1] << std::endl;

	int size = vec.size();
	if (size % 2 == 0)
		size /= 2;
	else
		size = size / 2 + 1;
	for (int i = 0; i != size; ++i)
		std::cout << vec[i] + vec[vec.size() - i - 1] << std::endl;
	return 0;
}
