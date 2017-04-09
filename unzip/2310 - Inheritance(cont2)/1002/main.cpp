#include <iostream>
using namespace std;
class A {
	public:
		virtual ~A() {
			cout << "A::~A()called" << endl;
		}
		virtual void Prin() {
			cout << "Prin come form class A" << endl;
		}
};

class B: public A {
		char *buf;
	public:
		B(int) {
		};
		virtual ~B() {
			cout << "B::~B()called" << endl;
		}
		virtual void Prin() {
			cout<<"Prin come from class B"<<endl;
		}
};

void fun(A *a) {
	delete a;
}
int main() {
	A *a = new B(10);
	a->Prin();
	fun(a);
	B *b =  new B(20);
	fun(b);
	return 0;
}

