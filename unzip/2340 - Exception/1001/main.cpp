#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<stdexcept>
using namespace std;

int parseBinary(const char * str) {
	int n = strlen(str);
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (str[n - i - 1] >= 48 && str[n - i - 1] <= 49) {
			temp += (str[n - i - 1] - 48) * pow(2, i);
		} else {
			throw runtime_error("Binary number format error");
		}
	}
	return temp;
}

