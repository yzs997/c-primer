#include "QueryResult.h"
#include <iostream>

using namespace std;

ostream &print(ostream &os, const QueryResult &qr)
{
	os << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times " : " time ") << endl;
	for (auto i : *qr.nos)
		os << "\t(line " << i + 1 << ") " << *(qr.input->begin() + i) << endl;	
	return os;
}
