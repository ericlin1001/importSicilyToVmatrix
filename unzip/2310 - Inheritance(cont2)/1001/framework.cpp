#include <iostream>
using namespace std;
#include "source.cpp"

int main()
{  
	A *a=new C;
	a->g();
	delete a;
	return 0;
}