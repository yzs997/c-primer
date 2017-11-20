#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream ifs("data.txt");
	TextQuery tq(ifs);
	string s = "yinzishuo";
	print(cout, tq.query(s)) << endl;

	getchar();
}
