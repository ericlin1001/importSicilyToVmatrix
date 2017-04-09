#include<iostream>
using namespace std;
class MyClass {
		int data;
	public:
		MyClass(int d) {
			data=d;
		}
		void printData() {
			cout << data << endl;
		}
		int sumIt() {
			return (data*(data+1))/2;
		}
};

