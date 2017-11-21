#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	multimap<string, string> multimap_author = { { "alan", "DMA" },
												{ "pezy", "LeetCode" },
												{ "alan", "CLRS" },
												{ "wang", "FTP" },
												{ "pezy", "CP5" },
												{ "wang", "CPP-Concurrency" }
	};
	auto it_found = multimap_author.find("pezy");
	auto int_count = multimap_author.count("pezy");
	while (int_count)
	{
		multimap_author.erase(it_found++);
		--int_count;
	}

	for (const auto &author : multimap_author)
		std::cout << author.first << " " << author.second << std::endl;
	getchar();
	return 0;
}