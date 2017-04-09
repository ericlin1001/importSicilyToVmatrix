#include <iostream>
#include <string>
#include <vector>
using namespace std;


class A
{
public:
	A(int a0):a(a0) {}
	void show() { cout<<"a="<<a<<endl; }
private:
	int a;
};

#include "source.cpp"

int main()
{
//	freopen("test01.in", "r", stdin);
//	freopen("test01.out", "w", stdout);
	B b(10,15);
	b.show();

    return 0;
}