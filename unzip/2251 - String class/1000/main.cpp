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
		}//��Сд��ĸΪ��д
		if(i < 1) {
			str_sum += str;//���ַ�����
			i++;
		}

		else  str_sum += ' ' + str;

		a = getchar();
		if (a=='\n') {
			break;
		}//�ж����� �Ƿ����
	}
	cout << str_sum << endl;
	return 0;
}

