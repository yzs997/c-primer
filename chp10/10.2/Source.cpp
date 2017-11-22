#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	list<string> list_string;
	string string_word;
	while (cin >> string_word)
		list_string.push_back(string_word);
	int i_count = count(list_string.begin(), list_string.end(), "yinzishuo");
	cout << i_count << endl;
	getchar();
	return 0;
}