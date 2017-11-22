#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	int i_count = count(vec.begin(), vec.end(), 315);
	cout << i_count << endl;
	getchar();
	return 0;

}