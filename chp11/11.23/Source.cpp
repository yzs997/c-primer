#include <map>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	multimap<string, string> multimap_family;
	string family_name;
	string given_name;
	while (cin >> family_name >> given_name)
		multimap_family.insert({ family_name, given_name});
	for (auto p : multimap_family)
		cout << p.first << '\t' << '\t' << p.second;
	getchar();
	return 0;


}