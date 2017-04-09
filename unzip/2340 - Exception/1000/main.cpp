#include <iostream>
#include <cstring>
#include <iomanip>
#include <stdexcept>
using namespace std;
int parseHex(const char * const hexString) {
	int size = strlen(hexString);
	int temp;
	int ans = 0;
	for(int i = 0; i < size; i++) {
		if((hexString[i] >= 'A' && hexString[i] <= 'F') || (hexString[i] >= '0' && hexString[i] <= '9') || (hexString[i] >= 'a' && hexString[i] <= 'f')) {
			if(hexString[i] >= 'A' && hexString[i] <= 'Z') {
				temp = hexString[i] - 'A' + 10;
			} else if(hexString[i] >= '0' && hexString[i] <= '9') {
				temp = hexString[i] - '0';
			} else {
				temp = hexString[i] - 'a' + 10;
			}
			ans = ans * 16 + temp;
		} else {
			throw runtime_error("Hex number format error");
		}

	}
	return ans;
}

