#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
	std::string s;
	std::vector<std::string> svec;
	while (std::cin >> s)
	{
		for (auto &c : s)
			c = toupper(c);
		svec.push_back(s);
	}

	for (auto &str : svec)
		std::cout << str << std::endl;
	return 0;
}
