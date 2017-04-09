#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	int M, n;
	cin >> M;
	while(M--) {
		cin >> n;
		string a;
		a.insert(0, n, '*');
		cout << n << ":" << a << endl;
	}
}
