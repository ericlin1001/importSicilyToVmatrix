#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
	string str, str_sum;
	char a;
	int i = 0;

	while(cin >> str) {
		if('a' <= str[0] && str[0] <='z') {
			str[0] -= 32;
		}//改小写字母为大写
		if(i < 1) {
			str_sum += str;//将字符连接
			i++;
		}

		else  str_sum += ' ' + str;

		a = getchar();
		if (a=='\n') {
			break;
		}//判断输入 是否结束
	}
	cout << str_sum << endl;
	return 0;
}

