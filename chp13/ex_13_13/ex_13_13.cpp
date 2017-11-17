#include "X.h"
#include <vector>

using namespace std;

int main()
{
	X x1("harold");
	X x2;
	x2 = x1;
	vector<X> vec;
	vec.push_back(x1);

	X *p_x = new X("yinzishuo");
	delete p_x;
	
}
