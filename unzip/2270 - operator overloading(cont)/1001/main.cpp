#include<iostream>
using namespace std;
class Int {
		int data;
	public:
		static int num;
		static bool isodd(int m) {
			if(m%2!=0) return true;
			else
				return false;
		};
		Int() {
			data=0;
			++num;
			cout << num <<" objects of Int has been constructed." <<endl;
		}
		Int(int m) {
			++num;
			data=m;
			cout << num <<" objects of Int has been constructed." <<endl;
		}
		~Int() {
			--num;
		};
};
int Int::num=0;

