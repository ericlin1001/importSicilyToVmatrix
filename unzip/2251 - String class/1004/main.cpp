#include <iostream>
#include <string>

using namespace std;

int N, minLen = 10010, maxLen = 0;
string words[1010];
string result[1010];
int r_count = 0;

bool find(string str) {
	for (int i = 0; i < N; i++) {
		if (words[i] == str) {
			return true;
		}
	}
	return false;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
		if (words[i].length() < minLen) {
			minLen = words[i].length();
		}
		if (words[i].length() > maxLen) {
			maxLen = words[i].length();
		}
	}
	string sentence;
	cin >> sentence;
	int start = 0;

	while (start < sentence.length()) {
		int len = 1;
		for (int i = maxLen; i >= minLen; i--) {
			string sub = sentence.substr(start, i);
			if (find(sub)) {
				len = i;
				break;
			}
		}
		result[r_count] = sentence.substr(start, len);
		start += len;
		r_count += 1;
	}

	if (r_count > 0) {
		cout << result[0];
	}
	for (int i = 1; i < r_count; i++) {
		cout << ' ' << result[i];
	}
	cout << endl;
	return 0;
}

