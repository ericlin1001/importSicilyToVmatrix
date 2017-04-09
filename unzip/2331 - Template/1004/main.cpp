#include <iostream>
#include <cstring>
using namespace std;

template<class T>
T max(T seq[], int n);
template<class T>
T max(T seq[], int n) {
	T max_v = seq[0];
	for (int i = 1; i < n; ++i) {
		if (max_v < seq[i])
			max_v = seq[i];
	}
	return max_v;
}
