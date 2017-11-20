#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<string>> map_all_family;
    string str_family_name = "finch";
    map_all_family[str_family_name].push_back("harold");
    map_all_family[str_family_name].push_back("david");
    for (auto p : map_all_family)
	{
		cout << p.first << " : " << endl;
		for (auto s : p.second)
			cout << '\t' << s << "." << p.first << endl;
    cout << endl;    
    }
	getchar();
	return 0;
}
