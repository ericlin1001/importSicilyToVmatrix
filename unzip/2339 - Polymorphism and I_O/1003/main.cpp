#include<iostream>
using namespace std;

int main() {
	int n, num = 0;
	char c;
	cin >> n;
	cin.get();
	while (num < n) {
		c = cin.get();
		if (c == '*') {
			++num;
			cout << endl;
		} else {
			cout << c;
		}
	}
	return 0;
}
