#include <iostream>

using namespace std;

class numbered
{
public:
	numbered() { mysn = st_id++; }
	int mysn;
private:
	static int st_id;
};

int numbered::st_id = 0;

void f(numbered s)
{
	cout << s.mysn << endl;
}
int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
}
