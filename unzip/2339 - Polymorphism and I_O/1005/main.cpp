#include<iostream>
#include<iomanip>
using namespace std;

void format(double k) {
	cout.unsetf(ios::fixed);
	cout << k << endl;
	cout << fixed << setprecision(6) << k << endl;
}

int main() {
	int t;
	double k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> k;
		format(k);
	}
	return 0;
}

